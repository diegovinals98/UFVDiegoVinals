#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int pulasodorLetras = 13;
const int pulsadorSeleccion = 8;
const int pulsadorCambio = 7;

int pulsarLetras;
int decidirLetra;
int tercerBoton;


                                          
void setup()
{
  
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(pulsadorCambio, INPUT);
  pinMode(pulasodorLetras, INPUT);
  pinMode(pulsadorSeleccion, INPUT);
  
 
}

void loop()
{
  String inicial = "ABCDEFGHIJQLMNOPQRSTUVWXYZ";
  String palabra = "";
  String palabraNueva = "";
  
  
  
  if(tercerBoton == HIGH){
    
    
    lcd.setCursor(0, 0);
    lcd.print("Codificando:");
    int cursor = 0;
    lcd.setCursor(cursor,1);
    int i = 0;
    
    while(tercerBoton == HIGH){
      lcd.setCursor(cursor,1);
      lcd.print(inicial.charAt(i));
      pulsarLetras = digitalRead(pulsadorSeleccion); 
      if(pulsarLetras == HIGH){
        lcd.setCursor(cursor , 1);
        lcd.print(inicial.charAt(i++));
        if(i == 27){
          i = 0;
        }
      }

      decidirLetra = digitalRead(pulasodorLetras);
      if(decidirLetra == HIGH){
        palabra = palabra + inicial.charAt(i);
        cursor++;
        lcd.setCursor(cursor, 1);
      }
      delay(100);
      tercerBoton = digitalRead(pulsadorCambio);
      
    }
    tercerBoton = digitalRead(pulsadorCambio);
    
  } 

  
     // aplicamos el codificado
    int cod = 5;
    for(int j =0 ; j < palabra.length() ; j++){
      char letra = palabra.charAt(j);
      int index = inicial.indexOf(letra);
      int nuevoIndex = index + cod;
      if(nuevoIndex > inicial.length()){
        nuevoIndex = nuevoIndex - 26;
      }
      char nuevaLetra = inicial.charAt(nuevoIndex);
      palabraNueva = palabraNueva + nuevaLetra;
      Serial.println(palabraNueva);

    }

     while(tercerBoton == LOW){
    lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("Cifrado!");
       lcd.setCursor(0,1);
       lcd.print(palabraNueva);
       Serial.println(palabraNueva);
       delay(10000);
  }
     


  }
