/* 
 * 1 - Programa de ejemplo de fork() 
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


/*
 * Programa principal: crear un proceso hijo que escriba su id en pantalla, espere 5 segundos y finalice con un exit (33).
 * El proceso padre espera un segundo, escribe su id, el de su hijo y espera que el hijo termine. Escribe en pantalla el valor de exit del hijo.
 */
main() {
	/* Identificador del proceso creado */
	pid_t idProceso;

	/* Variable para comprobar que se copia inicialmente en cada proceso y que luego puede cambiarse independientemente en cada uno de ellos. */
	int variable = 1;

	/* Estado del hijo */
	int estadoHijo;

	/* Se crea el proceso hijo. En alg�n sitio dentro del fork(), nuestro programa se duplica en dos procesos. Cada proceso obtendr� una salida distinta. */
	idProceso = fork();

	/* Si fork() devuelve -1, es que hay un error y no se ha podido crear el proceso hijo. */
	if (idProceso == -1) {
		perror ("No es posible crear proceso");
		exit (-1);
	}

	/* fork() devuelve 0 al proceso hijo.*/
	if (idProceso == 0)
	{
		/* El hijo escribe su pid en pantalla y el valor de variable */
		printf ("==> HiloHijo: Mi pid es %d. El PID de mi padre es %d\n", getpid(), getppid());

		/* Escribe valor de variable y la cambia */
		printf ("==> HiloHijo: variable = %d. Modifico variable = 2\n", variable);
		variable = 2;
		
		/* Espera 5 segundos, saca en pantalla el valor de variable y sale */
		sleep (5);
		printf ("==> HiloHijo: variable = %d,\n FINALIZO \n", variable);
		exit (33);
	}

	/* fork() devuelve un n�mero positivo al padre. Este n�mero es el id del hijo. */
	if (idProceso > 0)
	{
		/* Espera un segundo (para dar tiempo al hijo a hacer sus cosas y no entremezclar salida en la pantalla) y escribe su pid y el de su hijo */
		sleep (1);
		printf ("==> PPadre: Mi pid es %d. El pid de HiloHijo es %d\n", getpid(), idProceso);

		/* Espera que el hijo muera */
		wait (&estadoHijo);

		/* Comprueba la salida del hijo */
		if (WIFEXITED(estadoHijo) != 0)
		{
			printf ("==> PPadre: HiloHijo ha finalizado. Devuelve %d\n", WEXITSTATUS(estadoHijo));
		}

		/* Escribe el valor de variable, que mantiene su valor original */
		printf ("==> PPadre: variable = %d\n", variable);
	}
}
