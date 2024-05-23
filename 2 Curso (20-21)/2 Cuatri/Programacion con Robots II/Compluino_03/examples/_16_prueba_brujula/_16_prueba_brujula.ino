#include "Compluino_03.h"

Compluino_03 Robot;

void setup() 
{
  Robot.inicia();
}

void loop() 
{
  Robot.escribe_oled(4, 1, "Brujula:");
  Robot.escribe_oled_brujula(4, 3, T_GRANDE);
  delay(10);
}
