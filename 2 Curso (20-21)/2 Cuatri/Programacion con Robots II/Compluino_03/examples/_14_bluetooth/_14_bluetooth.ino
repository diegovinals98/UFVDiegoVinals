/*
   Compluino 03
   Ejemplo 14: Bluetooth
   06/2017
   www.complubot.com
   Controla el movimiento del robot a través de un
   sistema Android mediante la comunicación Bluetooth.
   Una de las aplicaciones para smartphone con las que comprobar el
   funcionamiento del programa es Bluetooth Terminal HC-05.

*/
#include <Compluino_03.h>

Compluino_03 Robot;

#define VELOCIDAD 70

void setup()
{
  Robot.inicia();

  Robot.enciende(RGB_ROJO);  // El robot se encuentra parado

  Robot.escribe_oled (1, 2, "Control robot");
  Robot.escribe_oled (1, 4, "  mediante");
  Robot.escribe_oled (1, 6, " Bluetooth");

  Serial.begin(9600);
}

void loop()
{
  if (Serial.available()>0)
  {
    switch (Serial.read())
    {
      case 'A':  //Avanza
        Robot.enciende(RGB_VERDE);
        Robot.avanza(VELOCIDAD);
        break;

      case 'R':  //Retrocede
        Robot.enciende(RGB_BLANCO);
        Robot.retrocede(VELOCIDAD);
        break;

      case 'D':  //Gira a la derecha
        Robot.enciende(RGB_MAGENTA);
        Robot.gira_derecha(50);
        break;

      case 'I':  //Gira a la izquierda
        Robot.enciende(RGB_AZUL);
        Robot.gira_izquierda(50);
        break;

      case 'P':  //Para
        Robot.enciende(RGB_ROJO);
        Robot.para();
        break;
    }
  }
}