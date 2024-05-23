#include <signal.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <string.h>
#include <regex.h> 
#include <pthread.h>

#define SEPARADOR ","
#define MAX_CARACTERES 10000
#define ERROR_LECT_FICHERO 0



FILE *pfich;
char linea[MAX_CARACTERES];
char *ptrtoken;
int contador = 0;
typedef struct{
    char idPelicula[MAX_CARACTERES];
    char titulo[MAX_CARACTERES];
    char generos[MAX_CARACTERES];
} pelicula;

pelicula peliculas[MAX_CARACTERES];


FILE* ficheroEscritura;

int LeerFichero ( pelicula *e);
void *buscarGenero (char genero[]);
void motrarPeliculas (pelicula *p);
regex_t regex;
int reti;


pthread_t idHilo;
int drama;
int horror;
int thriller;
int romance;
int scifi;
int crime;
int children;
int mystery;
int musical;
int action;

int main(){

    LeerFichero( peliculas);

    // EXPRESION REGULAR PARA ENCONTRAR UN GENERO
    // Aqui ponemos el genero que queremos buscar
    reti = regcomp(&regex, "Comedy", 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }
    // Aqui buscamos en la cadena de texto
    char texto[MAX_CARACTERES] = "Adventure|Animation|Children|Comedy|Fantasy";
    reti = regexec(&regex, texto , 0, NULL, 0);
    if (!reti) {
        //puts("Match");
    } else {
        puts("Not Match.");
    }


    drama = pthread_create (&idHilo, NULL, buscarGenero, "Drama");
    sleep(1);
    horror = pthread_create (&idHilo, NULL, buscarGenero, "Horror");
    sleep(1);
    thriller = pthread_create (&idHilo, NULL, buscarGenero, "Thriller");
    sleep(1);
    romance = pthread_create (&idHilo, NULL, buscarGenero, "Romance");
    sleep(1);
    scifi = pthread_create (&idHilo, NULL, buscarGenero, "Sci-Fi");
    sleep(1);
    crime = pthread_create (&idHilo, NULL, buscarGenero, "Crime");
    sleep(1);
    children = pthread_create (&idHilo, NULL, buscarGenero, "Children");
    sleep(1);
    mystery = pthread_create (&idHilo, NULL, buscarGenero, "Mystery");
    sleep(1);
    musical =  pthread_create (&idHilo, NULL, buscarGenero, "Musical");
    sleep(1);
    action = pthread_create (&idHilo, NULL, buscarGenero, "Action");
    sleep(1);


}




int LeerFichero (pelicula *e){

    // abrimos el fichero 
    pfich = fopen("./ml-latest-small/movies.csv" , "r");
    if(pfich == NULL){
        printf("Error al abrir el archivo\n\n");
        exit(ERROR_LECT_FICHERO);
    } else {
        printf("Lectura de fichero correcta.\n");
         // Mientras que haya lieneas, coge cada linea y hace lo de dentro del while
        while(fgets(linea, 100,  pfich)){
            // Por cada SEPARADOR (,) lo separa y lo almacena segun corresponda
            //printf("%s\n", linea);
            ptrtoken = strtok(linea, SEPARADOR);
            if(ptrtoken != NULL){
                strcpy(e[contador].idPelicula, ptrtoken);
            }
            if((ptrtoken = strtok(NULL, SEPARADOR)) != NULL){
                char aux[MAX_CARACTERES];
                strcpy(aux , ptrtoken);
                //char letra = strchr(aux, 0);
                
                //if(!strcmp(letra, "\"")){
                  //  printf("tiene \"");
                //}
                strcpy(e[contador].titulo , ptrtoken);
            } 
            if((ptrtoken = strtok(NULL, SEPARADOR)) != NULL){
                strcpy(e[contador].generos , ptrtoken);
            }
            
            contador++;
        }
    }

    printf("Archivo cerrado correctamente\n");
    // cerramos el archivo y si nos da error, lo imprimimos
    if(fclose(pfich) != 0){
        printf("Error al cerrar el archivo.\n");
        exit(ERROR_LECT_FICHERO);
    }
    return 0;
}


void *buscarGenero (char genero[]){

    int numero = 0;
    int size = sizeof peliculas / sizeof peliculas[0];
    for (int i = 0 ; i < size ; i++){
        reti = regcomp(&regex, genero, 0);
        reti = regexec(&regex, peliculas[i].generos, 0, NULL, 0);
        if (!reti) {
            //printf("La pelicula %s tiene el genero %s\n", peliculas[i].titulo, genero);
            numero++;
        } 
    }
    printf("Hay %d peliculas con el genero %s\n", numero, genero);
    
    
}



void motrarPeliculas (pelicula *p){
    printf("----- MOSTRANDO TODAS LAS PELICULAS -------");
    int numero = 0;
    int size = sizeof peliculas / sizeof peliculas[0];
    for (int i = 0 ; i < size ; i++){
        printf("id: %s\tTitulo: %s\tGeneros: %s\n", p[i].idPelicula, p[i].titulo, p[i].generos);
        sleep(1);
    }
}