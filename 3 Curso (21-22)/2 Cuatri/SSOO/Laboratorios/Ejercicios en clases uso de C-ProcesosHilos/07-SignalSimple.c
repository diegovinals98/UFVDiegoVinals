#include <signal.h>
#include <unistd.h>
#include <stdio.h>

/*
 * Controlador para la se�al de ctrl-c
 */
void controlaSignal (int);

/*
 * Cambia el controlador para la se�al de ctrl-c y se mete en un bucle infinito de espera
 */
main()
{
	/* Se cambia el controlador para ctrl-c, escribiendo error en pantalla si lo hay. */
	if (signal(SIGINT, controlaSignal) == SIG_ERR)
	{
		perror ("No es posible modificar Signal");
	}

	/* Bucle infinito de espera. pause() deja el proceso dormido hasta que llegue una se�al. */
	while (1)
		sleep(10);
		
}

/*
 * Controlador para ctrl-c. Indica en pantalla que no se quiere salir y pone el controlador por defecto para ctrl-c. La segunda vez que se pulse ctrl-c, el programa se saldr� normalmente.
 */
void controlaSignal (int numeroSenhal)
{
	printf("\n Estas seguro que quieres dejarme? \n");
	printf("\n Vuelve a intentarlo... \n");

	/* Se pone controlador por defecto para ctrl-c */
	signal(SIGINT, SIG_DFL);
}
