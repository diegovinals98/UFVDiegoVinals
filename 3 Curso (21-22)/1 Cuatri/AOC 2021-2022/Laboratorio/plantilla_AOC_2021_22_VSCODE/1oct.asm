        DEVICE ZXSPECTRUM48     ; Esto es una directiva
        org $8000               ; Programa ubicado a partir de $8000 = 32768. ESTO TAMBIEN ES UNA DIRECTIVA

inicio: di      
        ld sp, 0

        ; en la pila solo podemos poner registros de 16 bits. B no, BC si
        ; Resta uno al punero de pila (sp), y pone el registro mas alto
        ; le vuelve a restar uno al puntero de pila, y pone el otro registro.
        ; la pila crece hacia abajo
        ; NO DESBALANCEAR LA PILA
        ld bc ,$FF
        push bc 
        pop hl
        
        ld b, 14
        ld hl, $5800
b1:     
        ld (hl), (color)
        inc hl
        djnz b1

        ld a, 11 ; 
        ld b, (cy)
        ld c, (cx)
bucle:
        call escribeXY
        djnz bucle
        ; llamar a funciones

        ; VARIABLES
        ; Definicion de variables

fin: jr fin

; las funciones acaban con la instruccion ret
; vuelve a lo que le ha llamado
; para llamar a una funcion call
escribeXY:
    push af
    push de 
    push hl
    ld h,0
    ld l,b
    add hl, hl 						; ahora hl es 2*c
    add hl, hl 						; ahora hl es 4*c
    add hl, hl 						; ahora hl es 8*c
    add hl, hl 						; ahora hl 16*c
    add hl, hl 

    ld d, 0
    ld e, c
    add hl, de 
    ld de , $5800
    add hl, de  
    add a
    add a 
    add a 
    ld (hl), a 

    pop hl
    pop de
    pop af

    ret    

; las variables tiene que estar en un espacio donde no llegue el contador de programa
color: defb 6
cy: defb 21
cx: db 2