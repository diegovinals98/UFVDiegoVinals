#!/bin/bash
echo "--------------------------------------------------"
echo "------------------EJEMPLO 003---------------------"
echo "--------------------------------------------------"

if [ -f /etc/fstab ]; then
	cp /etc/fstab copia
	echo "Hecho."
else
	echo "Archivo /etc/fstab no existe."
	exit 1
fi
