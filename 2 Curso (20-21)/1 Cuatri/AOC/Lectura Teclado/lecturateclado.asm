		output "teclado.bin" 

		org	$8000
		di

		ld bc, $BFFE
		ld a,0

b1: 	out ($FE) , a
		in a, (c)
		bit 1,a
		jr z, pulsado
		ld a, 0 
		jr b1

pulsado:ld a,2
		jr b1
