/*
   Compluino 03
   Ejemplo 11: Servomotor
   10/2017
   www.complubot.com
   Mueve el servomotor en intervalos de 5 grados
   cada 100 milisegundos, primero en sentido
   anti-horario y luego en sentido horario.
   También escribe en el display OLED la posición
   del servomotor.
*/
#include <Compluino_03.h>

Compluino_03 Robot;

int posicion;

void setup()
{
  Robot.inicia();
}

void loop()
{
  //Mueve el servo en sentido anti-horario
  for (posicion = 0; posicion < 180; posicion+=5)
  {
    Robot.pos_servo(posicion);
    Robot.escribe_oled_int(0, 0, posicion);
    Robot.espera_milisegundos(100);
  }

  //Mueve el servo en sentido horario
  for (posicion = 180; posicion > 0; posicion-=5)
  {
    Robot.pos_servo(posicion);
    Robot.escribe_oled_int(0, 0, posicion);
    Robot.espera_milisegundos(100);
  }
}
