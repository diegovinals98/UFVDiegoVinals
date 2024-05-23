    ld hl, batman
    ld de, $4000
    ld bc, 6912

bucle:
    ; hara lo q sea
    ;ld a , (hl)
    ;ld (de), a
    ;inc de
    ;inc hl
    ;ld a, b 
    ;or c
    ;jr nz, bucle  ; bucle que da 6912 vueltas
    ;jr fin
    ldir ; hl es la fuente, de es siempre el destino y bc es siempre la longitud
    ; ldir hace lo mismo que el bucle comentado, pero mas rapido, y no modifica el registro a ni los flags
    ld a, 2
    out ($fe), a
    ld hl, $0000
    ld de,  $0000
    ld bc, 65000
    ldir ; para borrar la pantalla
    ld a ,4
    out ($fe) , a