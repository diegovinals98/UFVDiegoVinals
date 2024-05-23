#!/bin/bash
echo -n "Introduce un nunero entre 1 y 10:"
read num
if [ "$num" -lt 10 ]; then
 if [ "$num" -gt 1 ]; then
  echo “$num*$num=$(($num*$num))”
 else 
  echo “¡Número fuera de rango!”
 fi
else 
 echo “¡Número fuera de rango!”
fi
