/*
 * Compluino 03 
 * Ejemplo 8: Control de tonos del altavoz
 * mediante LDR
 * 10/2017
 * www.complubot.com
 * Lee el valor de luz existente con la LDR y
 * lo convierte a un rango de 0 a 6000, que será
 * el rango de frecuencias en Hz emitidas por el 
 * altavoz. También escribe en el display OLED 
 * el valor de la frecuencia emitida.

*/
#include <Compluino_03.h>

Compluino_03 Robot;

int valor_ldr;

void setup() 
{
  Robot.inicia();
}

void loop() 
{
  valor_ldr = Robot.escribe_oled_ldr(4, 3, T_GRANDE, 0, 6000);
  Robot.enciende_altavoz(valor_ldr);
}
