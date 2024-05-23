// Depende de la tecla que pulse el borde cambia de colores

		output "teclado.bin" 

		org	$8000
		di

		
		ld a,0;
		

b1: 	
		ld bc, $FBFE
		in a, (c)
		bit 1,a 				;COMPRUEBA SI SE PULSA LA 'W'
		jr z, pulsadoW
		ld bc, $FDFE
		in a, (c)
		bit 0,a 				;COMPRUEBA SI SE HA PULSADO LA 'A'
		jr z, pulsadoA
		bit 1,a 				;COMPRUEBA SI SE HA PULSADO LA 'S'
		jr z, pulsadoS
		bit 2,a 				;COMPRUEBA SI SE HA PULSADO LA 'S'
		jr z, pulsadoD
		ld a, 0 
		ld bc, $7FFE
		in a , (c)
		bit 0 , a
		jr z, pulsadoSpace		;COMPRUEBA SI SE HA PULSADO EL 'Space'
		jr b1

pulsadoW:;ld a,2
		;out ($FE), a
		ld hl, $5800
		ld bc, $300
		ld a, c 						; cargo c, que me dará el color en los bits 2 y 3
		dec a 							; pero ojo que tengo que restarle 1 para que sea 0..767
		rlca							; los muevo al sitio adecuado para paper
		;cpl                            ; Esta linea invierte los colores: 000->111; 001->110; 010->101; 011-> 100 ...
		and 0x20     	;El COLOR		; borro el resto de bits para dejar solo el paper
		ld (hl),a 						; Transfiero a memoria de video
		inc hl							; hl a siguiente posición de atributos
		dec bc 							; uno menos en el contador
		ld a,b
		or c 
		jr b1

pulsadoA:ld a,4
		out ($FE), a
		jr b1
pulsadoS:ld a,3
		out ($FE), a
		jr b1
pulsadoD:ld a,5
		out ($FE), a
		jr b1

pulsadoSpace:ld a,0
		out ($FE), a
		jr b1




