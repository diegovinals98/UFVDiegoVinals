#include <Compluino_03.h>

#define BLANCO 0
#define NEGRO 1

Compluino_03 Robot;

void setup()
{
  Robot.inicia();
}

void loop()
{
  double velocidad = 0.0, d1 = 0.0, d2 = 0.0, lado = 0.0;
  Robot.escribe_oled(0,0,"Pulsa para");
  Robot.escribe_oled(0,2,"Comenzar");
  Robot.escribe_oled(13,7,"-->");
  Robot.espera_pulsador();
  Robot.borra_oled();

  Robot.avanza(50;
  if(Robot.lee_suelo_id() == NEGRO){
    Robot.para();
    Robot.retrocede(50);
    sleep(200);
    Robot.gira_derecha(20);
  }
  Robot.avanza();
  

    
}
