#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void procesaSenial (int);


/* 
 * Crea un proceso hijo y le envía una señal SIGUSR1 cada segundo.
 */
main()
{
	/* Identificador del proceso hijo */
	pid_t idProceso;

	/* Se crea el proceso hijo y se comprueba el error */
	idProceso = fork();

	if (idProceso == -1)
	{
		perror ("No se puede lanzar proceso");
		exit (-1);
	}

	/* Camino que sigue el proceso hijo. Pone trataSenhal() para tratar la señal SIGUSR1 y se mete en un bucle de espera */
	if (idProceso == 0)
	{
		signal (SIGUSR1, procesaSenial);
		while (1)
			pause ();
	}

	/* Camino que sigue el proceso padre. Cada segundo envía una señal SIGUSR1 a su proceso hijo. */
	if (idProceso > 0)
	{
		while (1)
		{
			sleep (1);
			printf ("PAPA: Envío una señal a mi hijo \n");
			kill (idProceso, SIGUSR1);
		}
	}
}

/* Función de tratamiento de SIGUSR1. Escribe en pantalla un aviso de que ha llegado la señal. */
void procesaSenial (int numeroSenhal)
{
	printf ("==> HIJO: he recibido la señal de Papá \n");
}
