#!/bin/bash
#Lista todos los ficheros del directorio actual
echo "--------------------------------------------------"
echo "------------------EJEMPLO 012---------------------"
echo "--------------------------------------------------"
for x in *
do
ls -l "$x"
sleep 1
done
