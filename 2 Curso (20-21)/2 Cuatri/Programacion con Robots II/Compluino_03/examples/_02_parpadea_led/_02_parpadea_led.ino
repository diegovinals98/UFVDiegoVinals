/*
 * Compluino 03 
 * Ejemplo 02: Parpadeo del LED azul 
 * 06/2017
 * www.complubot.com
 * Enciende y apaga el LED azul a intervalos de un segundo
*/

#include <Compluino_03.h>

Compluino_03 Robot;

void setup() 
{
  Robot.inicia();
  Robot.escribe_oled(2,3,"Parpadea LED");
}

void loop() 
{
  Robot.enciende(LED);
  Robot.espera_segundos(1);
  Robot.apaga(LED);
  Robot.espera_segundos(1);
}