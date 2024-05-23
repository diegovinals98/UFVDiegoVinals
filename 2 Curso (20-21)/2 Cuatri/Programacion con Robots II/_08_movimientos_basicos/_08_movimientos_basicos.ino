/*
   Compluino 03
   Ejemplo 2: Movimientos basicos
   06/2017
   www.complubot.com
   
   El robot realiza una secuencia de movimientos basicos
*/
#include <Compluino_03.h>


Compluino_03 robot;

void setup()
{
  robot.inicia();
  robot.escribe_oled(0,0,"Practica 1");
  
}

void loop()
{

  int distancia = robot.lee_distancia(0);
  if(distancia >= 10){
    robot.mueve_motor(PIN_MOTOR_D, 70);
    robot.mueve_motor(PIN_MOTOR_I, 70);
  }else {
    robot.mueve_motor(PIN_MOTOR_D, 0);
    robot.mueve_motor(PIN_MOTOR_I, 0);
    int brujula = robot.lee_brujula();
    robot.escribe_oled_brujula(0, 0, 10);
    //brujula = map(brujula, -180, 180, 0, 360);
    int objetivoBrujula = brujula+180 ;
    if(objetivoBrujula >180)
      objetivoBrujula -= 360;
    robot.espera_segundos(2);
    //while(map(robot.lee_brujula(), -180, 180, 0, 360) > objetivoBrujula + 10 || map(robot.lee_brujula(), -180, 180, 0, 360) < objetivoBrujula - 10 ){

    if(brujula > 0)
    while( robot.lee_brujula() > objetivoBrujula - 10){
      robot.escribe_oled_brujula(0, 0, 10);
      robot.mueve_motor(PIN_MOTOR_D, 50);
      robot.mueve_motor(PIN_MOTOR_I, 0);
    }

    else{
    while(robot.lee_brujula() < objetivoBrujula + 10 ){
      robot.escribe_oled_brujula(0, 0, 10);
      robot.mueve_motor(PIN_MOTOR_D, 0);
      robot.mueve_motor(PIN_MOTOR_I, 50);
    }}
    
  }
  
 
  
}
