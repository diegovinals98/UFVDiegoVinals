#!/bin/bash
echo "--------------------------------------------------"
echo "------------------EJEMPLO 013---------------------"
echo "--------------------------------------------------"
read -p "Introduzca el nombre del directorio: "
directorio
echo "enlaces simbolicos en el directorio $directorio "
for fichero in $( find $directorio -type l )
do
echo "$fichero"
done
