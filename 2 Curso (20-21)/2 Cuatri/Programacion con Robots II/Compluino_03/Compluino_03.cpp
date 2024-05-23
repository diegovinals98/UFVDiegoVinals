/*
Compluino_03_oop.cpp - Library for Compluino_03 robot.  
 * \class   Compluino_03
 * \brief   Driver for ATMega328p, arduino.
 * @file    Compluino_03.cpp
 * @author  Complubot - www.complubot.com
 * @version V1.0
 * @date    2017/05/25
 * @brief   Driver for Compluino_03 module.
*/

#include "Compluino_03.h"

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE); //Constructor de la pantalla OLED
Servo 		servo_robot;		//Constructor del servo
//HMC5883L 	brujula_robot;		//Constructor brujula

COMPLUINO_QMC5883 compass;

Compluino_03::Compluino_03() 
{
} //Constructor:

//************************************
//**************PUBLIC****************
//************************************


/*
 * Funcion: inicia
 *   
 * Descripcion: Configura los puertos del Compluino_03, activa ledes, altavoz y muestra mensaje de bienvenida 
 *   
 * Parámetros: ninguno
 *   
 * Retorna: nada
 */
void Compluino_03::inicia (void)
{
	// Inicializa el robot
	char nombre[10];
	
	//Deshabilita los motores
	pinMode(PIN_EN, OUTPUT);
	digitalWrite(PIN_EN, HIGH);
	analogWrite(PIN_MOTOR_D,127);
	analogWrite(PIN_MOTOR_I,127);
  
	pinMode(PIN_MOTOR_I, OUTPUT);
	pinMode(PIN_MOTOR_D, OUTPUT);
	pinMode(PIN_SUELO_I, INPUT);
	pinMode(PIN_SUELO_D, INPUT);
  
	pinMode(PIN_RGB_ROJO, OUTPUT);
	pinMode(PIN_RGB_VERDE, OUTPUT);
	pinMode(PIN_RGB_AZUL, OUTPUT);
  
	pinMode(PIN_LED, OUTPUT);
  
	pinMode(PIN_PULSADOR, INPUT);

	pinMode(PIN_ALTAVOZ, OUTPUT);
    
	//Configura display OLED
	u8x8.setI2CAddress(0x078);
	u8x8.begin();
	u8x8.setPowerSave(0);
	u8x8.setFont(u8x8_font_chroma48medium8_r);
	
	//Configura la brújula del robot
	_brujula_conectada = inicia_brujula();
	
	if (!_brujula_conectada)
	{
		error_brujula();
		espera_segundos(2);
		borra_oled();
	}
  
	//Muestra pantalla de bienvenida
	escribe_oled(1, 1, "COMPLUINO - 03");
	escribe_oled(4, 3, "Me llamo");
  
	//Muestra en nombre del robot
	EEPROM.get (ADD_NOMBRE, nombre);
	escribe_oled (4, 5, nombre);
  
	escribe_oled(2, 7, "complubot.com");

	enciende(LED);
	beep();
	apaga(LED);
  
	enciende(RGB_ROJO);
	espera_segundos(1);
	enciende(RGB_VERDE);
	espera_segundos(1);
	enciende(RGB_AZUL);
	espera_segundos(1);

	doble_beep();
  
	borra_oled();

	apaga(RGB);
}

//
// Funciones para el control del movimiento del robot ------------------------------------
//

 /*
 * Funcion: para
 *   
 * Descripcion: Detiene el movimiento del robot
 *   
 * Parámetros: ninguno
 *   
 * Retorna: nada
 */
void Compluino_03::para(void)
{
	// Para los motores
	analogWrite(PIN_MOTOR_D,127);
	analogWrite(PIN_MOTOR_I,127);
	delay(200);
	digitalWrite(PIN_EN, HIGH);
}

 /*
 * Función: avanza
 *   
 * Descripcion: Mueve el robot en el sentido de avance, a la velocidad indicada
 *   
 * Parámetros:
 *   vel: velocidad [0, 100]
 *   
 * Retorna: nada
 */
void Compluino_03::avanza(int vel)
{
	//Avanza el robot en el rango de 0 a 100%
	vel = constrain(vel, 0, 100);
	mueve_motor(PIN_MOTOR_I, vel);
	mueve_motor(PIN_MOTOR_D, vel);	
}

 /*
 * Función: retrocede
 *   
 * Descripcion: Mueve el robot en el sentido de retroceso, a la velocidad indicada
 *   
 * Parámetros:
 *   vel: velocidad [0, 100]
 *   
 * Retorna: nada
 */
void Compluino_03::retrocede(int vel)
{
	//Retrocede el robot en el rango de 0 a 100%
	vel = constrain(vel, 0, 100);
	mueve_motor(PIN_MOTOR_I, -vel);
	mueve_motor(PIN_MOTOR_D, -vel);
}

 /*
 * Función: mueve
 *   
 * Descripcion: Mueve el robot en el sentido de avance o de retroceso, a la velocidad indicada
 *   
 * Parámetros:
 *   vel: velocidad [-100, 100]
 *	 Con velocidad positiva, el robot avanza
 *	 Con velocidad negativa, el robot avanza
 *   Con velocidad cero, el robot se para pero los motores permanecen activos
 *   
 * Retorna: nada
 */
void Compluino_03::mueve(int vel)
{
	//mueve el robot en el rango de +/- 100%
	vel = constrain(vel, -100, 100);
	mueve_motor(PIN_MOTOR_I, vel);
	mueve_motor(PIN_MOTOR_D, vel);
}

 /*
 * Función: gira_derecha
 *   
 * Descripcion: Hace girar el robot hacia la derecha (sentido horario),
 *              haciendo avanzar la rueda derecha y retroceder la rueda izquierda.
 *   
 * Parámetros:
 *   vel: velocidad [0, 100]
 *   
 * Retorna: nada
 */
void Compluino_03::gira_derecha(int vel)
{
	//Gira el robot hacia la derecha en el rango de 0 a 100%
	vel = constrain(vel, 0, 100);
	mueve_motor(PIN_MOTOR_I, vel);
	mueve_motor(PIN_MOTOR_D, -vel);
}

 /*
 * Función: gira_izquierda
 *   
 * Descripcion: Hace girar el robot hacia la izquierda (sentido anti-horario),
 *              haciendo avanzar la rueda derecha y retroceder la rueda izquierda.
 *   
 * Parámetros:
 *   vel: velocidad [0, 100]
 *   
 * Retorna: nada
 */
void Compluino_03::gira_izquierda(int vel)
{
	//Gira el robot hacia la izquierda en el rango de 0 a 100%
	vel = constrain(vel, 0, 100);
	mueve_motor(PIN_MOTOR_I, -vel);
	mueve_motor(PIN_MOTOR_D, vel);
}

 /*
 * Función: gira
 *
 * Descripcion: Hace girar el robot hacia la derecha o la izquierda, usando ambas ruedas:
 *              avanzando la rueda derecha y retrocediendo la rueda izquierda para girar
 *              a la derecha (sentido horario) y avanzando la rueda izquierda y retrocediendo
 *              la rueda derecha para girar a la izquierda (sentido anti-horario)
 * 
 * Parámetros:
 *   vel: velocidad [-100, 100].
 *   Con velocidad negativa, el robot gira a la izquierda (sentido anti-horario)
 *   Con velocidad positiva, el robot gira a la derecha (sentido horario)
 *   Con velocidad cero, el robot se para pero los motores permanecen activos 
 *   
 * Retorna: nada
 */
void Compluino_03::gira(int vel)
{
	//Gira el robot en el rango de +/- 100%
	//Velocidad positiva, gira hacia la derecha
	//Velocidad negativa, gira hacia la izquierda
	vel = constrain(vel, -100, 100);
	mueve_motor(PIN_MOTOR_I, -vel);
	mueve_motor(PIN_MOTOR_D, vel);
}

/*
 * Funcion: mueve_motor
 *   
 * Descripcion: Activa el motor seleccionado a una velocidad y sentido determinados
 *   
 *	Parámetros:
 *   pwm: selecciona el motor.
 *		MOTOR_I: motor izquierdo
 *		MOTOR_D: motor derecho
 *   vel: selecciona la velocidad y sentido de movimiento de los motores [-100,100]
 *   
 * Retorna: nada
 */
void Compluino_03::mueve_motor(int pin_pwm, int vel)
{
	//mueve un motor en el rango de +/- 100%
	vel = constrain(vel, -100, 100);
	vel = map(vel, -100, 100, 0, 255);
  
	digitalWrite(PIN_EN, LOW);

	analogWrite(pin_pwm, vel);
}

//
// Funciones para el control del display OLED
//

 /*
 * Función: borra_oled
 *   
 * Descripcion: Borra el display OLED del robot
 *   
 * Parámetros: ninguno
 *   
 * Retorna: nada
 */
void Compluino_03::borra_oled(void)
{
	//Borra el display OLED
	u8x8.clear();
}

 /*
 * Función: escribe_oled
 *   
 * Descripcion: escribe un mensaje en el display OLED, en la posición indicada
 *   
 * Parámetros:
 *   x: coordenada x de la pantalla donde aparecera el texto
 *   y: coordenada y de la pantalla donde aparecera el texto
 *   texto: texto que se muestra en el oled
 *   
 * Retorna: nada
 */
void Compluino_03::escribe_oled(int x, int y, char *texto)
{
	//Escribe un texto en la posición (x,y) del display OLED
	u8x8.drawString(x, y, texto);
}

 /*
 * Función: escribe_2x_oled
 *   
 * Descripcion: escribe un mensaje en el display OLED al doble de tamaño, en la posición indicada
 *   
 * Parámetros:
 *   x: coordenada x de la pantalla donde aparecera el texto
 *   y: coordenada y de la pantalla donde aparecera el texto
 *   texto: texto que se muestra en el oled
 *   
 * Retorna: nada
 */
void Compluino_03::escribe_2x_oled(int x, int y, char *texto)
{
	//Escribe un texto, en tamaño grande, en la posición (x,y) del display OLED
	u8x8.draw2x2String(x, y, texto);
}

int Compluino_03::escribe_oled_sensor(int x, int y, int font, int ref_sensor)
{
	int lectura;
	
	switch(ref_sensor)
	{
		case REF_POT:
			lectura = escribe_oled_pot(x,y,font, 0, 100);
			break;
			
		case REF_LDR:
			lectura = escribe_oled_ldr(x,y,font, 0, 100);
			break;
			
		case REF_PULSADOR:
			lectura = escribe_oled_pulsador(x,y,font);
			break;
			
		case REF_SUELO_D:
			lectura = escribe_oled_suelo_d(x,y,font, 0, 100);
			break;
			
		case REF_SUELO_I:
			lectura = escribe_oled_suelo_i(x,y,font, 0, 100);
			break;
			
		case REF_SUELO_DD:
			lectura = escribe_oled_suelo_dd(x,y,font);
			break;
			
		case REF_SUELO_ID:
			lectura = escribe_oled_suelo_id(x,y,font);
			break;
			
		case REF_DISTANCIA:
			lectura = escribe_oled_distancia(x,y,font, SI);
			break;
			
		default:
			lectura = 0;
	}
	
	return lectura;
}

int Compluino_03::escribe_oled_pot(int x, int y, int font, int min, int max)
{
	//Escribe la lectura del potenciómetro en el display OLED
	int lectura;
	
	lectura = lee_pot(min,max);
	sprintf(texto_oled, "%0.3d", lectura);
	
	salida_oled(x,y,texto_oled, font);
	
	return lectura;
}

int Compluino_03::escribe_oled_ldr(int x, int y, int font, int min, int max)
{	
	//Escribe la lectura de la ldr en el display OLED
	int lectura;
	
	lectura = lee_ldr(min,max);
	sprintf(texto_oled, "%0.3d", lectura);
	
	salida_oled(x,y,texto_oled, font);
	
	return lectura;
}

int Compluino_03::escribe_oled_pulsador(int x, int y, int font)
{	
	//Escribe la lectura del estado del pulsador en el display OLED
	int lectura;
	
	lectura = lee_pulsador();
	if (lectura)
		strcpy(texto_oled,"PUL   ");
	else
		strcpy(texto_oled,"NO PUL");
	
	salida_oled(x,y,texto_oled, font);
	
	return lectura;
}

int Compluino_03::escribe_oled_suelo_d(int x, int y, int font, int min, int max)
{	
	//Escribe la lectura del sensor de suelo derecho en el display OLED
	int lectura;
	
	lectura = lee_suelo_d(min,max);
	sprintf(texto_oled, "%0.3d", lectura);
	
	salida_oled(x,y,texto_oled, font);
	
	return lectura;
}

int Compluino_03::escribe_oled_suelo_i(int x, int y, int font, int min, int max)
{	
	//Escribe la lectura del sensor de suelo izquierdo en el display OLED
	int lectura;
	
	lectura = lee_suelo_i(min,max);
	sprintf(texto_oled, "%0.3d", lectura);
	
	salida_oled(x,y,texto_oled, font);
	
	return lectura;
}

int Compluino_03::escribe_oled_suelo_dd(int x, int y, int font)
{	
	//Escribe la lectura del sensor de suelo derecho, en formato digital, en el display OLED
	int lectura;
	
	lectura = lee_suelo_dd();
	if (lectura)
		strcpy(texto_oled,"NEGRO ");
	else
		strcpy(texto_oled,"BLANCO");
	
	salida_oled(x,y,texto_oled, font);
	
	return lectura;
}

int Compluino_03::escribe_oled_suelo_id(int x, int y, int font)
{	
	//Escribe la lectura del sensor de suelo izquierdo, en formato digital, en el display OLED
	int lectura;
	
	lectura = lee_suelo_id();
	if (lectura)
		strcpy(texto_oled,"NEGRO ");
	else
		strcpy(texto_oled,"BLANCO");
	
	salida_oled(x,y,texto_oled, font);
	
	return lectura;
}

int Compluino_03::escribe_oled_distancia(int x, int y, int font, int led)
{
	//Escribe la lectura del sensor de distancia en el display OLED
	int lectura;
	
	lectura = lee_distancia(led);
	sprintf(texto_oled, "%0.3d", lectura);
	
	salida_oled(x,y,texto_oled, font);
	
	return lectura;
}

int Compluino_03::escribe_oled_brujula(int x, int y, int font)
{
	//Escribe la lectura de la brújula en el display OLED
	static int longitud_anterior = 0;
	int lectura;
	int longitud;
	
	lectura = lee_brujula();
	
	sprintf(texto_oled, "%0.3d", lectura);
	longitud = strlen(texto_oled);
	
	if(longitud < longitud_anterior)
		salida_oled(x,y,"    ", font);
	
	longitud_anterior = longitud;

	salida_oled(x,y,texto_oled, font);
	
	return lectura;
}

void Compluino_03::escribe_oled_int(int x, int y, int valor)
{
	//Escribe un valor entero, con signo, en el display OLED
	static int longitud_anterior = 0;
	int longitud;
	
	sprintf(texto_oled, "%0.5d", valor);
	longitud = strlen(texto_oled);
	
	if(longitud < longitud_anterior)
		escribe_oled(x, y, "      ");
	
	longitud_anterior = longitud;

	escribe_oled(x, y, texto_oled);
}

void Compluino_03::salida_oled(int x, int y, char *salida, int font)
{
	if (font == T_NORMAL)
		escribe_oled(x, y, salida);
	else
		escribe_2x_oled(x, y, salida);
}

//
// Funciones para el control del altavoz piezoeléctrico
//

void Compluino_03::beep()
{
	tone(PIN_ALTAVOZ, 1000);
	delay(200);
	noTone(PIN_ALTAVOZ);
}

void Compluino_03::doble_beep()
{
	beep();
	delay(50);
	beep();
	delay(50);
}

void Compluino_03::enciende_altavoz(int frecuencia)
{
	tone(PIN_ALTAVOZ,frecuencia);
}

void Compluino_03::apaga_altavoz(void)
{
	noTone(PIN_ALTAVOZ);
}

//
// Funciones para la lectura de sensores
//

int Compluino_03::lee_sensor(int ref_sensor)
{
	int lectura;
	
	switch(ref_sensor)
	{
		case REF_POT:
			lectura = lee_pot(0,100);
			break;
			
		case REF_LDR:
			lectura = lee_ldr(0,100);
			break;
			
		case REF_PULSADOR:
			lectura = lee_pulsador();
			break;
			
		case REF_SUELO_D:
			lectura = lee_suelo_d(0,100);
			break;
			
		case REF_SUELO_I:
			lectura = lee_suelo_i(0,100);
			break;
			
		case REF_SUELO_DD:
			lectura = lee_suelo_dd();
			break;
			
		case REF_SUELO_ID:
			lectura = lee_suelo_id();
			break;
			
		case REF_DISTANCIA:
			lectura = lee_distancia(SI);
			break;
			
		case REF_BRUJULA:
			lectura = lee_brujula();
			break;
			
		default:
			lectura = 0;
	}
	
	return lectura;
}

int Compluino_03::lee_pot(int min, int max)
{
	return map(analogRead(PIN_POT), 0, 1020, min, max);
}

int Compluino_03::lee_ldr(int min, int max)
{
	return map(analogRead(PIN_LDR), 0, 1020, min, max);
}

int Compluino_03::lee_pulsador(void)
{
	return estado_pulsador();
}

int Compluino_03::lee_suelo_d(int min, int max)
{
	return map(analogRead(PIN_SUELO_D), 0, 1020, min, max);
}

int Compluino_03::lee_suelo_i(int min, int max)
{
	return map(analogRead(PIN_SUELO_I), 0, 1020, min, max);
}

int Compluino_03::lee_suelo_dd()
{
	return digitalRead(PIN_SUELO_DD);
}

int Compluino_03::lee_suelo_id()
{
	return digitalRead(PIN_SUELO_ID);
}

int Compluino_03::lee_distancia(int led)
{
	int medida;
  
	if (led)
		digitalWrite(LED, HIGH);
	
	//Realizamos medida del sensor de US
	//Generamos pulso de emision
	pinMode(PIN_US, OUTPUT);
	digitalWrite(PIN_US, LOW);
	delayMicroseconds(10);
	digitalWrite(PIN_US, HIGH);
	delayMicroseconds(10);
	digitalWrite(PIN_US,LOW);
	pinMode(PIN_US,INPUT);

	// Medimos en cm, como máximo 255 cm
	medida = pulseIn(PIN_US, HIGH, 20000) / 58;

	// Ajustamos la medida al rango máximo
	if (medida > 255)
		medida = 255;
  
	//El ultrasonidos devuelve un 0 cuando no se recibe ningun eco 
	//Cuando esto ocurre lo tratamos como rango maximo
	if (medida == 0)
		medida = 255;
  
	if (led)
		digitalWrite(LED, LOW);
   
	return medida;
}

//
// Funciones para el control del pulsador
//

void Compluino_03::espera_pulsador(void)
{
	while(estado_pulsador());
	delay(50);
	espera_pulsador_soltar();
	delay(50);
}

void Compluino_03::espera_pulsador_mensaje(void)
{
	u8x8.clear();
	
	u8x8.drawString(2, 6, "Pulsar ->");
	
	espera_pulsador();
	
	u8x8.clear();
}

void Compluino_03::espera_pulsador_soltar(void)
{
	while (!estado_pulsador());
}

int Compluino_03::estado_pulsador(void)
{
	return !digitalRead(PIN_PULSADOR);
}

//
// Funciones para el control de los ledes
//

void Compluino_03::enciende(int led)
{
	switch(led)
	{
		case LED:
			digitalWrite(led, HIGH);
			break;
			
		case RGB:
			digitalWrite(PIN_RGB_ROJO, HIGH);
			digitalWrite(PIN_RGB_VERDE, HIGH);
			digitalWrite(PIN_RGB_AZUL, HIGH);
			break;
			
		case RGB_NEGRO:
			digitalWrite(PIN_RGB_ROJO, LOW);
			digitalWrite(PIN_RGB_VERDE, LOW);
			digitalWrite(PIN_RGB_AZUL, LOW);
			break;
			
		case RGB_ROJO:
			digitalWrite(PIN_RGB_ROJO, HIGH);
			digitalWrite(PIN_RGB_VERDE, LOW);
			digitalWrite(PIN_RGB_AZUL, LOW);
			break;
		
		case RGB_VERDE:
			digitalWrite(PIN_RGB_ROJO, LOW);
			digitalWrite(PIN_RGB_VERDE, HIGH);
			digitalWrite(PIN_RGB_AZUL, LOW);
			break;
			
		case RGB_AZUL:
			digitalWrite(PIN_RGB_ROJO, LOW);
			digitalWrite(PIN_RGB_VERDE, LOW);
			digitalWrite(PIN_RGB_AZUL, HIGH);
			break;
			
		case RGB_MAGENTA:
			digitalWrite(PIN_RGB_ROJO, HIGH);
			digitalWrite(PIN_RGB_VERDE, LOW);
			digitalWrite(PIN_RGB_AZUL, HIGH);
			break;
			
		case RGB_CIAN:
			digitalWrite(PIN_RGB_ROJO, LOW);
			digitalWrite(PIN_RGB_VERDE, HIGH);
			digitalWrite(PIN_RGB_AZUL, HIGH);
			break;
			
		case RGB_AMARILLO:
			digitalWrite(PIN_RGB_ROJO, HIGH);
			digitalWrite(PIN_RGB_VERDE, HIGH);
			digitalWrite(PIN_RGB_AZUL, LOW);
			break;
			
		case RGB_BLANCO:
			digitalWrite(PIN_RGB_ROJO, HIGH);
			digitalWrite(PIN_RGB_VERDE, HIGH);
			digitalWrite(PIN_RGB_AZUL, HIGH);
			break;
	}
}

void Compluino_03::apaga(int led)
{
	switch(led)
	{
		case LED:
			digitalWrite(led, LOW);
			break;
			
		case RGB:
			digitalWrite(PIN_RGB_ROJO, LOW);
			digitalWrite(PIN_RGB_VERDE, LOW);
			digitalWrite(PIN_RGB_AZUL, LOW);
			break;
	}
}

void Compluino_03::brillo_rgb(int rojo, int verde, int azul)
{
	rojo = constrain(rojo, 0, 100);
    rojo = map(rojo, 0, 100, 0, 255);
	verde = constrain(verde, 0, 100);
    verde = map(verde, 0, 100, 0, 255);
	azul = constrain(azul, 0, 100);
    azul = map(azul, 0, 100, 0, 255);
	analogWrite(PIN_RGB_ROJO,rojo);
	analogWrite(PIN_RGB_VERDE,verde);
	analogWrite(PIN_RGB_AZUL,azul);
}

//
// Funciones de la brújula (Compass)
//

int Compluino_03::inicia_brujula(void)
{
	if (!compass.begin())
		return false;

    if(compass.isHMC())
	{
        compass.setRange(HMC5883L_RANGE_1_3GA);
        compass.setMeasurementMode(HMC5883L_CONTINOUS);
        compass.setDataRate(HMC5883L_DATARATE_15HZ);
        compass.setSamples(HMC5883L_SAMPLES_8);
    }
   else if(compass.isQMC())
   {
        compass.setRange(QMC5883_RANGE_2GA);
        compass.setMeasurementMode(QMC5883_CONTINOUS); 
        compass.setDataRate(QMC5883_DATARATE_50HZ);
        compass.setSamples(QMC5883_SAMPLES_8);
   }
    
   _angulo_referencia = brujula_absoluta();
   
   return true;
   
}

int Compluino_03::lee_brujula(void)
{
	int angulo_absoluto,orienta;

	angulo_absoluto = brujula_absoluta();
  
	if (angulo_absoluto < _angulo_referencia)
		orienta = 360 - abs(angulo_absoluto - _angulo_referencia);
	else
		orienta = angulo_absoluto - _angulo_referencia;

	if (orienta > 180)
		orienta = orienta - 360;

	return (orienta);
}

int Compluino_03::brujula_absoluta(void)
{
	#define PROMEDIOS 4
	int conta = 0, acumula = 0;
	
	float declinationAngle = (4.0 + (26.0 / 60.0)) / (180 / PI);
    
	
	for (conta = 0; conta < PROMEDIOS; conta++)
	{
	
		Vector norm = compass.readNormalize();
		float heading = atan2(norm.YAxis, norm.XAxis);
	
		heading += declinationAngle;
	
		if (heading < 0)
		{
			heading += 2 * PI;
		}

		if (heading > 2 * PI)
		{
			heading -= 2 * PI;
		}
	
		float headingDegrees = heading * 180/M_PI;
		
		acumula+=headingDegrees; 
	}
	 acumula /= PROMEDIOS;
	 
	 return acumula;
	
}

Calibra Compluino_03::obtener_offset(void)
{
	Vector b;
	static Calibra o;
	
	if(compass.isHMC_)
	{
		
		b.XAxis = compass.readRegister16(HMC5883L_REG_OUT_X_M);
		b.YAxis = compass.readRegister16(HMC5883L_REG_OUT_Y_M);
		b.ZAxis = compass.readRegister16(HMC5883L_REG_OUT_Z_M);
			
		if(b.XAxis < o.minX ) o.minX = b.XAxis;
		if(b.XAxis > o.maxX ) o.maxX = b.XAxis;
		if(b.YAxis < o.minY ) o.minY = b.YAxis;
		if(b.YAxis > o.maxY ) o.maxY = b.YAxis;
		if(b.ZAxis < o.minZ ) o.minZ = b.ZAxis;
		if(b.ZAxis > o.maxZ ) o.maxZ = b.ZAxis;
	
	}
	else if(compass.isQMC_)
	{
		b.XAxis = compass.readRegister16(QMC5883_REG_OUT_X_M);
		b.YAxis = compass.readRegister16(QMC5883_REG_OUT_Y_M);
		b.ZAxis = compass.readRegister16(QMC5883_REG_OUT_Z_M);
			
		if(b.XAxis < o.minX ) o.minX = b.XAxis;
		if(b.XAxis > o.maxX ) o.maxX = b.XAxis;
		if(b.YAxis < o.minY ) o.minY = b.YAxis;
		if(b.YAxis > o.maxY ) o.maxY = b.YAxis;
		if(b.ZAxis < o.minZ ) o.minZ = b.ZAxis;
		if(b.ZAxis > o.maxZ ) o.maxZ = b.ZAxis;
		
  }
  return o;
	/*	
	if (!_brujula_conectada)
	{
		error_brujula();
		while(true);
	}
	
	int minX = 0;
	int maxX = 0;
	int minY = 0;
	int maxY = 0;
	int offX = 0;
	int offY = 0;
	unsigned long tiempo = millis();
	Vector mag;
	
	escribe_oled(0, 0, "Calibra brujula");
	escribe_oled(1, 3, "OffX:");
	escribe_oled(1, 5, "OffY:");
	
	gira_derecha(70);

	while ((millis() - tiempo) < 10000)
	{
		mag = brujula_robot.readRaw();

		// Determine Min / Max values
		if (mag.XAxis < minX) minX = mag.XAxis;
		if (mag.XAxis > maxX) maxX = mag.XAxis;
		if (mag.YAxis < minY) minY = mag.YAxis;
		if (mag.YAxis > maxY) maxY = mag.YAxis;

		// Calculate offsets
		offX = (maxX + minX) / 2;
		offY = (maxY + minY) / 2;

		escribe_oled_int(8, 3, offX);
		escribe_oled_int(8, 5, offY);

		delay(10);
	}

	para();
	beep();

	escribe_oled (1, 7, "Guardar? -->");

	espera_pulsador();

	//Guardamos en la EEPROM los valores del offset de la brujula
	EEPROM.put(20, offX);
	EEPROM.put(22, offY);

	beep();
	borra_oled();

	escribe_oled (1, 0, "Offsets de la");
	escribe_oled (1, 1, "   brujula");
	escribe_oled (1, 2, "guardados en");
	escribe_oled (1, 3, " la EEPROM");*/
}

void Compluino_03::error_brujula(void)
{
	enciende(RGB_ROJO);
	escribe_oled(1, 1, "Error iniciando");
	escribe_oled(5, 3, "Brujula");
	escribe_oled(5, 5, "HMC5883L");
}

//
// Funciones de espera
//

void Compluino_03::espera_segundos(int segundos)
{
	delay(segundos*1000);
}

void Compluino_03::espera_milisegundos(int milisegundos)
{
	delay(milisegundos);
}

//
// Funciones para el control del servo
//

void Compluino_03::pos_servo (int grados)
{
	grados = constrain(grados, 0, 180);
		if (servo_robot.attached() == TRUE)
		{
			servo_robot.write (grados);
		}
		else
		{
			servo_robot.attach (PIN_SERVO);
			servo_robot.write (grados);
		}
}

int Compluino_03::lee_pos_servo ()
{
	return (servo_robot.read());
}

/* Funciones para el Bluetooth --------------------------------------------------------------*/
void Compluino_03::configura_bluetooth (String nombre)
{
  String robot = String("AT+NAME=") + nombre + String("\r\n"); 
  Serial.begin(38400); // Inicializamos  el puerto serie 
  escribe_oled(0,0,"Pulsa para");
  escribe_oled(0,2,"Comenzar");
  escribe_oled(13,7,"-->");
  espera_pulsador();
  borra_oled();  
  Serial.print("AT\r\n");
  delay(1000);
  escribe_oled (1, 1, "Configurando");
  escribe_oled (1, 2, "nombre");
  while (Serial.available()) 
  {  
   Serial.read();
   enciende(PIN_RGB_AZUL);
  }
  Serial.print(robot);
  delay(2000);
    escribe_oled (1, 1, "Configurando");
  escribe_oled (1, 2, "velocidad");
  while (Serial.available()) 
  {  
   Serial.read();
   enciende(RGB_VERDE);
  }
  Serial.print("AT+UART=9600,0,0\r\n");
  delay(2000);
  escribe_oled (1, 1, "Configuracion");
  escribe_oled (1, 2, "finalizada");
  while (Serial.available()) 
  {  
   Serial.read();
   apaga(RGB);
  }
  Serial.print("AT+INIT\r\n");
  delay(2000);
}



