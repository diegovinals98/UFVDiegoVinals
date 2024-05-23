/*
   Compluino 03
   Ejemplo 9: Siguelíneas
   10/2017
   www.complubot.com
   Los sensores reflexivos distinguen entre blanco (0)
   y negro (1) y el robot es capaz de seguir una línea
   negra sobre un fondo blanco
*/
#include <Compluino_03.h>

Compluino_03 Robot;

void setup()
{
  Robot.inicia();

  Robot.escribe_oled(2, 0, "Siguelineas");
  Robot.escribe_oled(4, 1, "Basico");
  Robot.escribe_oled(0, 5, "Pulsa para");
  Robot.escribe_oled(0, 6, "Comenzar");
  Robot.escribe_oled(13, 7, "-->");
  Robot.espera_pulsador();
  Robot.borra_oled();
}

void loop()
{
  if (Robot.lee_suelo_dd() == BLANCO)
  {
    Robot.mueve_motor(PIN_MOTOR_D, 100);
  }
  else
  {
    Robot.mueve_motor(PIN_MOTOR_D,0);
  }
  if (Robot.lee_suelo_id() == BLANCO)
  {
    Robot.mueve_motor(PIN_MOTOR_I, 100);
  }
  else
  {
    Robot.mueve_motor(PIN_MOTOR_I,0);
  }
}