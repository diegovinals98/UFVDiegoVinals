#!/bin/bash
echo "--------------------------------------------------"
echo "---------------EJERCICIO CATEGORIA----------------"
echo "--------------------------------------------------"
reg='^([1-9]|1[0-5])$'
echo -n "Introduzca un numero entre 1 y 200: "
read x
case $x in
[0-9]|1[0-5]) echo  "1";;
1[6-9]|2[0-9]|3[0-9]|4[0-9]|5[0-5]) echo "2";;
5[6-9]|6[0-9]|7[0-9]|8[0-9]|9[0-9]|100) echo "3";;
10[0-9]|11[0-9]|12[0-9]|13[0-9]|14[0-9]|15[0-9]|16[0-9]|17[0-9]|18[0-9]|19[0-9]|200) echo "4";;
*) echo "Inserte un valor correcto"
esac
