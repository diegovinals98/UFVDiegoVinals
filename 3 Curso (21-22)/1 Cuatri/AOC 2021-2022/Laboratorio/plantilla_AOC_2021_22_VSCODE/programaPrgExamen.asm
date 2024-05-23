
        DEVICE ZXSPECTRUM48     ; Esto es una directiva
        SLDOPT COMMENT WPMEM, LOGPOINT, ASSERTION
        org $8000        
        di
        ld sp,0

        call transferErase
        call $C000

fin: jr fin

; RUTINA 1
sumaV:
        ld hl, numeros
        xor a 
bucle: 
        add a, (hl)
        inc hl 
        bit 5, a 
        jp nz, salir
        jp bucle 
salir:  ret
finBucle:

; RUTINA 2

transferErase:
        ld hl, sumaV
        ld de, $C000
        ld bc, finBucle-sumaV
        ldir
        ld ix, bucle 
        xor a 
        ld (ix + 0), a 
        ld (ix + 1), a 
        ld (ix + 2), a 
        ld (ix + 3), a 
        ld (ix + 4), a 
        ld (ix + 5), a 
        ld (ix + 6), a 
        ret 

; DATOS

numeros:
        db 7,3,12,9,2,1,14,4,5