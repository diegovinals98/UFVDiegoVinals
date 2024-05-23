/*
 * Compluino 03 
 * Ejemplo 13: Configuración de módulo Bluetooth  
 * 06/2017
 * www.complubot.com
 * Configura el módulo Bluetooth con el nombre indicado
 * a una velocidad de comunicacion de 9600 baudios con 1 
 * bit de Stop y sin paridad. Para realizar la configuración:
 * 1. Escribir el nombre deseado en la función configura_bluetooth.
 * 2. Conectar el cargador usb2serial en su conector y cargar el 
 *    programa en el robot con el módulo Bluetooth desconectado. 
 * 3. A continuación desconectar el cargador usb2serial e insertar 
 *    el módulo Bluetooth en su conector. 
 * 4. Presionar el botón del módulo Bluetooth.
 * 5. Encender el robot manteniendo presionado el botón del módulo 
 *    Bluetooth y esperar hasta que empiece a parpadear el led del 
 *    módulo Bluetooth lentamente.
 * 6. Soltar el botón del módulo Bluetooth.
 * 7. Para finalizar presionar el pulsador del robot (BUTTON) para 
 *    iniciar la configuración.
 * 8. La configuración habrá terminado cuando el led del módulo 
 *    Bluetooth parpadee más rápido que anteriormente.
*/
#include <Compluino_03.h>

Compluino_03 Robot;

void setup()
{
  Robot.inicia();
  Robot.configura_bluetooth("Compluino_03");
}

void loop() 
{

}
