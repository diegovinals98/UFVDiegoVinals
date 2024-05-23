			output "pruebalab.bin"
			org $8000

			di
			ld sp,0

			call CLEARSCR				; Borra la pantalla
			ld ix, titulo				; Apunta al texto a imprimir (debe acabar en 0x00)
			ld bc, $0102				; Coordenada Y (0..23), Coordenada X (0..31)
			ld a, $46					; Color bits (Flash, Brillo, 3*Paper, 3*Ink)
			call PRINTAT				; Imprime el texto en pantalla

			ld ix, original				; Escribe "Texto original:"
			ld bc, $0600
			ld a, $42
			call PRINTAT
			ld ix, texto 				; Escribe el texto original
			ld bc, $0800
			ld a, $47
			call PRINTAT
			ld ix, modificado			; Escribe "Texto modificado:"
			ld bc, $0D00
			ld a, $44
			call PRINTAT

			ld ix, minombre				; Escribe el nombre del estudiante
			ld bc, $1700
			ld a, $43
			call PRINTAT



;-------------------------------------------------------------------------------------------------
; Código del estudiante

; Parte 0: Escribe tu nombre en la etiqueta "minombre"

; Parte 1: Crea otra variable (texto2) en el código, reservando 32 bytes para ella.
; copia mediante código el contenido de "texto" a texto2
texto2: db 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0   ; Resevamos 32 bytes para la variable texto2


parte1: ld ix, texto			; Metemos texto en ix
		ld a, (ix)				; metemos ix en a 
		ld (texto2), a  		; metemos en texto2, a
		inc a       			; Incrementamos a para acceder a la siguiente letra
		cp 0 					; si es 0, repetimos parte1
		jr z, parte1 			; No me funciona, esto es lo que tengo hecho.


; Parte 2: Copia texto2 sobre texto, pero eliminando los espacios. No olvides poner el '0' final.
parte2: ld ix, texto2	    	; texto2 en ix
		ld a, (ix) 				; ix en a
		cp $0020				; comparamos con el codigo ASCII del espacio que es 0x20
		jr nz, meterLetra  		; si no es el espacio llamamos a meterLetra, que mete la letra en texto
		inc a   				; Incrementamos a
		cp 0 					; Comparamos con 0
		jr nz, parte2			; Si no es 0, volvemos al princpio del bucle
		

								
meterLetra: ld (texto), a
			ret
			

fincodigoalumno:
			jr imprimemodificado

minombre:  defm	"Diego Vinals", 0		; Nombre y apellido (Sólo ASCII)
;-------------------------------------------------------------------------------------------------

imprimemodificado:			
			ld ix, texto				; Escribe el texto modificado
			ld bc, $0F00
			ld a, $47
			call PRINTAT

fin: 		jr fin

texto:		defm "En un lugar de La Mancha", 0


original:	defm "Texto original:" , 0
modificado: defm "Texto modificado sin espacios:", 0
titulo:		defm "Prueba de laboratorio de AOC  ________________________________", 0

			include "print_text.asm"