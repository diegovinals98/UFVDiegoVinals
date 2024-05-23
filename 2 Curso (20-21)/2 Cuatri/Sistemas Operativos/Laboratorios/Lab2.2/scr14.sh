#!/bin/bash
echo "Introduzca un numero: "
read x
let sum=0
for ((i=1 ; $i<$x ; i=$i+1)); do
let "sum=$sum+$i"
done
echo "La suma de todos los primeros numeros es" $sum"
