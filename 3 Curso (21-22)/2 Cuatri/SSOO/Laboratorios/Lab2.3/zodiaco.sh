#!/bin/bash
echo "--------------------------------------------------"
echo "---------------EJERCICIO ZODIACO------------------"
echo "--------------------------------------------------"
reg='^[0-9]+$'
echo "Escriba su dia de nacimiento: "
read dia

while [[ ! $dia =~ $reg  || "$dia" -gt 31 ]]; do
        echo -n  "Introduzca un dia valido: "
        read dia
done

echo "Escriba su mes de nacimiento: "
read mes
while [[ ! $mes =~ $reg || "$mes" -gt 12 ]]; do
        echo -n  "Introduzca un mes valido: "
        read mes
done

if [ "$mes" -eq 1 ]
then
 if [ "$dia" -lt 20 ]
 then 
  echo "Capricornio"
  elif [[ "$dia" -ge 20 && "$dia" -le 31 ]]
  then
   echo "Aquario"
 else
   echo "No valido, Enero solo tiene 30 dias"
  fi 
fi

if [ "$mes" -eq 2 ]
then
 if [ "$dia" -le 18 ]
 then 
  echo "Acuario"
  elif [[ "$dia" -gt 18 && "$dia" -le 28 ]]
  then
  echo "Piscis"
 else
  echo "No valido, Febrero tiene 28 dias"
 fi
fi

if [ "$mes" -eq 3 ]
then 
 if [ "$dia" -le 20 ]
 then 
  echo "Piscis"
  elif [[ "$dia" -ge 20  && "$dia" -le 31 ]]
  then
  echo "Aries"
 else
  echo "No valido, Marzo tiene 31 dias"
 fi 
fi

if [ "$mes" -eq 4 ]
then 
 if [ "$dia" -le 19 ]
 then 
  echo "Aries"
  elif [[ "$dia" -gt 19 && "$dia" -le 30 ]]
  then
  echo "Tauro"
 else
  echo "No valido, Abril tiene 30 dias"
 fi 
fi

if [ "$mes" -eq 5 ]
then 
 if [ "$dia" -le 20 ]
 then 
  echo "Tauro"
  elif [[ "$dia" -gt 20 && "$dia" -le 31 ]]
  then
  echo "Geminis"
 else
  echo "No valido, Mayo solo tiene 31 dias"
 fi 
fi

if [ "$mes" -eq 6 ]
then 
 if [ "$dia" -le 20 ]
 then 
  echo "Geminis"
  elif [[ "$dia" -gt 20 && "$dia" -le 30 ]]
  then
  echo "Cancer"
 else
  echo "No valido, Junio tiene 30 dias"
 fi 
fi

if [ "$mes" -eq 7 ]
then 
 if [ "$dia" -le 22 ]
 then 
  echo "Cancer"
  elif [[ "$dia" -gt 22 && "$dia" -le 31 ]]
  then
  echo "Leo"
 else
  echo "No valido, Julio tiene 31 dias"
 fi 
fi

if [ "$mes" -eq 8 ]
then 
 if [ "$dia" -le 22 ]
 then 
  echo "Leo"
  elif [[ "$dia" -gt 22 && "$dia" -le 31 ]]
  then
  echo "Virgo"
 else
  echo "No valido, Agosto tiene 31 dias"
 fi 
fi

if [ "$mes" -eq 9 ]
then 
 if [ "$dia" -le 22 ]
 then 
  echo "Virgo"
  elif [[ "$dia" -gt 22 && "$dia" -le 30 ]]
  then
  echo "Libra"
 else
  echo "No valido, Septiembre tiene 30 dias"
 fi 
fi

if [ "$mes" -eq 10 ]
then 
 if [ "$dia" -le 22 ]
 then 
  echo "Libra"
  elif [[ "$dia" -gt 22 && "$dia" -le 31 ]]
  then
  echo "Escorpio"
 else
  echo "No valido, Octubre tiene 31 dias"
 fi 
fi

if [ "$mes" -eq 11 ]
then 
 if [ "$dia" -le 21 ]
 then 
  echo "Escorpio"
  elif [[ "$dia" -gt 21 && "$dia" -le 30 ]]
  then
  echo "Sagitario"
 else
  echo "No valido, Noviembre tiene 30 dias"
 fi 
fi

if [ "$mes" -eq 12 ]
then 
 if [ "$dia" -le 21 ]
 then 
  echo "Sagitario"
  elif [[ "$dia" -gt 21 && "$dia" -le 31 ]]
  then
  echo "Capricornio"
 else
  echo "No valido, Diciembre tiene 31 dias"
 fi 
fi
