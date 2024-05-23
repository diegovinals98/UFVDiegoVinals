/*
 *  Compluino 03
 *  Ejemplo 5: Control del pulsador
 *  10/2017
 *  www.complubot.com
 *  
 *  Mientras apretemos el pulsador, el altavoz emite un sonido
 *  de una frecuencia de 1000 Hz
*/
#include <Compluino_03.h>

Compluino_03 Robot;

void setup()
{
  Robot.inicia();
  Robot.escribe_oled (1, 6, "Aprieta");
  Robot.escribe_oled (1, 7, "el pulsador -->");
}

void loop()
{
  if (Robot.estado_pulsador())
  {
    Robot.enciende_altavoz(1000);
  }
  else
  {
    Robot.apaga_altavoz();
  }
}
