/*
   Compluino 03
   Ejemplo 2: Movimientos basicos
   06/2017
   www.complubot.com
   
   El robot realiza una secuencia de movimientos basicos
*/
#include <Compluino_03.h>

Compluino_03 Robot;

void setup()
{
  Robot.inicia();
}

void loop()
{
  Robot.escribe_oled(0,0,"Pulsa para");
  Robot.escribe_oled(0,2,"Comenzar");
  Robot.escribe_oled(13,7,"-->");
  Robot.espera_pulsador();
  Robot.borra_oled();

  Robot.escribe_oled(0,4,"Avanza        ");
  Robot.avanza(70);
  Robot.espera_segundos(5);

  Robot.escribe_oled(0,4,"Gira derecha  ");
  Robot.gira_derecha(70);
  Robot.espera_milisegundos(1500);

  Robot.escribe_oled(0,4,"Avanza        ");
  Robot.avanza(70);
  Robot.espera_milisegundos(2500);

  Robot.escribe_oled(0,4,"Retrocede     ");
  Robot.retrocede(70);
  Robot.espera_milisegundos(2500);

  Robot.escribe_oled(0,4,"Gira izquierda");
  Robot.gira_izquierda(70);
  Robot.espera_milisegundos(1600);

  Robot.escribe_oled(0,4,"Retrocede     ");
  Robot.retrocede(70);
  Robot.espera_segundos(5);
  
  Robot.para();
  Robot.borra_oled();
}
