#!/bin/bash
# Lista todos los ficheros del directorio /bin
echo "--------------------------------------------------"
echo "------------------EJEMPLO 011---------------------"
echo "--------------------------------------------------"
for x in /bin
do 
ls -l "$x"
done
