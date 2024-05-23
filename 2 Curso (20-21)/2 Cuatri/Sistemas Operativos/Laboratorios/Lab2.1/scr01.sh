#!/bin/bash
echo -n "Introduzca su nombre de usuario: "
read login
if [ "$login"  = "$USER" ]; then
echo “Hola, $login. Cómo está hoy?”
else
echo “Tú no eres $login!!!”
fi
