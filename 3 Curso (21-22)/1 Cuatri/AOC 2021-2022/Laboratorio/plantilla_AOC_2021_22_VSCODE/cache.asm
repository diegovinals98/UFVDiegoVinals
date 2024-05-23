    ORG $0000 


; bloque 0
    di              ; 000000 00             Fallo, cargamos bloque 0
inic: 
    ld ix, var1     ; 000000 01             Fallo, cargamos bloque 3 en cache
    ld a,(ix+0)     ; 000000 10             Acierto, ya esta el bloque 0 en cache
    ld b,(ix+1)     ; 000000 11             Fallo, cargamos el bloque 4 en cache
   
mien: 
; bloque 1 
    cp b            ; 000 001 00            Fallo, cargamos el bloque 1 en cache
    jr c, sino      ; 000 001 01            Fallo, cargamos el bloque 2 en cache
    jr z, fmien     ; 000 001 10            Acierto, no accedemos a fmien, por lo que el bloque 1 ya esta en cache
    sub b           ; 000 001 11

; bloque2
    jr mien 
sino:  
    ld e,b 
    ld b,a 
    ld a,e 

; bloque 3
    jr mien         ; 000 011 00
fmien: 
    ld (mcd), a     ; 000 011 01
fin: halt           ; 000 011 10
var1:  db 75        ; 000 011 11

; bloque 4
var2:  db 40 
mcd: db 0 