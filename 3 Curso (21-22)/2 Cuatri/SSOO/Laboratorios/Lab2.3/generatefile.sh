#!/bin/bash
echo "--------------------------------------------------"
echo "---------------EJERCICIO GENERATEFILE-------------"
echo "--------------------------------------------------"
text='[a-zA-Z]{6,20}'
declare -ir mb=1024
echo "Introduzca el nombre del fichero: "
read fichero
while [[ ! $fichero =~ $text ]]; do
        echo -n  "Introduzca nombre del fichero: (deben ser entre 6 20 caracteres) "
        read fichero
done
echo "Introduzca el tamanio en Mb: "
read tamanio
tamanioMb=$[tamanio*$mb]
echo $tamanioMb
while [[ "$tamanio" -lt 1 && "$tamanio" -gt 20 ]]; do
        echo -n  "Introduzca tamanio del fichero en Mb: (deben ser entre 1 y 20 Mb) "
        read tamanio
	tamanioMb = $tamanio*1024
done
dd if=/dev/zero of=$a.txt bs=$tamanioMb count=$tamanioMb
