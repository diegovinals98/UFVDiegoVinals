#!/bin/bash
echo "--------------------------------------------------"
echo "------------------EJEMPLO 005---------------------"
echo "--------------------------------------------------"
reg='^[0-9]+$'
echo -n "Introduzca un numero 1 < x < 10: "
read num
while [[ ! $num =~ $reg ]]; do
	echo -n "introduzca un numerp 1 < x < 10: "
	read num
done
if [ "$num" -gt 1 ] && [ "$num" -lt 10 ]; then
	echo "$num*$num=$(($num*$num))"
else
	echo "Numero introducido incorrecto"
fi
