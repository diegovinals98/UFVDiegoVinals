        DEVICE ZXSPECTRUM48     ; Esto es una directiva
        org $8000               ; Programa ubicado a partir de $8000 = 32768. ESTO TAMBIEN ES UNA DIRECTIVA

inicio:   
    di      
    ld sp, 0
    ; lectura de teclado
    ; se lee en el registro A
    ; bit n , a ; comprueba el bit n de a si es 0 o no, y modifica el flag z
    ; in a, (c) , instruccion para leer teclado, hay que hacer ld bc, puerto, y luego la instruccion in a , (c)


    ; leer la tecla A y D
    
    ld hl, $5810

buclePrincipal:
    ld bc, $FDFE
    in a, (c)
    bit 0, a ; comprobamos la a
    jr z, pintarA ; si se ha pulsado, z se modifica, y saltamos a pintar
    in a, (c)
    bit 2, a  ; comprobar la d
    jr z, pintarD
    in a, (c)
    bit 1, a  ; comprobar la s
    jr z, pintarS ; 
    ld bc, $FBFE
    in a, (c)
    bit 1, a  ; comprobar la w
    jr z, pintarW ; 
    jr buclePrincipal ; si no se ha pintado no salta a pintar y continuamos en el bucle

pintarA:
    ld a , 4*8
    ld (hl), 0
    dec hl
    ld (hl), a

bucleEsperarA:
    in a, (c)
    bit 0, a        ; este bucle, espera a que se haya soltado la tecla
    jr z, bucleEsperarA
    jr buclePrincipal


pintarD: 
    ld a , 4*8
    ld (hl), 0
    inc hl
    ld (hl), a

bucleEsperarD:
    in a, (c)
    bit 2, a        ; este bucle, espera a que se haya soltado la tecla
    jr z, bucleEsperarD
    jr buclePrincipal   

pintarS: 
    ld a , 4*8
    ld (hl), 0
    ld de, 32
    add hl, de
    ld (hl), a

bucleEsperarS:
    in a, (c)
    bit 1, a        ; este bucle, espera a que se haya soltado la tecla
    jr z, bucleEsperarS
    jr buclePrincipal   

pintarW: 
    ld a , 4*8
    ld (hl), 0
    ld de, 32
    sbc hl, de
    ld (hl), a

bucleEsperarW:
    in a, (c)
    bit 1, a        ; este bucle, espera a que se haya soltado la tecla
    jr z, bucleEsperarW
    jr buclePrincipal   


fin: jr fin