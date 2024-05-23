#!/bin/bash
echo "--------------------------------------------------"
echo "------------------EJEMPLO 014---------------------"
echo "--------------------------------------------------"
reg='^[0-9]+$'

echo "Introduzca un numero: "; read x
let sum=0

while [[ ! $x =~ $reg ]];do
 echo -n "Introduzca un numero: "
 read x
done


for (( i=1 ; $i<$x ; i=$i+1 ));do
let "sum=$sum + $i"
done
echo "La suma de los primeros $x numeros es: $sum"

