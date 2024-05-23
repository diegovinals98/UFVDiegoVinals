#!/bin/bash
echo "Escriba el dia: "
read dia
echo "Escriba el mes de nacimiento: "
read mes

if [ "$mes" -eq 1 ]
then
 if [ "$dia" -gt 20 ]
 then 
  echo Acuario
 else
  echo Capricornio
 fi
fi

if [ "$mes" -eq 2 ]
then
 if [ "$dia" -gt 18 ]
 then 
  echo Piscis
 else 
  echo  Acuario
 fi
fi

if [ "$mes" -eq 3 ]
then 
 if [ "$dia" -gt 20 ]
 then 
  echo Aries
 else
  echo Piscis
 fi 
fi

if [ "$mes" -eq 4 ]
then 
 if [ "$dia" -gt 20 ]
 then 
  echo Tauro
 else
  echo Aries
 fi 
fi

if [ "$mes" -eq 5 ]
then 
 if [ "$dia" -gt 21 ]
 then 
  echo Geminis
 else
  echo Tauro
 fi 
fi

if [ "$mes" -eq 6 ]
then 
 if [ "$dia" -gt 20 ]
 then 
  echo Cancer
 else
  echo Geminis
 fi 
fi

if [ "$mes" -eq 7 ]
then 
 if [ "$dia" -gt 22 ]
 then 
  echo Leo
 else
  echo Cancer
 fi 
fi

if [ "$mes" -eq 8 ]
then 
 if [ "$dia" -gt 22 ]
 then 
  echo Virgo
 else
  echo Leo
 fi 
fi

if [ "$mes" -eq 9 ]
then 
 if [ "$dia" -gt 22 ]
 then 
  echo Libra
 else
  echo Virgo
 fi 
fi

if [ "$mes" -eq 10 ]
then 
 if [ "$dia" -gt 22 ]
 then 
  echo Escorpio
 else
  echo Libra
 fi 
fi

if [ "$mes" -eq 11 ]
then 
 if [ "$dia" -gt 21 ]
 then 
  echo Sagitario
 else
  echo Escorpio
 fi 
fi

if [ "$mes" -eq 12 ]
then 
 if [ "$dia" -gt 21 ]
 then 
  echo Capricornio
 else
  echo Sagitario
 fi 
fi






