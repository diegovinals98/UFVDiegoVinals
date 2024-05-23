
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

        ld ix , level2          ; el mapa a pintar en ix
        call pintarMapa         ; Llamamos a pintarMapa y pinta el mapa que hemos puesto en ix

fin:    jr fin


funciones:      
        include funciones.asm
niveles: 
        include niveles_basicos.asm


