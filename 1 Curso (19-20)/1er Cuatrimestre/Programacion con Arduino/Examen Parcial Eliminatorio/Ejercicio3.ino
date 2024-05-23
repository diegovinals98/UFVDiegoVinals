#define pot1 A10
#define pot2 A12
#define led1 8
#define led2 7
#define led3 6

void setup() {
  
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

}

void loop() {


analogWrite(led1, 0);
for(int i = 0 ; i< 255 ; i++){
  
  analogWrite(led1 , i);
  int value1 = analogRead(pot1);
  int value2 = analogRead(pot2);
  value1 = map(value1, 0, 1023, 0, 255);
  value2 = map(value2, 0, 1023, 0, 255);
  analogWrite(led2, value1);
  analogWrite(led3, value2);
  

  Serial.print("El Led 1 tiene valor: ");
  Serial.print(i);
  Serial.print("\n");

  Serial.print("El Led 2 tiene valor: ");
  Serial.print(value1);
  Serial.print("\n");

  Serial.print("El Led 3 tiene valor: ");
  Serial.print(value2);
  Serial.print("\n");

  delay(25);
  
}
 
}
