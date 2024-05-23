
        DEVICE ZXSPECTRUM48     ; Esto es una directiva
        SLDOPT COMMENT WPMEM, LOGPOINT, ASSERTION
        org $8000               ; Programa ubicado a partir de $8000 = 32768. ESTO TAMBIEN ES UNA DIRECTIVA

inicio:   
        di      
        ld sp, 0


        ; $40 es destino        BLANCO
        ; $10 es jugador        CYAN
        ; $08 no valido         NEGRO (todo el fondo)
        ; $20 es una caja       AMARILLO
        ; $80 es muro           ROJO


while:  ld a, 0
        ld c, 0

        ld b , (level1 + 5

bucle3:  
; -------------- switch --------------
        ld a, b
        ; si es 08 no hacemos nada
        cp $08
        jr nz, comparar3
        ;codigo 
        ; codigo
        jr fin_switch

comparar3:    
        ; si es $40
        cp $40
        jr nz, comparar5
        ld (hl), 8*8
        ;codigo 
        ;codigo
        jr fin_switch

comparar5:      
        ; si es $10
        cp $10
        jr nz, comparar6
        ld (hl), 5*8
        ;codigo
        ;codigo
        jr fin_switch

comparar6:
        ; si es $20
        cp $20
        jr nz, comparar7
        ld (hl), 6*8
        ; codigo
        jr fin_switch
comparar7: 
        ; si es $80
        cp $80
        jr nz, fin_switch
        ld (hl), 2*8
        ; codigo
        jr fin_switch

        
fin_switch: 
        inc hl
        inc b
        ld a , h
        cp $5b
        jr nz, bucle3



; -------- FUNCION QUE PINTA UN CUADRO EN LAS COORDENADAS B Y C, Y DE COLOR A---------
pintar: 
        
        push de 
        push hl 

        ld h, 0
        ld l, c 

        add hl, hl
        add hl, hl
        add hl, hl
        add hl, hl
        add hl, hl

        ld d, 0
        ld e ,b 
        add hl, de 
        ld de, $5800
        add hl, de 

        add a 
        add a 
        add a 

        ld (hl), a
        pop hl 
        pop de 
        ret

niveles: include niveles_basicos.asm
