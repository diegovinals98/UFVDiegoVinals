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

  while(Robot.lee_suelo_id() == BLANCO){
    Robot.escribe_oled(0,4,"Avanza        ");
    Robot.avanza(70);
  }

  while(Robot.lee_suelo_id() == NEGRO){
    Robot.escribe_oled(0,4,"Avanza        ");
    Robot.avanza(70);

    if(Robot.lee_suelo_dd() == NEGRO){
      if(d1 == 0.0)
        d1 = Robot.lee_distancia();

      else{
          d2 = Robot.lee_distancia();
          lado = d1-d2;
          Robot.para();
          Robot.borra_oled();
          Robot.escribe_oled(0,4,"Area de la baldosa:")
          Robot.escribe_oled(1,4,lado*lado)      
      }
    }
  }
  
   while(Robot.lee_suelo_id() == BLANCO){
    velocidad += 0.1;
    Robot.escribe_oled(0,4,"Gira derecha        ");
    Robot.gira_derecha(velocidad);
    
    if(Robot.lee_suelo_id() == BLANCO){
      velocidad += 0.1;
      Robot.escribe_oled(0,4,"Gira izquierda        ");
      Robot.gira_izquierda(velocidad);
    }
  }
    
}
