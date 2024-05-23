#!/bin/bash
echo "--------------------------------------------------"
echo "------------------EJEMPLO 004---------------------"
echo "--------------------------------------------------"
reg='^[0-9]+$'
echo -n "Introduzca un numero entre 1 < x < 10: "
read num
while [[ ! $num =~ $reg ]]; do
	echo -n  "Introduzca un numero entre 1 < x < 10: "
	read num
done
if [ "$num" -gt 1 -a "$num" -lt 10 ]; then
	echo "$num*$num = $(($num*$num))"
else
	echo "Numero introducido incorrecto!"
fi
