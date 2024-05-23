        DEVICE ZXSPECTRUM48     ; Esto es una directiva
        org $8000               ; Programa ubicado a partir de $8000 = 32768. ESTO TAMBIEN ES UNA DIRECTIVA

inicio:         di              ; Deshabilitar interrupciones
                ld a, $E6       ; Establecer el puntero de pila en la parte alta de la memoria
                ld HL, $5800 + 32*15 + 10
                ld (HL), a


;--------------------------------------- BUCLES FOR --------------------------------------------
; instruccion DJNZ <etiqueta>
; esta instruccion solo funciona con el registro b, y le resta 1, si no ha llegado a 0 salta donde este la etiqueta
        ld a, 11111111
        ld b, 64
        ld HL, $5800

bucle:  ld (HL) , a
        inc HL
        djnz bucle   ; Decrementa b y salta si no es 0
;-------------------------------------------------------------------------------------------------
;Código del estudiante


;bucle: 
;        ld a , r                 ; el a es un registro acumulador
;        out ($fe) , a           ; el b es un registro normal. 
;        jr bucle


;-------------------------------------------------------------------------------------------------
fin:    jr fin          ; Bucle infinito

rojo:   EQU 2
verde:  EQU 4

; Las directivas le da pistas de como queremos que se comporte, NO GENERA CODIGO

; Etiquetas: Son como un define en c. Es una manera de asociar constantes y ponerles un nombre. Estas tampoco generan codigo
;       - Unicas partes que tienen que estar en la primera columna
;       - Tienen que empezar por una letra
;       - Ejemplo: fin, bucle, inicio
;

; Instrucciones: El repertorio de instrucciones de ensamblador en Z80
;       - Si genera codigo


;       - ld a, 5 instruccion de carga