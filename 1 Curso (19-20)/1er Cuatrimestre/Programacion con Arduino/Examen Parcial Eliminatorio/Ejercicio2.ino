#include <SR04.h>

// Definimos a qué pines conectamos trigger y echo
#define TRIG_PIN 12
#define ECHO_PIN 11
#define led 4

// Creamos un objeto de tipo sensor de distancia
SR04 sensor = SR04(ECHO_PIN, TRIG_PIN);

// Variable que almacenará la distancia
long distancia;

void setup() {
  delay(1000);
  Serial.begin(9600);
}

void loop() {
  distancia = sensor.Distance();
  Serial.print(distancia);
  Serial.print("\n");

  // Uso la fumcion map para pasar los valores de 0 a 70 cm a 0 1000 segundos. El valor maximo 70 sera 1000 y 0 es 0.
  // Hago esto para que el delay sea un poco mas largo, y no vaya yan rapido
  long tiempo = map(distancia, 0 , 70 , 0, 1000);
  if(distancia < 5 || distancia > 30){
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led , HIGH);
    delay(tiempo);
    digitalWrite(led , LOW);
    delay(tiempo);
  }
  
  
}
