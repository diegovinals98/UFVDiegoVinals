#include <IRremote.h>  // Librería para el receptor IR



const int RECV_PIN = 8; // Pin al que conectamos la salida del receptor IR  
const int led = 7;
int status = 0;// 0 es apgado, 1 encendido
IRrecv irrecv(RECV_PIN); // Objeto de tipo IRrecv
decode_results results; // Datos que recibiremos

void setup()     
{     
  
  pinMode(led, OUTPUT);
  Serial.begin(9600);  // Utilizar el monitor en serie
  irrecv.enableIRIn(); // Activamos el receptor IR
 
}

void loop()
{
  if(irrecv.decode(&results)) // Devuelve 0 si no hay datos disponibles, 1 en caso contrario
  {     
    
    if(results.value == 0xFD30CF) { // Lo he hecho con el boton 0 
      if(status == 0){
    
        digitalWrite(led, HIGH);
        status = 1;
      } else if(status == 1){
        digitalWrite(led, LOW);
        status = 0;
      }
    }
    
     irrecv.resume(); // Reinicia el estado del receptor IR y queda listo esperando el siguiente valor
   
  }
}
