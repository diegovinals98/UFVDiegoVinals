/*
 * Compluino 03 
 * Ejemplo 4: Prueba de colores del LED RGB 
 * 06/2017
 * www.complubot.com
 * Enciende secuencialmente los tres colores primarios del
 * LED RGB y posteriormente todas las combinaciones posibles
 * entre ellos
*/

#include <Compluino_03.h>

Compluino_03 Robot;

void setup() 
{
  Robot.inicia();
  Robot.escribe_oled(1,1,"Colores con el");
  Robot.escribe_oled(4,3,"Led RGB");
}

void loop() 
{
  Robot.escribe_oled(4,5,"Rojo    ");
  Robot.enciende(RGB_ROJO);
  Robot.espera_segundos(1);

  Robot.escribe_oled(4,5,"Verde   ");
  Robot.enciende(RGB_VERDE);
  Robot.espera_segundos(1);

  Robot.escribe_oled(4,5,"Azul    ");
  Robot.enciende(RGB_AZUL);
  Robot.espera_segundos(1);

  Robot.escribe_oled(4,5,"Magenta ");
  Robot.enciende(RGB_MAGENTA);
  Robot.espera_segundos(1);

  Robot.escribe_oled(4,5,"Cian    ");
  Robot.enciende(RGB_CIAN);
  Robot.espera_segundos(1);

  Robot.escribe_oled(4,5,"Amarillo");
  Robot.enciende(RGB_AMARILLO);
  Robot.espera_segundos(1);

  Robot.escribe_oled(4,5,"Blanco  ");
  Robot.enciende(RGB_BLANCO);
  Robot.espera_segundos(1);
}