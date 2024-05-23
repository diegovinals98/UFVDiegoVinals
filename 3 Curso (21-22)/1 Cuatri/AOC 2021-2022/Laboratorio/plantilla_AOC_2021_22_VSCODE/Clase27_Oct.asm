
        DEVICE ZXSPECTRUM48     ; Esto es una directiva
        SLDOPT COMMENT WPMEM, LOGPOINT, ASSERTION
        org $8000               ; Programa ubicado a partir de $8000 = 32768. ESTO TAMBIEN ES UNA DIRECTIVA

inicio:   
        di      
        ld sp, 0
        ld iy, coorX
        ld ix, dx
bucle:
        
        ;ld a ,0                con esto solo se mueve un solo cuadrado, pero el cuadrado es intermitente, por lo que
        ;call pintar            no nos sirve

        ; falta comprobar que hay cambio, pq si no hay cambio, no hacemos nada. 
        ; tb falta borrar el restro del movimiento, solo se tiene q mover el cuadrado

        call leerTecla 

        ; if que comprueba si ha habido cambio en dy o dx
        ld a , 0
        ld c , (ix)
        cp c
        jr nz, mover
        ld a , 0
        ld c , (ix + 1)
        cp c
        jr nz, mover
        jr z, bucle

mover:
        ; pintamos de negro
        ld b, (iy)
        ld c, (iy + 1)
        ld a ,0
        call pintar

        ; actualizamos las coordenadas
        ld a, (ix)
        add a, (iy)
        ld (iy), a      ; actualizamos la coordenada x
        ld b, a ; guardamos en b la posicion nueva de x

        ld a, (ix + 1)  ; por aqui cambia el registro b de 1 a 0 por lo que hace que solo se pude avanzar 1 cuadrado
        add a, (iy + 1)
        ld c, a         ; guardamos en c el valor de la posicion nueva en y
        ld (iy + 1), a  ; actualizamos la coordenada y

        ; pintamos de rojo
        ld a , 2
        call pintar     ; llamamos a pintar con las nuevas coordenadas
        jr bucle

        

; ---------- FUNCION QUE LEE LAS TECLAS AWSD --------------------
leerTecla:
        push af 
        push bc 

        ld ix, dx
        ld (ix), 0
        ld (ix +1), 0
pulsadoW:
        ld bc, $FBFE
        in a, (c)
        bit 1, a  ; comprobar la w
        jr nz, pulsadoA ; si no se ha pulsado, saltamos a ver si se ha pulsado la tecla A
        dec (ix + 1)
        call esperarTecla

pulsadoA:
        ld bc, $FDFE
        in a, (c)
        bit 0, a ; comprobamos la a
        jr nz, pulsadoS
        dec (ix)
        call esperarTecla

pulsadoS:
        in a, (c)
        bit 1, a  ; comprobar la s
        jr nz, pulsadoD
        inc (ix + 1)
        call esperarTecla

pulsadoD:
        in a, (c)
        bit 2, a  ; comprobar la d
        jr nz, noPulsado
        inc (ix)
        call esperarTecla

noPulsado: 
        pop bc 
        pop af
        ret


; -------- Pinta un solo cuadro ---------
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


; FUNCION QUE ESPERA A QUE NINGUNA TECLA ESTE PULSADA
esperarTecla:
        push af 
        push bc 

iniciarScan: 
        ld bc, $FEFE
sigueScan:
        in a, (c)
        and 31
        cp 31
        jr nz, iniciarScan
        rlc b 
        jr c, sigueScan

        pop bc
        pop af 
        ret


coorX: db 0
coorY: db 0

dx: db 0
dy: db 0

