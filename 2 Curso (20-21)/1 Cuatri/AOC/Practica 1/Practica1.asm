; Practica 1
; Diego Vinals Lage

		org $8000
		output "practica1.bin"

		di 								; Deshabilitar interrupciones
		ld sp,0 						; Posicionar la pila al final de la memoria
		ld ix, pr1 

bucP:   call LineasV 					; Llama a LineasV, que hace las lineas				
		jr finBP						; Salta a finBP
	
finBP:	ld b, 64						; Carga 64 iteraciones de pausa
		call pausa 						; Llama a pausa

		jr bucP 						; Salta al bucle principal

pausa: 	push af							; Salva registros utilizados en la pila
		push de

paus0:  ld de, 0 						; 0 lo mete en de
paus1:	dec de 							; Decremento en 1 de "de"
		ld a,d 							; Para comprobar si DE es 0000, D tiene que ser 0...
		or e 							; ... y E también
		jr nz, paus1					; Si no lo es, sigue el bucle inteno
		djnz paus0                      ; B=B-1 y cicla a bucle externo hasta que B sea 0

		pop de 							; Recupera registros utilizados desde la pila
		pop af

		ret 							; Retorna al punto de llamada

// ---------------- FUNCION QUE PINTA LAS LINEAS VERTICALES -------------------------------//
LineasV: 
		push af							; Guarda los registros usados en la pila
		push bc

		ld b,0 							; B lleva la cuenta de la coordenada X
buclebV:		
		ld a,(ix)                       ; Carga el color de la columna en curso
		inc ix                          ; Incremento de XI, es decir, siguiente color
		call barraVert                  ; Pinta una barra vertical en X=B y Color=A
		inc b 							; Incremento de B, siguiente columna
		ld a,b 							; Compara si B es 32, si lo es, acaba el bucle, por que 
		cp 32							; hemos llegado al final
		jr nz, buclebV 					; Si no, sigue el bucle

		pop bc 							; Recupera los registros originales desde la pila
		pop af
		ret


// ---------------- FUNCION QUE PINTA UNA SOLA BARRA VERTICAL ---------------------------//
barraVert:  
		push af							; Salvamos registros usados
		push bc

		ld c,23							; C es la coordenada Y

bucVert: 
		call cuadro 					; bucle de 31..0 en la coordenada Y
		dec c
		jp p, bucVert 					; jp P salta si el SIGNO en Complemento a 2 es positivo

		pop bc 							; Recuperamos el valor original de los registros
		pop af

		ret 	


// ---------------- FUNCION QUE PINTA UN SOLO CUADRO DE COLOR ---------------------------//
cuadro:  				
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


pr1 :	db 0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7;

