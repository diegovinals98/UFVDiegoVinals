#include <Keypad.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

// Pines de conexión para el LCD
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Pines de conexión
#define Sensor 2
#define LEDG 5
#define LEDR 4
#define Buzzer 3

SoftwareSerial espSerial(6, 7); // RX, TX

bool alarmaActiva = false;
bool alarmaSonando = false;
bool temporizadorActivo = false;
unsigned long tiempoInicio = 0;
const int duracionTemporizador = 30000; // 30 segundos

String inputCode = "";
const String desactivacionCode = "2217";
const String activacionCode = "2217";
unsigned long lastKeyPressTime = 0;
const unsigned long keyPressTimeout = 5000; // 5 segundos
String ultimoMensajeLCD = "";

// Configuración del teclado
const byte ROWS = 4; // Cuatro filas
const byte COLS = 4; // Cuatro columnas

// Definir los símbolos del teclado en la matriz
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {22, 23, 24, 25}; // Conectar a los pines de fila del teclado
byte colPins[COLS] = {26, 27, 28, 29}; // Conectar a los pines de columna del teclado

// Crear la instancia del teclado
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void actualizarLCD(String mensaje, int linea = 0, bool clear = true) {
  if (clear) {
    lcd.clear();
  }
  lcd.setCursor(0, linea);
  lcd.print(mensaje);
}

void sendTelegramMessage(String message) {
  espSerial.print("AT+SEND:");
  espSerial.println(message);
}

void mostrarEstadoAlarma() {
  if (alarmaActiva && !alarmaSonando) {
    actualizarLCD("Alarma Activada", 0, false);
  } else if (!alarmaActiva) {
    actualizarLCD("Alarma sin funcionar", 0, false);
  } else if (alarmaSonando) {
    actualizarLCD("Movimiento Detectado", 0, false);
  }
}

void checkCode() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
    inputCode += key;
    Serial.print("Input Code: ");
    Serial.println(inputCode);
    lastKeyPressTime = millis(); // Actualiza el tiempo de la última pulsación

    // Mostrar el código ingresado en la segunda línea del LCD
    actualizarLCD(inputCode, 1, false);

    if (key == 'A' && inputCode.startsWith(activacionCode)) {
      temporizadorActivo = true;
      tiempoInicio = millis();
      actualizarLCD("Alarma en 30s", 0); // Mostrar en la primera línea
      inputCode = ""; // Limpiar el código de entrada después de activar la alarma
    } else if (inputCode.length() >= 5 && key == '#') {
      if (inputCode == desactivacionCode + "#") {
        alarmaActiva = false;
        alarmaSonando = false;
        temporizadorActivo = false;
        sendTelegramMessage("Alarma desactivada con código");
        Serial.println("Alarma desactivada con código");
        actualizarLCD("Codigo correcto", 0); // Mostrar en la primera línea
        delay(2000);
      } else {
        Serial.println("Codigo incorrecto");
        Serial.println(inputCode);
        actualizarLCD("Codigo incorrecto", 0); // Mostrar en la primera línea
        delay(2000);
      }
      inputCode = "";
    }
  }

  // Si han pasado más de keyPressTimeout desde la última pulsación, resetea inputCode
  if (millis() - lastKeyPressTime > keyPressTimeout) {
    inputCode = "";
    actualizarLCD("", 1); // Limpiar la segunda línea del LCD
  }
}

void setup() {
  Serial.begin(115200);
  espSerial.begin(115200);

  pinMode(Sensor, INPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  delay(2000);

  Serial.println("Sistema iniciado");
  actualizarLCD("Sistema iniciado", 0);
  sendTelegramMessage("Sistema iniciado");
  delay(2000);
}

void loop() {
  checkCode();

  if (temporizadorActivo) {
    unsigned long tiempoTranscurrido = millis() - tiempoInicio;
    int segundosRestantes = (duracionTemporizador - tiempoTranscurrido) / 1000;
    actualizarLCD("Alarma en " + String(segundosRestantes) + "s", 0);

    if (tiempoTranscurrido >= duracionTemporizador) {
      alarmaActiva = true;
      temporizadorActivo = false;
      sendTelegramMessage("Alarma activada con código");
      Serial.println("Alarma activada con código");
      actualizarLCD("Alarma activada", 0);
      delay(2000);
    }
    return;
  }

  if (alarmaActiva && !alarmaSonando) {
    int value = digitalRead(Sensor);
    Serial.println("Valor del sensor: " + String(value));
    digitalWrite(LEDG, HIGH); // Encender el LED verde cuando la alarma está activa y no hay movimiento detectado

    if (value == HIGH) {
      alarmaSonando = true;
      Serial.println("Movimiento Detectado");
      sendTelegramMessage("¡Movimiento detectado!");
      digitalWrite(LEDG, LOW); // Apagar el LED verde cuando se detecta movimiento
    }
  } else if (!alarmaSonando) {
    digitalWrite(LEDG, LOW); // Apagar el LED verde cuando la alarma no está activa
  }

  while (alarmaSonando) {
    checkCode(); // Continuar verificando el código de desactivación
    digitalWrite(LEDR, HIGH);
    digitalWrite(Buzzer, HIGH);
    actualizarLCD("Movimiento Detectado", 0);
    actualizarLCD(inputCode, 1, false);

    if (!alarmaActiva) { // Salir del loop infinito si la alarma es desactivada
      digitalWrite(LEDR, LOW);
      digitalWrite(Buzzer, LOW);
      digitalWrite(LEDG, LOW);
      actualizarLCD("Alarma desactivada", 0);
      delay(2000);
      alarmaSonando = false;
    }
    delay(100);
  }

  mostrarEstadoAlarma();
}
