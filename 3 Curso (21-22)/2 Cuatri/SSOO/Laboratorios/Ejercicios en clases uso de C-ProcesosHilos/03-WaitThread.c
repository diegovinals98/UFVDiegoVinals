/*
 * Programa de ejemplo de threads.
 *
 * El programa principal crea un hilo y espera a que termine, recogiendo el valor que este devuelva.
 * El hilo creado espera 1 segundo y termina devolviendo la cadena de caracteres "Por fin"
 */
#include <pthread.h>
#include <stdio.h>

/* Prototipo de la función que va a ejecutar el thread hijo */
void *funcionThread (void *parametro);

/*
 * Lanza un thread para la función funcionThread.
 * Luego espera a que termine el thread y escribe en pantalla el valor que
 * este devuelve.
 */
main() {
	/* Identificador del thread hijo */
	pthread_t idHilo;

	/* Atributos para la creación del thread */	
	pthread_attr_t atributos;

	/* error devuelto por la función de creación del thread */
	int error;

	/* Valor que va a devolver el thread hijo */
	char *valorDevuelto = NULL;

	/* Inicializamos los atributos con sus valores por defecto */
	pthread_attr_init (&atributos);

	/* Aseguramos que el thread que vamos a poder esperar por el thread que
	 * vamos a crear. */
	pthread_attr_setdetachstate (&atributos, PTHREAD_CREATE_JOINABLE);

	/* Creamos el thread.
	 * En idHilo nos devuelve un identificador para el nuevo thread,
	 * Pasamos atributos del nuevo thread NULL para que los coja por defecto
	 * Pasamos la función que se ejecutará en el nuevo hilo
	 * Pasamos NULL como parámetro para esa función. */
	error = pthread_create (&idHilo, &atributos, funcionThread, NULL);

	/* Comprobamos el error al arrancar el thread */
	if (error != 0)
	{
		perror ("No es posible crear el thread");
		exit (-1);
	}

	/* El hilo principal espera al hilo hijo, indicándo por pantalla cuando empieza la espera y cuando termina. */
	printf ("Padre : Espero al thread\n");
	pthread_join (idHilo, (void **)&valorDevuelto);
	printf ("Padre : Ya ha terminado el Hijo\n");

	/* Se saca en pantalla el valor devuelto */
	printf ("Padre : el Hijo devuelve \"%s\"\n", valorDevuelto);
}

/* Funcion que se ejecuta en el thread hijo. Espera un segundo y termina devolviendo la cadena de caracteres "Por fin" */
void *funcionThread (void *parametro)
{
	/* El hijo espera un segundo y sale, indicando cuando empieza a esperar y cuando termina */
	int count = 5;
	printf ("==> Hijo: Inicio y espero 5 segundo\n");
	while (count >= 0){
		printf("==> Hijo: \%d\n", count);
		count--;
		sleep (1);	
	}
	printf ("==> Hijo: Termino\n");

	/* Termina el thread y devuelve una cadena "Ya tá" */
	pthread_exit ((void *)"Por fin");
}
