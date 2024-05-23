
; -------------- FUNCION QUE PINTA EL NIVEL IX DE NIVELES_BASICOS ---------------
pintarMapa:
        ld c, 0 ; posicion y 
        ld b, 0 ; posicion x 
        
        ld d , (ix) ; tamaño en y del mapa
        ld e, (ix + 1) ; tamaño en x del mapa
bucle3:  
; -------------- switch --------------
        
        ld a , b                ; Metemos b (posicion del cuadrado) en a, para ver cuando se ha llegado al final de la fila
        cp e                    ; Si llegamos al final de la fila, (comparar con e, tamaño en x del mapa)
        jr z, cambiarFila       ; cambiamos de fila
volver:        
        ld a , c                ; Lo mismo que con el tamaño en x, pero en y
        cp d                    ; Comparamos con el tamaño de y
        jr z, salirFuncion      ; Si hemos llegado a la ultima fila, salimos de la funcion, ya que hemos acabado

        ld a, (ix + 5)          ; Guardamos en a el primer cuadrado del mapa, para comparar
        cp $08                  ; Comparamos a con $08
        jr nz, comparar3        ; si no es $08, saltamos a comparar el siguiente
        jr fin_switch           ; si es $08, vamos al final del switch

comparar3:    
        ; si es $40
        cp $40                  ; Comparamos a con $40
        jr nz, comparar5        ; Si no es $40, saltamos al siguiente a comparar
        push af                 ; Si si que es 40, metemos a en una pila, para poder pintar
        ld a , 7                ; guardamos en a el color del cuadrado a pintar
        call pintar             ; llamamos a pintar con las coordenadas b y c, y el color a 
        pop af                  ; sacamos de la pila a
        jr fin_switch           ; vamos al final del switch

comparar5:      
        ; si es $10
        cp $10                  ; Comparamos con $10
        jr nz, comparar6        ; si no es $10, saltamos al siguiente a comparars
        push af                 ; si si que es $10, metemos en la pila a, para guardar el cuadrado 
        ld a , 1                ; Guardamos en a el color del cuadrado a pintar
        call pintar             ; Pintamos el cuadrado
        pop af                  ; Sacamos de la pila a
        jr fin_switch           ; Vamos al final del switch

comparar6:
        ; si es $20
        cp $20                  ; Comparamos con $20
        jr nz, comparar7        ; Si no es $20, saltamos al siguiente comparar
        push af                 ; Metemos en la pila a
        ld a , 6                ; Guardamos en a el color a pintar del cuadrado
        call pintar             ; Pintamos el cuadrado
        pop af                  ; Sacamos de la pila 
        jr fin_switch           ; Vamos al final del switch
comparar7:      
        ; si es $80
        cp $80                  ; Comparamos con $80
        jr nz, fin_switch       ; Si no es $80, vamos al final del switch
        push af                 ; Metemos en la pila a
        ld a , 2                ; Guardamos en a el color a pintar del cuadrado
        call pintar             ; Pintamos el cuadrado
        pop af                  ; Sacamos de la pila a
        jr fin_switch           ; Vamos al final del switch

        
fin_switch: 
        
        inc b                   ; Incrementamos b, que es la coordenada x del cuadrado a pinar
        inc ix                  ; Incrementamos ix, pasamos al siguiente numero del array del nivel
        push af                 ; Metemos en la pila a
        ld a , h                ; Metemos h en a, para comparar 
        cp $5b                  ; Comparamos con $5b
        pop af                  ; Sacamos de la pila af
        jr nz, bucle3           ; Si no hemos acabado el bucle, saltamos a bucle3, que es el bucle del while
        ret                     ; Si hemos acabado, retornamos a donde estabamos

cambiarFila:
        
        ld b, 0                 ; Si hemos cambiado de fila,ponemos b en 0
        inc c                   ; e incrementamos c (coordenada y) 
        jr volver               ; saltamos a volver, donde estabamos antes de cambiar fila

salirFuncion:
        ret                     ; Salimos de la funcion

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
