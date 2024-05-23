#!/bin/bash
echo "--------------------------------------------------"
echo "------------------EJEMPLO 017---------------------"
echo "--------------------------------------------------"
function check() {
 if [ -e "/home/$1" ]
  then
  return 0
 else
  return 1
 fi
}
echo "Introduzca el nombre del archivo: "; read x
if check $x
then
 echo "$x existe !"
else
 echo "$x no existe !"
fi
