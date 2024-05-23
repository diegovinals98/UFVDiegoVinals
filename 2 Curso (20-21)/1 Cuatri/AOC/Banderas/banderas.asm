;------------------------------------------------------------------------------------------------
; Programa que pinta banderas de lineas horizontales o verticales en la pantalla usando atributos
; Las banderas se definen en una tabla
; Oct 2020 - Daniel León - AOC - UFV
;------------------------------------------------------------------------------------------------

		output "banderas.bin"			; fichero binario de salida
		org $8000						; inicio de la dirección del código para el cálculo de etiquetas (Directiva)

		di 								; Deshabilitar interrupciones
		ld sp,0 						; Posicionar la pila al final de la memoria
		ld ix, banderas 				; Cargar la posición de memoria de las banderas en IX



;--------------------------------------------------------------------------------------------
; Bucle Principal - recorre una a una todas las banderas definidas y llama a vertical u horizontal
;--------------------------------------------------------------------------------------------
bucP:   ld a,(ix)						; Carga el tipo de la bandera apuntado por IX	
		inc ix 							; Mueve al primer color de la bandera
chkH:	cp 0 							; Mira si el tipo es 0 (Bandera de barras horizontales) (Más eficiente con OR A)
		jr nz, chkV						; Si no lo es, salta a la siguiente comprobación
		call banderaH 					; Llama a pintar bandera Horizontal
		jr finBP 						; A la vuelta, salta al final del Bucle principal
chkV:	cp 1 							; Mira si el tipo es 1 (Bandera de barras verticales) (Más eficiente con DEC A)	
		jr nz, chkFin 					; Si no lo es, salta a la siguiente comprobación
		call banderaV 					; Llama a pintar la bandera Vertical
		jr finBP						; A la vuelta, salta al final del Bucle principal
chkFin:	cp 255							; Mira si el tipo es 255 (Final de lista) (Más eficiente con INC A)
		jr z, fin 						; Si tenemos la marca de fin de lista, saltamos al final
	
finBP:	ld b, 5 						; Carga 5 iteraciones de pausa
		call pausa 						; Llama a pausa

		jr bucP 						; Cicla al bucle principal


fin: jr fin								; Final del programa : DeadLock	
	


;--------------------------------------------------------------------------------------------
; Funcion Pausa - Recibe en b la longitud de la pausa
;--------------------------------------------------------------------------------------------
pausa: 	push af							; Salva registros utilizados en la pila
		push de

paus0:  ld de, 0 						; Inicializa DE a 0 para ciclar 2e16 (65536) en el bucle interno
paus1:	dec de 							; Decrementa DE. En la primera vuelta, DE valdrá 65535
		ld a,d 							; Para comprobar si DE es 0000, D tiene que ser 0...
		or e 							; ... y E también
		jr nz, paus1					; Si no lo es, sigue el bucle inteno
		djnz paus0                      ; B=B-1 y cicla a bucle externo hasta que B sea 0

		pop de 							; Recupera registros utilizados desde la pila
		pop af

		ret 							; Retorna al punto de llamada



;--------------------------------------------------------------------------------------------
; Funcion BanderaV -  Pinta la bandera vertical apuntada por IX
;--------------------------------------------------------------------------------------------
banderaV: 
		push af							; Guarda los registros usados en la pila
		push bc

		ld b,0 							; B lleva la cuenta de la coordenada X
buclebV:		
		ld a,(ix)                       ; Carga el color de la columna en curso
		inc ix                          ; Apunta IX al siguiente color
		call barraVert                  ; Pinta una barra vertical en X=B y Color=A
		inc b 							; Mueve a la siguiente columna
		ld a,b 							; Compara si ha llegado a la columna 32 (una más de la última)
		cp 32
		jr nz, buclebV 					; Si no, sigue el bucle

		pop bc 							; Recupera los registros originales desde la pila
		pop af

		ret 							; Retorna a la dirección de llamada



;--------------------------------------------------------------------------------------------
; Funcion BanderaH -  Pinta la bandera horizontal apuntada por IX
;--------------------------------------------------------------------------------------------
banderaH:  
		push af							; Guarda los registros usados en la pila
		push bc

		ld c,0 							; C lleva la cuenta de la coordenada Y
buclebH:		
		ld a,(ix) 						; Carga en a el color de la fila en curso
		inc ix 							; Apunta IX al siguiente color
		call barraHor 					; Pinta una barra horizonal en Y=C y Color=A
		inc c 							; Mueve a la siguiente fila
		ld a,c 							; Comprueba si ha llegado a la columna 24 (una más de la última)
		cp 24
		jr nz, buclebH 					; Si no, sigue el bucle

		pop bc 							; Recupera los registros originales desde la pila
		pop af

		ret 							; Retorna a la dirección de llamada



;--------------------------------------------------------------------------------------------
; Funcion barraVert -  	Pinta una barra vertical de color A en X=B
;						Recibe en B la coordenada de la barra vertical 0..31 y en A el color
;--------------------------------------------------------------------------------------------
barraVert:  
		push af							; Salvamos registros usados
		push bc

		ld c,23							; C contará la coordenada Y

bucVert: 
		call cuadroXYC 					; bucle de 31..0 en la coordenada Y
		dec c
		jp p, bucVert 					; jp P salta si el SIGNO en Complemento a 2 es positivo
										; La primera vez que no salta es cuando es -1

		pop bc 							; Recuperamos el valor original de los registros
		pop af

		ret 							; Retorno de la función



;--------------------------------------------------------------------------------------------
; Funcion barraHor -  	Pinta una barra horizontal de color A en Y=C
;						Recibe en C la coordenada de la barra horizontal 0..23 y en A el color
;						Esta función implementa el bucle de forma distinta a barraVer voluntariamente
;--------------------------------------------------------------------------------------------
barraHor:
		push bc							; Salvamos registros usados
		push af

		ld b,0							; B contará la coordenada X

bucHor: pop af							; Recupera el valor de a, importante para el color
		push af
		call cuadroXYC 					; bucle de 31..0 en la coordenada Y
		inc b
		ld a,b
		cp 32
		jr nz, bucHor					; jr nz salta siempre que b sea distinto de 32

		pop af 							; Recuperamos el valor original de los registros
		pop bc

		ret 							; Retorno de la función



;--------------------------------------------------------------------------------------------
; Funcion cuadroXYC -  	Pinta un cuadro de color A en las coordenadas X,Y (0..31, 0..23)
;						Recibe coordenada X,Y y color en B,C y A respectivamente
;
; Esta función determina la dirección con la fórmula Dirección = $5800+32*Y+X
;--------------------------------------------------------------------------------------------
cuadroXYC:  				
		push af							; Salva registros usados
		push de
		push hl

		ld h,0 							; Empieza calculando Y*32
		ld l,c  						; Para multiplicar c (coord. Y) por 32, se usan sumas. Esto se puede hacer en un bucle también
		add hl, hl 						; ahora hl es 2*c
		add hl, hl 						; ahora hl es 4*c
		add hl, hl 						; ahora hl es 8*c
		add hl, hl 						; ahora hl 16*c
		add hl, hl 						; ahora hl 32*c 
		
		ld d,0
		ld e,b    						; b Contiene el valor de la coordenada X -> Se carga en DE

		add hl, de 						; Ahora HL Contiene 32*y+X
		ld de, $5800 					; Se carga en DE la dirección base de la zona de atributos (colores)
		add hl, de 						; Ahora HL contiene $5800 + 32*Y + X, el valor buscado, 

		sla a 							; Ajuste de color para paper desplazando los bits a la zona de paper y bright
		sla a 							; mediante tres desplazamientos a la izquierda
		sla a 							; Esta secuencia es lo mismo que multiplicar por 8

		ld (hl),a 						; Transfiere a memoria de video apuntada por HL el valor del color sobre el PAPER y el bit de brillo

		pop hl 							; Recupera registros desde la pila
		pop de
		pop af

		ret 							; Retorno de la función



;--------------------------------------------------------------------------------------------
; Tabla de banderas -  	primer byte determina tipo de bandera -> 	0:horizontal, 1:vertical
;																	255: fin de lista
;						Cada byte restante es el color de la fila o columna correspondiente
;						Los colores son del 0 al 15 (con brillo)
;--------------------------------------------------------------------------------------------
banderas: db 0,10,10,10,10,10,10,14,14,14,14,14,14,14,14,14,14,14,14,10,10,10,10,10,10 ; España
		  db 1,1,1,1,1,1,1,1,1,1,1,15,15,15,15,15,15,15,15,15,15,15,15,2,2,2,2,2,2,2,2,2,2 ; Francia
		  db 1,4,4,4,4,4,4,4,4,4,4,4,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 ; Portugal
		  db 0,13,13,13,13,13,13,13,15,15,15,15,15,15,15,15,15,15,13,13,13,13,13,13,13 ; Argentina
		  db 1,0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7; Barras de colores
		  db 255 ; fin

	
