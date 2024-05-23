        DEVICE ZXSPECTRUM48     ; Esto es una directiva
        org $8000               ; Programa ubicado a partir de $8000 = 32768. ESTO TAMBIEN ES UNA DIRECTIVA
inicio: di      
        ld sp, 0
        jr pintar
        
        ld b, tamT
        ld ix, array ; array2 esta en ix + 10 y resulyado en ix + 20

bucle:  
        ld c, (ix)
        ld a, (ix + tamT)
        add c 
        ld (ix + tamT + tamT), a
        inc ix
        djnz bucle


finsumar:
        ld a , b ; resultado en a y en b

pintar: 
        ld ix, argentina
        ld hl, $5800
        
franja: 
        ld a, (ix)
        cp 0
        jr z,fin
        ld b , a ; numero de repeticiones a b
        ld a, (ix + 1) ; en a cargo el color
cuadro: 
        ld (hl), a
        inc hl
        djnz cuadro
        inc ix
        inc ix
        call pausa
        jr franja
fin: jr fin

pausa:
        push af
        push bc 

        ld bc, $5FFF
btonto:
        dec bc
        ld a , b
        or c 
        jr nz, btonto
        pop bc 
        pop af 
        ret

; tabla de datos
argentina: 
        defb 128,5*8
        defb 32,7*8
        defb 15,7*8
        defb 2, 6*8
        defb 15, 7*8
        defb 15,7*8
        defb 2, 6*8
        defb 15, 7*8
        defb 32,7*8
        defb 128,5*8,0   ; bandera de argentina



array: defb 1,2,3,4,5,6,7,8,9,10
array2: defb 10,9,8,7,6,5,4,3,2,1
resultado: defb 0,0,0,0,0,0,0,0,0,0

tamT: EQU 10
