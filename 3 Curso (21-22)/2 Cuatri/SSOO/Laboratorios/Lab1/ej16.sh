#!/bin/bash
echo "--------------------------------------------------"
echo "------------------EJEMPLO 016---------------------"
echo "--------------------------------------------------"
reg='^[0-9]+$'
echo "Introduzca un numero: "; read x
echo ;

while [[ ! $x =~ $reg ]];do
 echo -n "Introduzca un numero: "
 read x
done

until [ "$x" -le 0 ]; do
echo $x
x=$(($x - 1))
sleep 1
done
echo ; echo FIN

