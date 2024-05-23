#!/bin/bash
echo "--------------------------------------------------"
echo "---------------EJERCICIO TABLAX-------------------"
echo "--------------------------------------------------"
echo -n "introduzca un numero: "; read x
let i=1
let mul=0
while [ $i -le 12 ]; do
let "mul = $x * $i"
echo "$x * $i = $mul"
let "i = $i + 1"
done

