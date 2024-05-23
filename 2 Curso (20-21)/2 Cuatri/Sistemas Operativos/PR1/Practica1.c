/* 
 * 1 - Practica 1
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <pthread.h>

#define MAX_CARACTERES 100
#define MAX_ITEMS 200000
#define ERROR_LECT_FICHERO 1

typedef struct {
	int movieID;
	char title[MAX_CARACTERES];
	char genres[MAX_CARACTERES];

} pelicula;

char linea[MAX_CARACTERES];
FILE *fich;
char *ptrtoken;
char *ptrtoken2;

char *ptr;

pelicula listadopeliculas[MAX_ITEMS];
int contador = 0;
char peliculasLinea[MAX_ITEMS][MAX_ITEMS];

char delim[] = "\"";
char delim2[] = ",";

int contadorCOMEDY = 0;










// void *funcion(int i){
// 	switch(i){
// 		case 1:
// 		    printf("Soy %d \treviso la categoria: ACTION\n" , i);
// 			break;
// 		case 2:
// 			printf("Soy %d \treviso la categoria: ADVENTURE\n", i);
// 			break;
// 		case 3:
// 			printf("Soy %d \treviso la categoria: ANIMATION\n", i);
// 			break;
// 		case 4:
// 			printf("Soy %d \treviso la categoria: CHILDRENS\n", i);
// 			break;
// 		case 5:
// 			printf("Soy %d \treviso la categoria: COMEDY\n" , i);
// 			break;
// 		case 6:
// 			printf("Soy %d \treviso la categoria: CRIME\n", i);
// 			break;
// 		case 7:
// 			printf("Soy %d \treviso la categoria: DOCUMENTARY\n", i);
// 			break;
// 		case 8:
// 			printf("Soy %d \treviso la categoria: DRAMA\n", i);
// 			break;	
// 		case 9:
// 			printf("Soy %d \treviso la categoria: FANTASY\n", i);
// 			break;
// 		case 10:
// 			printf("Soy %d \treviso la categoria: FILM-NOIR\n", i);
// 			break;
// 		case 11:
// 			printf("Soy %d \treviso la categoria: HORROR\n", i);
// 			break;
// 		case 12:
// 			printf("Soy %d \treviso la categoria: MUSICAL\n", i);
// 			break;
// 		case 13:
// 			printf("Soy %d \treviso la categoria: MYSTERY\n", i);
// 			break;	
// 		case 14:
// 			printf("Soy %d \treviso la categoria: ROMANCE\n", i);
// 			break;
// 		case 15:
// 			printf("Soy %d \treviso la categoria: SCI-FI\n", i);
// 			break;
// 		case 16:
// 			printf("Soy %d \treviso la categoria: THRILLER\n", i);
// 			break;
// 		case 17:
// 			printf("Soy %d \treviso la categoria: WAR\n", i);
// 			break;
// 		case 18:
// 			printf("Soy %d \treviso la categoria: WESTERN\n", i);
// 			break;	

// 	}
// }




void *funcionCOMEDY(pelicula lista[]){

	printf("Entra en la funcion COMEDY\n");
	for(int g = 0; g <= 197640 ; g++){
		// printf("entra en el for %d\n",g );
		//printf("Entra en el for\n");
		ptr = strtok(lista[g].genres , "|");
		//printf("'%s'\n", ptr);
		while(ptr != NULL){
			// printf("Entra en el while\n");
			if(!strcmp(ptr , "Comedy")){
				contadorCOMEDY++;
			}	
			ptr = strtok(NULL , "|");
		}
	}
	printf("Hay %d peliculas con genero COMEDY\n", contadorCOMEDY);

}

void *funcionACTION(pelicula lista[]){

	printf("Entra en la funcion ACTION\n");
	for(int g = 0; g <= 200000 ; g++){
		// printf("entra en el for %d\n",g );
		//printf("Entra en el for\n");
		ptr = strtok(lista[g].genres , "|");
		//printf("'%s'\n", ptr);
		while(ptr != NULL){
			// printf("Entra en el while\n");
			if(!strcmp(ptr , "Action")){
				contadorCOMEDY++;
			}	
			ptr = strtok(NULL , "|");
		}
	}
	printf("Hay %d peliculas con genero COMEDY\n", contadorCOMEDY);

}




/*
 * Programa principal: crear un proceso hijo que escriba su id en pantalla, espere 5 segundos y finalice con un exit (33).
 * El proceso padre espera un segundo, escribe su id, el de su hijo y espera que el hijo termine. Escribe en pantalla el valor de exit del hijo.
 */
int main() {



	fich = fopen("movies.csv" , "r");
	if(fich == NULL){
        printf("Error al abrir el archivo\n\n");
        exit(ERROR_LECT_FICHERO);
    } else {
        printf("Lectura de fichero correcta.\n");
         // Mientras que haya lieneas, coge cada linea y hace lo de dentro del while
        while(fgets(linea, 100,  fich)){

            // Por cada separacion (;) lo separa y lo almacena segun corresponda
        	//peliculasLinea[contador] = linea;
        	//strcpy(peliculasLinea[contador], linea);
        	//printf("%s\n", peliculasLinea[contador]);


            
            // if(ptrtoken == NULL){
            // 	ptrtoken2 = strtok(linea , delim2);
            // 	if(ptrtoken != NULL){
            //     	listadopeliculas[contador].movieID = strtol(ptrtoken2,NULL,10);
	           //      //strcpy(listadopeliculas[contador].movieID , ptrtoken);
	           //  }
	           //  if((ptrtoken = strtok(NULL, delim2)) != NULL){
	           //      strcpy(listadopeliculas[contador].title , ptrtoken2);
	                
	           //  } 
	           //  if((ptrtoken = strtok(NULL, delim2)) != NULL){
	           //      strcpy(listadopeliculas[contador].genres , ptrtoken2);
	           //  } 
            // }

     	
            int c2 = 0;
            int size = sizeof linea / sizeof *linea;
            for(int x = 0 ; x < size; x++){
            	//printf("%s\n", linea[x]);
            	
            	if(linea[x] == '"'){
            		c2 = 1;
            		
            	}
            	//printf("\n");
            }

            if(c2 == 1){
            	//printf("Entramos en la linea con Comillas\n");
            	ptrtoken = strtok(linea, delim);
            	if(ptrtoken != NULL){
	                listadopeliculas[contador].movieID = strtol(ptrtoken,NULL,10);
	                //strcpy(listadopeliculas[contador].movieID , ptrtoken);
	            }
	            if((ptrtoken = strtok(NULL, delim)) != NULL){
	                strcpy(listadopeliculas[contador].title , ptrtoken);
	                
	            } 
	            if((ptrtoken = strtok(NULL, delim)) != NULL){
	                strcpy(listadopeliculas[contador].genres , ptrtoken);
	            } 
	            //printf("Acabamos linea con comillas\n");
            }else{ // SOLO SI NO HAY COMILLAS EN LA LINEA
            	//printf("Entremos en la linea sin comillas\n");
            	ptrtoken2 = strtok(linea , delim2);
	        	if(ptrtoken2 != NULL){
	            	listadopeliculas[contador].movieID = strtol(ptrtoken2,NULL,10);
	                //strcpy(listadopeliculas[contador].movieID , ptrtoken);
	            }
	            if((ptrtoken2 = strtok(NULL, delim2)) != NULL){
	                strcpy(listadopeliculas[contador].title , ptrtoken2);
	                
	            } 
	            if((ptrtoken2 = strtok(NULL, delim2)) != NULL){
	                strcpy(listadopeliculas[contador].genres , ptrtoken2);
	            } 
	            //printf("Acabamos linea sin comillas\n");
            }
            
            contador++;
        }
    }
    // cerramos el archivo y si nos da error, lo imprimimos
    if(fclose(fich) != 0){
        printf("Error al cerrar el archivo.\n");
        exit(ERROR_LECT_FICHERO);
    }

    // int j = 0;
    // while(peliculasLinea){
    // 	ptrtoken = strtok(peliculasLinea[j], SEPARADOR1);
    // 	if(ptrtoken == NULL){

    // 	}
    // 	printf("%s\n", ptrtoken);
    // 	j++;
    // }
   	// printf("%s\n", peliculasLinea[2]);



    pthread_t idHilo1, idHilo2, idHilo3,idHilo4,idHilo5,idHilo6,idHilo7,idHilo8,idHilo9,idHilo10,idHilo11,idHilo12,idHilo13,idHilo14,idHilo15, idHilo16,idHilo17, idHilo18; 

	
	// pthread_create(&idHilo2, NULL, funcion, 2);
	// pthread_create(&idHilo3, NULL, funcion, 3);
	// pthread_create(&idHilo4, NULL, funcion, 4);
	// pthread_create(&idHilo5, NULL, funcion, 5);
	// pthread_create(&idHilo6, NULL, funcion, 6);
	// pthread_create(&idHilo7, NULL, funcion, 7);
	// pthread_create(&idHilo8, NULL, funcion, 8);
	// pthread_create(&idHilo9, NULL, funcion, 9);
	// pthread_create(&idHilo10, NULL, funcion, 10);
	// pthread_create(&idHilo11, NULL, funcion, 11);
	// pthread_create(&idHilo12, NULL, funcion, 12);
	// pthread_create(&idHilo13, NULL, funcion, 13);
	// pthread_create(&idHilo14, NULL, funcion, 14);
	// pthread_create(&idHilo15, NULL, funcion, 15);
	// pthread_create(&idHilo16, NULL, funcion, 16);
	// pthread_create(&idHilo17, NULL, funcion, 17);
	// pthread_create(&idHilo18, NULL, funcion, 18);

    // for(int i = 0 ; i < 20 ; i++){
    // 	printf("%d: ", listadopeliculas[contador].movieID);
    // 	printf("\t%s\n",listadopeliculas[i].title );
    // 	printf("\t%s\n",listadopeliculas[i].genres);
    // }


	/* Identificador del proceso creado */
	pid_t idProceso, idProceso1, idProceso2, idProceso3, idProceso4, idProceso5, idProceso6, idProceso7, idProceso8, idProceso9, idProceso10, idProceso11, idProceso12, idProceso13, idProceso14, idProceso15, idProceso16, idProceso17, idProceso18;

	/* Variable para comprobar que se copia inicialmente en cada proceso y que luego puede cambiarse independientemente en cada uno de ellos. */
	int variable = 1;

	/* Estado del hijo */
	int estadoHijo;

	/* Se crea el proceso hijo. En algún sitio dentro del fork(), nuestro programa se duplica en dos procesos. Cada proceso obtendrá una salida distinta. */
	idProceso = fork();

	/* Si fork() devuelve -1, es que hay un error y no se ha podido crear el proceso hijo. */
	if (idProceso == -1) {
		perror ("No es posible crear proceso");
		exit (-1);
	}

	/* fork() devuelve 0 al proceso hijo.*/
	if (idProceso == 0)
	{
		
		
	}

	/* fork() devuelve un número positivo al padre. Este número es el id del hijo. */
	if (idProceso > 0)
	{
		pthread_create(&idHilo1, NULL, funcionCOMEDY, listadopeliculas);
		pthread_create(&idHilo1, NULL, funcionACTION, listadopeliculas);
	}
	// 	idProceso1 = fork();
	// 	if (idProceso1 == 0)
	// 	{
	// 		printf("Soy el 2 = %d, hijo de %d, reviso la categoria: ADVENTURE\n", getpid(), getppid());
	// 	}
	// 	if(idProceso1 > 0){
	// 		idProceso2 = fork();
	// 		if(idProceso2 == 0){
	// 			printf("Soy el 3 = %d, hijo de %d, reviso la categoria: ANIMATION\n", getpid(), getppid());
	// 		}
	// 		if(idProceso2 > 0){
	// 			idProceso3 = fork();
	// 			if(idProceso3 == 0){
	// 				printf("Soy el 4 = %d, hijo de %d, reviso la categoria: CHILDRENS\n", getpid(), getppid());
	// 			}
	// 			if(idProceso3 > 0){
	// 				idProceso4 = fork();
	// 				if(idProceso4 ==  0){
	// 					printf("Soy el 5 = %d, hijo de %d, reviso la categoria: COMEDY\n", getpid(), getppid());
	// 				}
	// 				if(idProceso4 > 0){
	// 					idProceso5 = fork();
	// 					if(idProceso5 == 0){
	// 						printf("Soy el 6 = %d, hijo de %d, reviso la categoria: CRIME\n", getpid(), getppid());
	// 					}
	// 					if(idProceso5 > 0){
	// 						idProceso6 = fork();
	// 						if(idProceso6 == 0){
	// 							printf("Soy el 7 = %d, hijo de %d, reviso la categoria: DOCUMENTARY\n", getpid(), getppid());
	// 						}
	// 						if(idProceso6 > 0){
	// 							idProceso7 = fork();
	// 							if(idProceso7 == 0){
	// 								printf("Soy el 8 = %d, hijo de %d, reviso la categoria: DRAMA\n", getpid(), getppid());
	// 							}
	// 							if(idProceso7 > 0){
	// 								idProceso8 = fork();
	// 								if(idProceso8 == 0){
	// 									printf("Soy el 9 = %d, hijo de %d, reviso la categoria: FANTASY\n", getpid(), getppid());
	// 								}
	// 								if(idProceso8 > 0){
	// 									idProceso9 = fork();
	// 									if(idProceso9 == 0){
	// 										printf("Soy el 10 = %d, hijo de %d, reviso la categoria: FILM-NOIR\n", getpid(), getppid());
	// 									}
	// 									if(idProceso9 > 0){
	// 										idProceso10 = fork();
	// 										if(idProceso10 == 0){
	// 											printf("Soy el 11 = %d, hijo de %d, reviso la categoria: HORROR\n", getpid(), getppid());
	// 										}
	// 										if(idProceso10 > 0){
	// 											idProceso11 = fork();
	// 											if(idProceso11 == 0){
	// 												printf("Soy el 12 = %d, hijo de %d, reviso la categoria: MUSICAL\n", getpid(), getppid());
	// 											}
	// 											if(idProceso11 > 0){
	// 												idProceso12 = fork();
	// 												if(idProceso12 == 0){
	// 													printf("Soy el 13 = %d, hijo de %d, reviso la categoria: MISTERY\n", getpid(), getppid());
	// 												}
	// 												if(idProceso12 > 0){
	// 													idProceso13 = fork();
	// 													if(idProceso13 == 0){
	// 														printf("Soy el 14 = %d, hijo de %d, reviso la categoria: ROMANCE\n", getpid(), getppid());
	// 													} 
	// 													if(idProceso13 > 0){
	// 														idProceso14 = fork();
	// 														if(idProceso14 == 0){
	// 															printf("Soy el 15 = %d, hijo de %d, reviso la categoria: SCI-FI\n", getpid(), getppid());
	// 														}
	// 														if(idProceso14 > 0){
	// 															idProceso15 = fork();
	// 															if(idProceso15 == 0){
	// 																printf("Soy el 16 = %d, hijo de %d, reviso la categoria: THRILLER\n", getpid(), getppid());
	// 															}
	// 															if(idProceso15 > 0){
	// 																idProceso16 = fork();
	// 																if(idProceso16 == 0){
	// 																	printf("Soy el 17 = %d, hijo de %d, reviso la categoria: WAR\n", getpid(), getppid());
	// 																}
	// 																if(idProceso16> 0){
	// 																	idProceso17 = fork();
	// 																	if(idProceso17 == 0){
	// 																		printf("Soy el 18 = %d, hijo de %d, reviso la categoria: WESTERN\n", getpid(), getppid());
	// 																	}
	// 																	if(idProceso17 > 0){
	// 																		idProceso18 = fork();
	// 																		if(idProceso18 == 0){
																				
	// 																		}
	// 																		if(idProceso18 > 0){

	// 																		}
	// 																	}
	// 																}
	// 															}
	// 														}
	// 													}
	// 												}
	// 											}
	// 										}
	// 									}
	// 								}
	// 							}
	// 						}
	// 					}
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	
	
	
}








