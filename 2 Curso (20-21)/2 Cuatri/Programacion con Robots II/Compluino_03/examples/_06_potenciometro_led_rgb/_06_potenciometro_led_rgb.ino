/*
 * Compluino 03 
 * Ejemplo 6: Control de brillo del LED RGB mediante el
 * potenciómetro
 * 06/2017
 * www.complubot.com
 * Lee el valor analógico del potenciómetro en un rango
 * de 0 a 100 y lo utiliza para controlar el brillo del
 * LED azul del LED RGB. También imprime en el display 
 * OLED el valor leído.
*/
#include <Compluino_03.h>

Compluino_03 Robot;

int brillo;

void setup() 
{
  Robot.inicia();

  Robot.escribe_oled (1, 0, "Cambia brillo");
  Robot.escribe_oled (1, 1, "del RGB azul");
  Robot.escribe_oled (1, 2, "   con el");
  Robot.escribe_oled (1, 3, "potenciometro");
}

void loop() 
{
  brillo = Robot.escribe_oled_pot(4, 5, T_GRANDE, 0, 100);
  Robot.brillo_rgb(0,0,brillo);
}
