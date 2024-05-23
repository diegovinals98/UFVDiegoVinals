/*
Compluino_03_oop.h - Library for Compluino_03 robot. 
 * \class   Compluino_03_oop
 * \brief   Driver for ATMega328p, arduino.
 * @file    Compluino_03.h
 * @author  Complubot - www.complubot.com
 * @version V1.0
 * @date    2017/05/25
 * @brief   Header for Compluino_03.cpp module.
*/

#ifndef Compluino_03_h
#define Compluino_03_h

/* Includes ------------------------------------------------------------------*/
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <U8x8lib.h>
#include <Wire.h>
#include <Servo.h>
//#include <HMC5883L.h>
#include <EEPROM.h>
#include <Compluino_QMC5883.h>

// Definición de pines
#define PIN_SERVO 2				// Control de servos de RC
#define PIN_PULSADOR 3			// Pulsador de usuario
#define PIN_EN 4				// Habilitación de los motores
#define PIN_MOTOR_D 5			// PWM motor derecho
#define PIN_MOTOR_I 6			// PWM motor izquierdo
#define PIN_US 7				// Sensor de distancias ultrasonidos HC-SR04. Configuración un pin
#define PIN_ALTAVOZ 8			// Altavoz piezoeléctrico (pasivo)
#define PIN_RGB_ROJO 9			// Color rojo del led RGB
#define PIN_RGB_AZUL 10			// Color azul del led RGB
#define PIN_RGB_VERDE 11		// Color verde del led RGB
#define PIN_MISO 12				// Pin MISO (1) del conector ICSP (CMUCAM)
#define PIN_LED 13				// Led azul
#define PIN_SUELO_DD 16		// Sensor reflexivo derecho, en digital
#define PIN_SUELO_ID 17		// Sensor reflexivo izquierdo, en digital
#define PIN_POT A0				// Potenciometro
#define PIN_LDR A1				// Sensor de luz LDR
#define PIN_SUELO_D A2			// Sensor reflexivo de suelo derecho, en analógivo
#define PIN_SUELO_I A3			// Sensor reflexivo de suelo izquierdo, en analógivo

// Referencias de sensores
#define REF_POT 100				// Referencia al potenciómetro
#define REF_LDR 101				// Referencia al sensor de luz LDR
#define REF_PULSADOR 102		// Referencia al pulsador de usuario
#define REF_SUELO_D 103			// Referencia al sensor reflexivo de suelo derecho
#define REF_SUELO_I 104			// Referencia al sensor reflexivo de suelo izquierdo
#define REF_SUELO_DD 105		// Referencia al sensor reflexivo de suelo derecho en digital
#define REF_SUELO_ID 106		// Referencia al sensor reflexivo de suelo izquierdo en digital
#define REF_DISTANCIA 107		// Referencia al sensor de distancias HC-SR04
#define REF_BRUJULA 108			// Referencia al sensor de orientación HMC5883L (brújula electrónica)

// Tamaño de fuente del display OLED
#define T_NORMAL 0
#define T_GRANDE 1

// Estados del pulsador
#define PULSADO 0
#define NO_PULSADO 1

// Colores led RGB
#define RGB	200
#define RGB_NEGRO 201
#define RGB_ROJO 202
#define RGB_VERDE 203
#define RGB_AZUL 204
#define RGB_MAGENTA 205
#define RGB_CIAN 206
#define RGB_AMARILLO 207
#define RGB_BLANCO 208

#define LED PIN_LED

// Colores detectados por los sensores reflexivos en formato digital
#define BLANCO 0
#define NEGRO 1

// Notas musicales de la cuarta octava
#define DO4 262
#define RE4 294
#define MI4 330
#define FA4 349
#define SOL4 392
#define LA4 440
#define SI4 494

// Estados de las variables de confirmacion
#define FALSE 0
#define TRUE 1
#define NO 0
#define SI 1

//Posiciones EEPROM
#define ADD_NOMBRE 0
#define ADD_BRUJULA 20

 /*
 * Clase: Compluino_03
 * Declaracion de Clase Compluino_03
 */
class Compluino_03 //public Compluino_03
{
	public: 
  
		/*
		* Constructor
		*/
		Compluino_03 (void);

		/*
		* Función: inicia
		*   
		* Descripcion: Configura los puertos del Compluino_03, activa ledes, altavoz y muestra mensaje de bienvenida 
		*   
		* Parámetros: ninguno
		*   
		* Retorna: nada
		*/
		void inicia(void);

		//
		// Funciones para el control del movimiento del robot
		//

		/*
		* Función: para
		*   
		* Descripcion: Detiene el movimiento del robot
		*   
		* Parámetros: ninguno
		*   
		* Retorna: nada
		*/
		void para(void);

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
		void avanza(int vel);

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
		void retrocede(int vel);

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
		void mueve(int vel);

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
		void gira_derecha(int vel);

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
		void gira_izquierda(int vel);

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
		void gira(int vel);

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
		void mueve_motor(int pin_pwm, int vel);

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
		void borra_oled(void);

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
		void escribe_oled(int x, int y, char *texto);

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
		void escribe_2x_oled(int x, int y, char *texto);

		/**
		* \par Funcion
		*   escribe_oled_sensor
		* \par Descripcion
		*   Muestra por pantalla la lectura del sensor analogico indicado
		* \param[in]
		*   x: coordenada x de la pantalla donde aparecera el texto
		*	y: coordenada y de la pantalla donde aparecera el texto
		* font:selecciona el tamaño de la fuente. T_NORMAL, T_GRANDE
		* sensor: selecciona el sensor al que tomar medidas.
			SENSOR_D:sensor reflexivo derecha
			SENSOR_I:sensor reflexivo izquierda
			LDR: sensor de luz
		* \par Output
		*   Ninguno
		* \return
		*   Devuelve la medida del sensor indicado
		* \par Others
		*   Ninguno
		*/
		int escribe_oled_sensor(int x, int y, int font, int ref_sensor);

		/**
		* \par Funcion
		*   escribe_oled_pot
		* \par Descripcion
		*   Muestra por pantalla la medida del potenciometro
		* \param[in]
		*   x: coordenada x de la pantalla donde aparecera el texto
			y: coordenada y de la pantalla donde aparecera el texto
			font:selecciona el tamaño de la fuente. T_NORMAL, T_GRANDE
		* \par Output
		*   Ninguno
		* \return
		*   Devuelve el valor del potenciometro
		* \par Others
		*   Ninguno
		*/
		int escribe_oled_pot(int x, int y, int font, int min, int max);

		int escribe_oled_ldr(int x, int y, int font, int min, int max);

		int escribe_oled_pulsador(int x, int y, int font);

		int escribe_oled_suelo_d(int x, int y, int font, int min, int max);

		int escribe_oled_suelo_i(int x, int y, int font, int min, int max);

		int escribe_oled_suelo_dd(int x, int y, int font);

		int escribe_oled_suelo_id(int x, int y, int font);

		/**
		* \par Funcion
		*   escribe_oled_distancia
		* \par Descripcion
		*   Muestra por pantalla la medida del sensor de ultrasonidos
		* \param[in]
		*   x: coordenada x de la pantalla donde aparecera el texto
			y: coordenada y de la pantalla donde aparecera el texto
			font:selecciona el tamaño de la fuente. T_NORMAL, T_GRANDE
		* \par Output
		*   Ninguno
		* \return
		*   Devuelve la medida del sensor de distancias
		* \par Others
		*   Ninguno
		*/
		int escribe_oled_distancia(int x, int y, int font, int led);

		int escribe_oled_brujula(int x, int y, int font);

		/**
		* \par Funcion
		*   escribe_lectura_int
		* \par Descripcion
		*   Muestra por pantalla la lectura del sensor requerido
		* \param[in]
		*   x: coordenada x de la pantalla donde aparecera el texto
			y: coordenada y de la pantalla donde aparecera el texto
			valor: dato que se quiera mostrar por la pantalla oled
		* \par Output
		*   Ninguno
		* \return
		*   Ninguno
		* \par Others
		*   Ninguno
		*/
		void escribe_oled_int(int x, int y, int valor);

		void salida_oled(int x, int y, char *salida, int font);

		//
		// Funciones para el control del altavoz piezoeléctrico
		//

		/**
		* \par Funcion
		*   beep
		* \par Descripcion
		*   Hace sonar un pitido por el zumbador
		* \param[in]
		*   Ninguno
		* \par Output
		*   Ninguno
		* \return
		*   Ninguno
		* \par Others
		*   Ninguno
		*/
		void beep(void);

		/**
		* \par Funcion
		*   beep
		* \par Descripcion
		*   Hace sonar un doble pitido por el zumbador
		* \param[in]
		*   Ninguno
		* \par Output
		*   Ninguno
		* \return
		*   Ninguno
		* \par Others
		*   Ninguno
		*/
		void doble_beep(void);

		/**
		* \par Funcion
		*   enciende_zumbador
		* \par Descripcion
		*   Hace sonar el zumbador a la frecuencia indicada
		* \param[in]
		*   frecuencia: frecuencia del tono seleccionado
		* \par Output
		*   Ninguno
		* \return
		*   Ninguno
		* \par Others
		*   Ninguno
		*/
		void enciende_altavoz(int frecuencia);

		/**
		* \par Funcion
		*   apaga_zumbador
		* \par Descripcion
		*   Apaga el zumbador
		* \param[in]
		*   Ninguno
		* \par Output
		*   Ninguno
		* \return
		*   Ninguno
		* \par Others
		*   Ninguno
		*/
		void apaga_altavoz(void);

		//
		// Funciones para la lectura de sensores
		//

		/**
		* \par Funcion
		*   lee_pot
		* \par Descripcion
		*   Lee la posicion a la que se encuentra el potenciometro
		* \param[in]
		*   min:el valor minimo del rango de lectura del potenciometro
			max:el valor maximo del rango de lectura del potenciometro
		* \par Output
		*   Ninguno
		* \return
		*   Devuelve el valor del potenciometro en el rango indicado
		* \par Others
		*   Ninguno
		*/
		int lee_pot(int min, int max);

		int lee_ldr(int min, int max);

		int lee_pulsador(void);

		int lee_suelo_d(int min, int max);

		int lee_suelo_i(int min, int max);

		int lee_suelo_dd(void);

		int lee_suelo_id(void);

		/* Funciones para el control del sensor de distancia HC-SR04 ------------------------------------------------------------------*/
		/**
		* \par Funcion
		*   mide_distancia
		* \par Descripcion
		*   Realiza medidas de distancia con el sensor de ultrasonidos
		* \param[in]
		*   Ninguno
		* \par Output
		*   Ninguno
		* \return
		*   Devuelve la distancia en centrimetros
		* \par Others
		*   Ninguno
		*/
		int lee_distancia(int led);

		/**
		* \par Funcion
		*   lee_sensor
		* \par Descripcion
		*   Lee los sensores reflexivos en formato analogico
		* \param[in]
		*   ref_sensor: selecciona el sensor al que tomar medidas.
			SENSOR_D:sensor reflexivo derecha
			SENSOR_I:sensor reflexivo izquierda
			LDR: sensor de luz
		* \par Output
		*   Ninguno
		* \return
		*   Devuelve el valor del sensor indicado
		* \par Others
		*   Ninguno
		*/
		int lee_sensor(int ref_sensor); //Lee sensores analogicos

		//
		// Funciones para el control del pulsador
		//

		/**
		* \par Funcion
		*   espera_pulsador
		* \par Descripcion
		*   Espera a que se apriete y se suelte el pulsador
		* \param[in]
		*   Ninguno
		* \par Output
		*   Ninguno
		* \return
		*   Ninguno
		* \par Others
		*   Ninguno
		*/
		void espera_pulsador(void);

		/**
		* \par Funcion
		*   espera_pulsador_mensaje
		* \par Descripcion
		*   Espera a que se apriete y se suelte el pulsador y te lo indica por la pantalla oled con el mensaje "Pulsar"
		* \param[in]
		*   Ninguno
		* \par Output
		*   Ninguno
		* \return
		*   Ninguno
		* \par Others
		*   Ninguno
		*/
		void espera_pulsador_mensaje(void);

		/**
		* \par Funcion
		*   espera_pulsador_soltar
		* \par Descripcion
		*   Espera a que el pulsador no este presionado
		* \param[in]
		*   Ninguno
		* \par Output
		*   Ninguno
		* \return
		*   Ninguno
		* \par Others
		*   Ninguno
		*/
		void espera_pulsador_soltar(void);

		/**
		* \par Funcion
		*   estado_pulsador
		* \par Descripcion
		*   Devuelve el estado del pulsador
		* \param[in]
		*   Ninguno
		* \par Output
		*   Ninguno
		* \return
		*   Devuelve un 0 cuando el pulsador esta presionado, devuelve un 1 cuando no esta presionado
		* \par Others
		*   Ninguno
		*/
		int estado_pulsador(void);

		//---------------------------------------------------------------------------------------------------
		/**
		* \par Funcion
		*   estado_sensor
		* \par Descripcion
		*   Lee el estado de los sensores reflexivos en formato digital
		* \param[in]
		*   sensor: selecciona el sensor al que tomar medidas.
			SENSOR_D:sensor reflexivo derecha
			SENSOR_I:sensor reflexivo izquierda
		* \par Output
		*   Ninguno
		* \return
		*   Estado del sensor: 0-Blanco, 1-Negro
		* \par Others
		*   Ninguno
		*/
		int estado_sensor(int sensor);
		//---------------------------------------------------------------------------------------------------

		//
		// Funciones para el control de los ledes
		//

		/**
		* \par Funcion
		*   enciende
		* \par Descripcion
		*   Enciende el led indicado
		* \param[in]
		*   led:selecciona el led a encender.
			LED: led indicador D10
			RGB: enciende los tres ledes del RGB
			RGB_NEGRO: apaga los tres ledes del RGB
			RGB_ROJO: enciende el led rojo del RGB
			RGB_VERDE: enciende el led verde del RGB
			RGB_AZUL: enciende el led azul del RGB
			RGB_MAGENTA: enciende el RGB en color magenta
			RGB_CIAN: enciende el RGB en color cian
			RGB_AMARILLO: enciende el RGB en color amarillo
			RGB_BLANCO: enciende el RGB en blanco
		* \par Output
		*   Ninguno
		* \return
		*   Ninguno
		* \par Others
		*   Ninguno
		*/
		void enciende(int led);

		/**
		* \par Funcion
		*   apaga
		* \par Descripcion
		*   Apaga el led indicado
		* \param[in]
		*   led: selecciona el led a apagar
			LED: led indicador D10
			RGB: apaga los tres ledes internos del RGB
		* \par Output
		*   Ninguno
		* \return
		*   Ninguno
		* \par Others
		*   Ninguno
		*/
		void apaga(int led);

		/**
		* \par Funcion
		*   brillo_rgb
		* \par Descripcion
		*   Controla la intensidad de cada uno de los tres ledes internos del rgb
		* \param[in]
		*    rojo: led rojo, de 0 a 100
		*    verde: led verde, de 0 a 100
		*    azul: led azul, de 0 a 100
		* \par Output
		*   Ninguno
		* \return
		*   Ninguno
		* \par Others
		*   Ninguno
		*/
		void brillo_rgb(int rojo, int verde, int azul);
		
		/* Funciones para la brujula ------------------------------------------------------------------*/
		/**
		* \par Funcion
		*   inicia_brujula
		* \par Descripcion
		*   Configura los parametros necesarios para la brujula
		* \param[in]
		*   Ninguno
		* \par Output
		*   Ninguno
		* \return
		*   Ninguno
		* \par Others
		*   Ninguno
		*/
		int inicia_brujula(void);

		/**
		* \par Funcion
		*   brujula
		* \par Descripcion
		*   Indica la posicion en la que se encuentre
		* \param[in]
		*   Ninguno
		* \par Output
		*   Ninguno
		* \return
		*   Posicion en grados
		* \par Others
		*   Ninguno
		*/
		int lee_brujula(void);

		/**
		* \par Funcion
		*   lee_brujula
		* \par Descripcion
		*   Calcula distintos parametros para calcular el angulo
		* \param[in]
		*   Ninguno
		* \par Output
		*   Ninguno
		* \return
		*   Correccion en grados
		* \par Others
		*   Ninguno
		*/
		int brujula_absoluta(void);
		
		Calibra obtener_offset(void);
		
		void Compluino_03::error_brujula(void);

		//
		// Funciones de espera
		//

		/**
		* \par Funcion
		*   espera_segundos
		* \par Descripcion
		*   Hace una espera de los segundos indicados
		* \param[in]
		*   segundos: cantidad de segundos que espera
		* \par Output
		*   Ninguno
		* \return
		*   Ninguno
		* \par Others
		*   Ninguno
		*/
		void espera_segundos(int segundos);

		/**
		* \par Funcion
		*   espera_milisegundos
		* \par Descripcion
		*   Hace una espera de los milisegundos indicados
		* \param[in]
		*   milisegundos: cantidad de milisegundos que espera
		* \par Output
		*   Ninguno
		* \return
		*   Ninguno
		* \par Others
		*   Ninguno
		*/
		void espera_milisegundos(int milisegundos);

		//
		// Funciones para el control del servo
		//

		/**
		* \par Funcion
		*   pos_servo
		* \par Descripcion
		*   Desplaza al servo a la posicion indicada
		* \param[in]
		*   grados: posicion angular a la que queremos desplazar el servo
		* \par Output
		*   Ninguno
		* \return
		*   Ninguno
		* \par Others
		*   Ninguno
		*/
		void pos_servo(int grados);			//desplaza el servo a esa posicion

		/**
		* \par Funcion
		*   lee_pos_servo
		* \par Descripcion
		*   Te indica la posicion en la que se encuentra el servo
		* \param[in]
		*   Ninguno
		* \par Output
		*   Ninguno
		* \return
		*   Devuelve la posicion en la que se encuentre el servo
		* \par Others
		*   Ninguno
		*/
		int lee_pos_servo(void);				//devuelve la posicion del servo


		/* Funciones para el Bluetooth --------------------------------------------------------------*/
		/**
		* \par Funcion
		*   configura_bluetooth
		* \par Descripcion
		*   Configura el modulo bluetooth con el nombre que se le indique
		* \param[in]
		*   nombre: nombre seleccionado, tipo string
		* \par Output
		*   Ninguno
		* \return
		*   Ninguno
		* \par Others
		*   Ninguno
		*/
		void configura_bluetooth(String nombre);				//configura el nombre del HC-05


	private:
		
		// Variables del display OLED
		char texto_oled[16];
		
		String sc;
	
		// Variables para la brujula
		//int minX = 0;
		//int maxX = 0;
		//int minY = 0;
		//int maxY = 0;
		//int offX = 0, offX_old = 0;
		//int offY = 0, offY_old = 0;
		//float declinationAngle = 0, angulo_dec = 0;
		//int referencia = 0, ref = 0;
		
		int _brujula_conectada = false;
		int _angulo_referencia=0;
		float _angulo_declinacion=0;

		// Funciones

 
};					//fin de la clase

#endif