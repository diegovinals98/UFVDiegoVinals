#!/bin/bash
echo "--------------------------------------------------"
echo "------------------EJEMPLO 001---------------------"
echo "--------------------------------------------------"
echo -n "Introduzca su nombre de usuario: "
read login
if [ "$login"  = "$USER" ]; then echo "Hola, $login. Como esta hoy";
elif [ -z "$login" ]; then echo "Campo vacio";
else echo "Tu no eres $USER";
fi
