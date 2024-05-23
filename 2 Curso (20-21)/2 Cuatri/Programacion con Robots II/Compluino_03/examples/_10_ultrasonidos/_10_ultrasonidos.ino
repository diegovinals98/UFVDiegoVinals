/*
 * Compluino 03 
 * Ejemplo 10: Control de ultrasonidos 
 * 10/2017
 * www.complubot.com
 * Configura el sensor de ultrasonidos para que el 
 * robot avance hasta que detecte un obstáculo que
 * se encuentre a 15 cm o menos de él
*/
#include <Compluino_03.h>

Compluino_03 Robot; 

int distancia;

void setup() 
{
  Robot.inicia();
  Robot.escribe_oled (1, 1, "Distancia (cm)");
}

void loop() 
{
  distancia = Robot.escribe_oled_distancia(4,4,T_GRANDE,LED);
  if (distancia < 10)
  {
    Robot.para();
  }
  else
  {
    Robot.avanza(70);
  }
}
