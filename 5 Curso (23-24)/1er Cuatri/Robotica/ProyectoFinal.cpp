#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>


const char* ssid = "iPhone de Diego";
const char* password = "1234567890";

#define BOTtoken "6482373390:AAGxqjhMWen4_WM5kaj5wo1y8ZbI_CxGtLw"
#define CHAT_ID "903753145"

#define Sensor D0
#define LEDG D3
#define LEDR D4
#define Buzzer D5  

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
LiquidCrystal_I2C lcd (0x27, 16, 2);

bool alarmaActiva = false;
int lastMessageId = 0;
int value = 0;
 int b = 0;



void setup() {
  Serial.begin(9600);
  pinMode(Sensor, INPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(Buzzer, OUTPUT);

  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();
  
  Wire.begin();

  configTime(0, 0, "pool.ntp.org");      // obtener la hora UTC a través de NTP
  client.setTrustAnchors(&cert); // Agregar el certificado raíz para api.telegram.org
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  int a = 0;
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    lcd.setCursor(a, 0);
    lcd.print(".");
    delay(500);
    a++;
  }
  
  Serial.println("");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Conectado a WiFi");
  Serial.println("Conectado a WiFi");
  Serial.print("Dirección IP: ");
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());
  Serial.println(WiFi.localIP());
  delay(500);
  
  bot.sendMessage(CHAT_ID, "Sistema iniciado", "");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sistema iniciado");
  delay(1000);
  lcd.clear();
}

// Función para manejar los nuevos mensajes
void handleNewMessages(int numNewMessages) {
    for (int i = 0; i < numNewMessages; i++) {
        String chat_id = bot.messages[i].chat_id;
        String text = bot.messages[i].text;
        int message_id = bot.messages[i].message_id;

        if (message_id > lastMessageId) {
            lastMessageId = message_id;
            Serial.println(text);

            if (text == "Activar") {
                alarmaActiva = true;
                bot.sendMessage(chat_id, "Alarma activada", "");
            } else if (text == "Desactivar") {
                alarmaActiva = false;
                bot.sendMessage(chat_id, "Alarma desactivada", "");
            }
        }
    }
}

void loop() {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    // funcion encontrada en internet
    while (numNewMessages) {
        handleNewMessages(numNewMessages);
        numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }

    Serial.print(analogRead(Buzzer));
    if (alarmaActiva){
        int value = digitalRead(Sensor);
        Serial.println(value);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Alarma Activada");

       

        if (value == 1) {
            Serial.println("Movimiento Detectado");
            digitalWrite(LEDR, HIGH);
            digitalWrite(Buzzer, HIGH);
            digitalWrite(LEDG, LOW);
            lcd.setCursor(0, 0);
            //lcd.print(b);
            b++;
            lcd.print("Movimiento Detectado");
            bot.sendMessage(CHAT_ID, "¡Movimiento detectado!", "");
        } else if (value == 0) {
            digitalWrite(LEDR, LOW);
            digitalWrite(Buzzer, LOW);
            digitalWrite(LEDG, HIGH);
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print("Sin Movimiento");
        }

    } else if (!alarmaActiva){
        digitalWrite(LEDR, LOW);
        digitalWrite(Buzzer, LOW);
        digitalWrite(LEDG, LOW);
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Alarma sin funcionar");
    }
}
