#!/bin/bash
echo "Introduzca un nombre del directorio: " 
read $directorio
echo "enlaces simbolicos en el directorio $directorio"
for fichero in $(find directorio -type l)
do
echo "$fichero"
done
