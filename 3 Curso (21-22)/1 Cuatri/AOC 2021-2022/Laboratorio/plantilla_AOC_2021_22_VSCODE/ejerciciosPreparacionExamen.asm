        DEVICE ZXSPECTRUM48     ; Esto es una directiva
        org $8000               ; Programa ubicado a partir de $8000 = 32768. ESTO TAMBIEN ES UNA DIRECTIVA

inicio:        
        di      
        ld sp, 0
        jr ejercicio1

ejercicio1:
        ld b, 3
        ld a, 1







fin: jr fin