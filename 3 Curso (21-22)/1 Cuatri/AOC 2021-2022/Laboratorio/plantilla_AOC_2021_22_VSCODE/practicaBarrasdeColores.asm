        DEVICE ZXSPECTRUM48     ; Esto es una directiva
        org $8000               ; Programa ubicado a partir de $8000 = 32768. ESTO TAMBIEN ES UNA DIRECTIVA

inicio: di      
        ld sp, 0

;---------- Barras ----------------

        ld ixl, 8

        ld a, 0
bucle: 
        call barras
        inc a
        inc a
        inc a
        inc a
        inc a
        inc a
        inc a
        inc a
        dec ixl
        jr nz, bucle

; ------ loop infinito ----------
fin:    jr fin   


; ------ funcion que pinta barras de colores -----------
barras: 
        ld ixh, 4
azul:   
        ld c, 0
        call cuadro
        ld c, 23 ; corrdenadsa y
        call vertical
        inc b
        dec ixh
        jr nz, azul
        ret

; ------- Funcion que pinta barras verticales de 1 solo cuadrado ------
vertical:  
        call cuadro
        dec c
        jr nz, vertical
        ret

; -------- Pinta un solo cuadro ---------
cuadro: ld h,0 							; Empieza calculando Y*32
        ld l,c 						; Para multiplicar c (coord. Y) por 32, se usan sumas. Esto se puede hacer en un bucle también
        add hl, hl 						; ahora hl es 2*c
        add hl, hl 						; ahora hl es 4*c
        add hl, hl 						; ahora hl es 8*c
        add hl, hl 						; ahora hl 16*c
        add hl, hl 						; ahora hl 32*c 
        
        ld d,0
        ld e,b    						; b Contiene el valor de la coordenada X -> Se carga en DE

        add hl, de 						; Ahora HL Contiene 32*y+X
        ld de, $5800 					
        add hl, de 						 

        ld (hl),a 	
        ret