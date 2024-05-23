#include "Compluino_03.h"

Calibra u;

Compluino_03 Robot;

void setup()
{
  
  Robot.inicia();

  Robot.escribe_oled(0, 0, "Calibra brujula");
  Robot.escribe_oled(1, 1, "MinX:");
  Robot.escribe_oled(1, 2, "MaxX:");
  Robot.escribe_oled(1, 3, "MinY:");
  Robot.escribe_oled(1, 4, "MaxY:");

  EEPROM.get(ADD_BRUJULA, u);

  Robot.escribe_oled_int(8, 1, (int)u.minX);
  Robot.escribe_oled_int(8, 2, (int)u.maxX);
  Robot.escribe_oled_int(8, 3, (int)u.minY);
  Robot.escribe_oled_int(8, 4, (int)u.maxY);

  Robot.escribe_oled (0, 6, "Para comenzar");
  Robot.escribe_oled (7, 7, "Pulsar ->");
  Robot.espera_pulsador();
  Robot.borra_oled();
  
}

void loop()
{


  unsigned long tiempo = millis();

  Robot.escribe_oled(0, 0, "Calibra brujula");
  Robot.escribe_oled(1, 1, "MinX:");
  Robot.escribe_oled(1, 2, "MaxX:");
  Robot.escribe_oled(1, 3, "MinY:");
  Robot.escribe_oled(1, 4, "MaxY:");

  Robot.gira_derecha(70);

  while ((millis() - tiempo) < 10000)
  {
    u = Robot.obtener_offset();
    Robot.escribe_oled_int(8, 1, (int)u.minX);
    Robot.escribe_oled_int(8, 2, (int)u.maxX);
    Robot.escribe_oled_int(8, 3, (int)u.minY);
    Robot.escribe_oled_int(8, 4, (int)u.maxY);
    delay(10);
  }

  Robot.para();
  Robot.beep();

  Robot.escribe_oled (1, 7, "Guardar? -->");

  Robot.espera_pulsador();

  //Guardamos en la EEPROM los valores del offset de la brujula
  EEPROM.put(ADD_BRUJULA, u);

  Robot.beep();
  Robot.borra_oled();

  Robot.escribe_oled (1, 0, "Offsets de la");
  Robot.escribe_oled (1, 1, "   brujula");
  Robot.escribe_oled (1, 2, "guardados en");
  Robot.escribe_oled (1, 3, " la EEPROM");

  delay(2000);

  Robot.borra_oled();

  Robot.escribe_oled(0, 0, "Calibra brujula");
  Robot.escribe_oled(1, 1, "MinX:");
  Robot.escribe_oled(1, 2, "MaxX:");
  Robot.escribe_oled(1, 3, "MinY:");
  Robot.escribe_oled(1, 4, "MaxY:");

  EEPROM.get (ADD_BRUJULA, u);

  Robot.escribe_oled_int(8, 1, (int)u.minX);
  Robot.escribe_oled_int(8, 2, (int)u.maxX);
  Robot.escribe_oled_int(8, 3, (int)u.minY);
  Robot.escribe_oled_int(8, 4, (int)u.maxY);

  // El programa se detiene para no repetir la calibración
  while (true);
}