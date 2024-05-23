
        DEVICE ZXSPECTRUM48     ; Esto es una directiva
        SLDOPT COMMENT WPMEM, LOGPOINT, ASSERTION
        org $8000               ; Programa ubicado a partir de $8000 = 32768. ESTO TAMBIEN ES UNA DIRECTIVA

inicio:   
        di      
        ld sp, 0
        
        ld iy, coorX            ; Guardamos en iy la coordenada x. iy + 1 sera la coordenada y
        ld ix, dx               ; Guardamos en ix, dx. En ix + 1 guardamos dy

; -------- BUCLE PRINCIPAL DEL PROGRMA -----------------

bucle:

        call leerTecla          ; llamamos a la funcion leerTecla que comprueba si se ha tecleado una letra

        ; If para comprobar si ha habido cambio en dx o dy
        ld a , 0
        ld c , (ix)
        cp c
        jr nz, mover            ; Si ha habido cambio de dx, vamos a la funcion mover
        ld a , 0
        ld c , (ix + 1)
        cp c
        jr nz, mover
        jr z, bucle            ; Si no ha habido cambio, no pintamos y volvemos al principio del bucle

; --------------- BUCLE QUE ACTUALIZA LAS COORDENADAS Y MUEVE EL CUADRADO --------------------

mover:
        ; Pintamos de negro el cuadrado en el q estamos, a donde vayamos, lo pintaremos de rojo. 
        ld b, (iy)
        ld c, (iy + 1)
        ld a ,0
        call pintar

        ; Actualizamos las coordenadas
        ld a, (ix)
        add a, (iy)
        ld (iy), a              ; actualizamos la coordenada x
        ld b, a                 ; guardamos en b la posicion nueva de x
        ld a, (ix + 1)          ; por aqui cambia el registro b de 1 a 0 por lo que hace que solo se pude avanzar 1 cuadrado
        add a, (iy + 1)

        ld c, a                 ; guardamos en c el valor de la posicion nueva en y
        ld (iy + 1), a          ; actualizamos la coordenada y
        ld a , 2                ; Pintamos de rojo
        call pintar             ; llamamos a pintar con las nuevas coordenadas
        jr bucle

        

; ---------- FUNCION QUE LEE LAS TECLAS AWSD --------------------
leerTecla:
        push af 
        push bc 

        ld ix, dx               ; Guardamos en ix la diferencia dx
        ld (ix), 0              ; dx lo inicializamos a 0
        ld (ix +1), 0           ; dy lo inicializamos a 0
pulsadoW:
        ld bc, $FBFE
        in a, (c)
        bit 1, a                ; comprobar la w
        jr nz, pulsadoA         ; si no se ha pulsado, saltamos a ver si se ha pulsado la tecla A
        dec (ix + 1)            ; Si se ha pulsado, sumamos 1 al incremento dy
        call esperarTecla       ; Esperamos hasta que se deje de pulsar la tecla

pulsadoA:
        ld bc, $FDFE
        in a, (c)
        bit 0, a                ;comprobamos la a
        jr nz, pulsadoS         ; Si no se ha pulsado saltamos a la siguiente tecla a comprobar
        dec (ix)                ; Si se ha pulsado, restamos 1 a dx
        call esperarTecla       ; Esperemos hasta que se deje de pulsar la tecla

pulsadoS:
        in a, (c)
        bit 1, a                ; Comprobamos si se ha pulsado la tecla s
        jr nz, pulsadoD         ; Si no se ha pulsado, saltamos a la siguiente tecla a comprobar
        inc (ix + 1)            ; Si se ha pulsado, sumamos 1 a dy
        call esperarTecla       ; Eseperamos a que se deje de pulsar la tecla

pulsadoD:
        in a, (c)
        bit 2, a                ; Comprobamos si se ha pulsado la tecla d
        jr nz, noPulsado        ; Si no se ha pulsado, saltamos a noPulsado, que sale de la funcion
        inc (ix)                ; Si se ha pulsado, sumamos 1 a dx
        call esperarTecla       ; Esperamos a que se deje de pulsar la tecla

noPulsado: 
        pop bc                  ; Expulsamos de la pila los registros salvados al principio de la funcion
        pop af
        ret     


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


;------------- FUNCION QUE ESPERA A QUE NINGUNA TECLA ESTE PULSADA ----------------
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

; ------------ ETIQUETAS --------------

coorX: db 0
coorY: db 0

dx: db 0
dy: db 0

