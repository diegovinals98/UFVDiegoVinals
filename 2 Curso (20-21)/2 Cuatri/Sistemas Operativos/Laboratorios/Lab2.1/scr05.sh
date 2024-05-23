#!/bin/bash
echo -n "Introduzca un numeor 1 < x < 10:"
read num
if ["$num" -gt 1] && ["$num" -lt 10]; then
 echo "$num*$num=$(($num*$num))"
else
 echo "Numero introducido incorrecto !"
fi
