        DEVICE ZXSPECTRUM48     ; Esto es una directiva
        org $8000               ; Programa ubicado a partir de $8000 = 32768. ESTO TAMBIEN ES UNA DIRECTIVA

inicio:         di      
                ld sp, 0
                jr bucle200Func
                ld b, 2 ; La coordenada y
                ld c, 3 ; La coordenada x
                ld a , $F4 ; Color

                ld h, 0
                ld l, b 

                add hl, hl      ;Multiplicacion sin bucle
                add hl, hl 
                add hl, hl
                add hl, hl
                add hl, hl

                ld d, 0
                ld e, c
                add hl, de 
                ld de , $5800
                add hl, de      ; en HL tenemos la direccion de memoria a la que corresponda las coordenadas x e y
                ; FBABCHJG F: Flash B:Brillo : ABC color HJG: Nada (BYTES PARA PINTAR)
                ; Verde brillante 0110 0000 $60
                ;ld (hl),a ; Pintamos el color en la direccion de memoria que contenga HL

; --------------IF --------------
                ; Registro f es el registro bandera (Flag), no lo podemos modificar nosotros
                ; z -> la ultima operacion aritmetica o logica ha salido 0
                ; Se usa para comparar. Se hacen con restas. Con la a
                ld b,14 
                ld c, 12
                ld a , 11 ; Si c es mayor, hay carry
                cp c  ; En este caso no se levanta ni el carry ni el z (cero) jrz, jrnz, jpz, jprz. CP hace lo mismo que la resta. pero no guarda el resultado en a
                jr z, else 

; -------------- switch --------------
                ld a, 7
                cp 1
                jr nz, comparar3
                ;codigo 
                ; codigo
                jr fin_switch

comparar3:      cp 3
                jr nz, comparar5
                ;codigo 
                ;codigo
                jr fin_switch

comparar5:      cp 5
                jr nz, default
                ;codigo
                ;codigo
                jr fin_switch

default: 

                ;codigo
                ;codigo

fin_switch:     



else:




for:    ld hl, $5800
        ld a, 0

bucle:  ld (hl), $F4
        inc hl
        dec a
        jr nz, bucle ; bucle con el registro a


; ------------BUCLE 16 BITS ----------------
for2:   ld hl, $5800
        ld bc, 768

bucle2: ld (hl), $F4
        inc hl
        dec bc

        ld a,b 
        or c ; Es una operacion logica, por lo que altera los flags
        jr nz, bucle2

; ---------- BUCLE SIN CONTAR (while) -------------
while: ld hl, $5800

bucle3:  
        ld (hl), $F4
        inc hl
        ld a , h
        cp $5b
        jr nz, bucle3



; Bucle 2000
bucle200Func
        ld bc, 2000
bucle2000:
        dec bc 
        ld a, B
        or c 
        jr nz, bucle2000


;-------------------------------------------------------------------------------------------------
fin:    jr fin          ; Bucle infinito


