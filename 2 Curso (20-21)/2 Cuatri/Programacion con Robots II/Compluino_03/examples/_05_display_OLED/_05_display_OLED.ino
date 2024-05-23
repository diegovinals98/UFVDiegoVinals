/*
 * Compluino 03 
 * Ejemplo 6: Mensajes en display OLED
 * 06/2017
 * www.complubot.com
 * Escribe en la pantalla OLED texto con 
 * diferentes tamaños de letra.
*/
#include <Compluino_03.h>

Compluino_03 Robot;

void setup() 
{
  Robot.inicia();
}

void loop() 
{
  Robot.escribe_oled(0,0,"Texto normal");
  Robot.escribe_oled(13,7,"-->");

  Robot.espera_pulsador();

  Robot.borra_oled();
  
  Robot.escribe_2x_oled(0,0,"Texto");
  Robot.escribe_2x_oled(0,2,"Grande");
  Robot.escribe_2x_oled(10,6,"-->");

  Robot.espera_pulsador();

  Robot.borra_oled();
}