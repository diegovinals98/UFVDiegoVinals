#!/bin/bash
echo -n "Introduce un numero entre 1 y 10: "
read num
if [[ "$num" -gt 1 && "$num" -lt 10 ]]; then
 echo “$num*$num=$(($num*$num))”
else
 echo “Número introducido incorrecto !”
fi
