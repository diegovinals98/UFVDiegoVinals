        DEVICE ZXSPECTRUM48     ; Esto es una directiva
        org $8000               ; Programa ubicado a partir de $8000 = 32768. ESTO TAMBIEN ES UNA DIRECTIVA

inicio:   
    di      
    ld sp, 0
    include "trozo.asm" ; para llamar a otro archivo, lo normal es que haya una funcion o datos, no lineas al azar 



fin: 
    jr fin


incbin ; incluye un binario
batman: incbin "BATMAN.SCR"