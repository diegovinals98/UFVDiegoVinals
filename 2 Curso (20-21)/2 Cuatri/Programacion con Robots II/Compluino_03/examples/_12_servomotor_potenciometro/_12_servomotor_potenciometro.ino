/*
 * Compluino 03 
 * Ejemplo 12: Servomotor controlado por potenciometro
 * 06/2017
 * www.complubot.com
 * El potenciometro controla la posición del servomotor 
 */
#include <Compluino_03.h>

Compluino_03 Robot;

int pot;
int posicion;

void setup()
{
  Robot.inicia();
}

void loop() 
{
  pot = Robot.lee_pot(0,180);
  Robot.pos_servo(pot);
  posicion = Robot.lee_pos_servo();
  Robot.escribe_lectura_oled(0,0,posicion);
  Robot.espera_milisegundos(200);
}

