#!/bin/bash
echo "--------------------------------------------------"
echo "------------------EJEMPLO 002---------------------"
echo "--------------------------------------------------"
reg='^[0-9]+$'
echo -n "Introduzca un numero 1 < x < 10: "
read num
while [[ ! $num =~ $reg ]]; do
	echo -n  "Introduzca un numero 1 < x < 10: "
	read num
done
if [ "$num" -lt 10 ]; then
	if [ "$num" -gt 1 ]; then
		echo "$num*$num=$(($num*$num))"
	else
		echo "Numero fuera de rango!"
	fi
else
	echo "Numero fuera de rango!"
fi

