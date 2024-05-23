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