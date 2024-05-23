#define data_pin 8
#define latch_pin 9
#define clock_pin 10
#define x_pin A2
#define y_pin A3
#define sw_pin 4

  void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(data_pin,OUTPUT);
pinMode(clock_pin,OUTPUT);
pinMode(latch_pin,OUTPUT);
pinMode(sw_pin, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:

int ValorX= analogRead(x_pin);
int ValorY= analogRead(y_pin);
int ValorBoton = digitalRead(sw_pin);

byte byteF = 00000000;

  Serial.print(ValorX);
  Serial.print("\n");
  Serial.print(ValorY);
  Serial.print("\n");
  delay(1000);




if (ValorY >= 540){
  
  for(int pepe  = 0;pepe <=  8;  pepe++){
//    ValorX= analogRead(x_pin);
//    ValorY= analogRead(y_pin);
    digitalWrite(latch_pin,0);
    bitClear(byteF , pepe -1);
    shiftOut(data_pin, clock_pin, LSBFIRST, bitSet(byteF , pepe));
    digitalWrite(latch_pin,1);  
    delay(100 + ValorX);
       
  }
}else if(ValorY < 540){

  for(int pepe  = 0;pepe <=  8;  pepe++){
//    ValorX= analogRead(x_pin);
//    ValorY= analogRead(y_pin);  
    digitalWrite(latch_pin,0);
     bitClear(byteF , pepe -1);
    shiftOut(data_pin, clock_pin, MSBFIRST, bitSet(byteF , pepe));
    digitalWrite(latch_pin,1);  
    delay(100 + ValorX);
       
  }
}



}
