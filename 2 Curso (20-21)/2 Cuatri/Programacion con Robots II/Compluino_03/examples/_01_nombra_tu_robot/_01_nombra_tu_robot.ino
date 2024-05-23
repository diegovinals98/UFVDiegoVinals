/*
 * Compluino 03 
 * Ejemplo 01: Nombra tu robot
 * 06/2017
 * www.complubot.com
 * Con este programa puedes dar un nombre a tu robot
 * este se almacena en la memoria EEPROM
 * y se muestra cada vez que se inicia
*/

#include <EEPROM.h>
#include <Compluino_03.h>

Compluino_03 Robot;

void setup()
{
  //Cambia COMPLUINO por el nombre que quieras poner a tu robot
  //Puedes usar un máximo de 9 caracteres, sin acentos ni
  //caracteres especiales
  char nombre[10] = "DIEGO";
  
  int add = 0;	//Escribimos el nombre a partir de la dirección 0 de la EEPROM

  Robot.inicia();

  Robot.doble_beep();
  Robot.escribe_oled (1, 1, "Me has llamado:");
  Robot.escribe_oled (3, 3, nombre);

  Robot.enciende (LED);
  Robot.escribe_oled (1, 5, "Si te gusta el");
  Robot.escribe_oled (1, 6, "nombre,aprieta");
  Robot.escribe_oled (1, 7, "el pulsador-->");
  Robot.espera_pulsador();

  EEPROM.put (add, nombre);

  Robot.borra_oled();
  Robot.escribe_oled (5, 0, "¡Bien!");
  Robot.escribe_oled (1, 2, "Tu robot esta");
  Robot.escribe_oled (2, 3, "identificado");
  Robot.escribe_oled (5, 4, "como:");

  EEPROM.get (add, nombre);
  Robot.escribe_oled (3, 7, nombre);
}

void loop()
{
  //No hay nada que hacer en el bucle principal
}
