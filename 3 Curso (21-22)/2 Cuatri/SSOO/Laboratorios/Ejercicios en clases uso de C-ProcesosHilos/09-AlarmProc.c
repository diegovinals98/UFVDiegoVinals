#include <signal.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

/* Función para tratamiento de la señal SIGALRM */
void procesaSenial (int);

/* Pone un contador de tiempo que salta la primera vez a los dos segundos y luego cada medio segundo. */
main() {	
	
	/* Estructura con el contador de tiempo */
	struct itimerval contador;

	/* Valor inicial del contador */
	struct timeval tiempoInicial;

	/* Tiempo de repetición del contador */
	struct timeval tiempoRepeticion;

	/* Se rellena el tiempo inicial del contador con 2 segundos */
	tiempoInicial.tv_sec=2;
	tiempoInicial.tv_usec=0;

	/* Se rellena el tiempo de repetición con medio segundo */
	tiempoRepeticion.tv_sec=0;
	tiempoRepeticion.tv_usec=500000;

	/* Se rellenan los datos del contador */
	contador.it_value=tiempoInicial;
	contador.it_interval=tiempoRepeticion;
	
	/* Se cambia el tratamiento de la señal por defecto para que llame a
	 * nuestra función procesaSenial */
	signal (SIGALRM, procesaSenial);

	/* Se pone en marcha el contador.
	 * La primera vez tardará 2 segundos en saltar, según indicamos en
	 * tiempoInicial. Luego saltará automáticamente cada medio segundo, como
	 * indicamos en tiempoRepeticion. */
	setitimer (ITIMER_REAL, &contador, NULL);

	/* Bucle infinito con pause(). */
	while(1)
		sleep(100);
}

/* Tratamiento de la señal SIGALRM. Escribe en pantalla que ha llegado la señal */
void procesaSenial (int idSenhal) {
	printf ("==> Señal recibida \n");
}
