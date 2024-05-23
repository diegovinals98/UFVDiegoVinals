// Practica 1: Parte 1
// Nombre: Diego Vinals Lage
// Curso: 2A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>

// Declaracion de constantes

#define NE 3
#define NR 6
#define CORRECTO 0
#define OPCION_UNO 1
#define OPCION_DOS 2
#define OPCION_TRES 3
#define OPCION_CUATRO 4
#define ERROR_LECT_FICHERO 1
#define SEPARADOR ";"
#define MAX_CARACTERES 100

// Declararion de Estructuras
typedef struct{
    char Nombre[MAX_CARACTERES];
    char Apellido1[MAX_CARACTERES];
    char Apellido2[MAX_CARACTERES];
    long Sueldo;
} tEmpleado;

typedef struct{
    long Maximo;
    long Incremento;
} tRango;

// declarancion de variables
char linea[MAX_CARACTERES];
char fichero3[MAX_CARACTERES];
char fichero2[MAX_CARACTERES];
char fichero1[MAX_CARACTERES];
FILE *pfich1;
FILE *pfich2;
FILE *pfich3;
char *ptrtoken;
tEmpleado empleados[MAX_CARACTERES];
tRango listaRango[MAX_CARACTERES];
long sueldos[MAX_CARACTERES];
int finalizador;
int opcion;
int contadorNE = 0;
int contadorNR = 0;
float varianza = 0;
float desviacion = 0;
float media = 0;
float maximo = 0;

/* Funcion que devuelve en float
   Calcula la media de todos los sueldos
*/
float CalcularMedia (long *S, int Num){

    float suma = 0;
    for (int i =0 ; i < Num; i++){
        suma = suma + S[i];
    }
    return suma / Num;
}

/* Funcion que devuelve un float
   Calcula la varianza con todos los suelos
*/
float CalcularVarianza (long *S, int Num)
{

    float suma = 0;
    for(int i = 0 ; i <  NE ; i++){
        suma = suma + pow(S[i] - media, 2);
    }
    return suma / NE;
}

/* Funcion que devuelve un float
   Calcula la desviacion tipica con la varianza calculada anteriormente
*/
float CalcularDesviacionTipica (float var)
{

    return sqrt(var);
}

/* Funcion que dado un puntero a empleado, 
   extrae los sueldos y los mete en el punero a Sueldos
*/
void ExtraerSueldos(tEmpleado *e, int Num, long *S)
{

    for (int i = 0; i < Num; ++i){
        S[i] = e[i].Sueldo;
    }
}

/* Funcion que devuelve un float
   Calcula, dado un puntero a empleado, el sueldo maximo de todos los empleados
*/
float CalcularMaximo (tEmpleado *e, int Num)
{
    
    float max = 0;
    for(int i = 0 ; i < Num ; i++ ){
        if(e[i].Sueldo > max){
            max = e[i].Sueldo;
    }
  }
  return max;
}

/* Funcion que dado los punteros a empleado y a rango, 
   calcula los nuevos sueldos y los sustituye por los 
   suelos anteriores
*/ 
void CalcularNuevosSueldos (tEmpleado *e, tRango *R)
{
    

    int numa = 0;
    int numb = 0;
    float na = 0;
    float nb = 0;

    for(int i = 0; i < NE; i++){
        for(int j =  0; j < NR; j++) {
            if(e[i].Sueldo > R[j].Maximo){
                numa = j;
                numb = i;
            }
        }
            nb = (100 + R[numa].Incremento)*(0.01);

            na = e[numb].Sueldo * nb;
            e[numb].Sueldo = na;
    }
   

}

// Funcion que lee um fichero y lo almacena en el puntero empleado
int LeerFicheroE (char NomFichero[], tEmpleado *e)
{

    // abrimos el fichero NomFichero
    pfich1 = fopen(NomFichero , "r");
    if(pfich1 == NULL){
        printf("Error al abrir el archivo\n\n");
        exit(ERROR_LECT_FICHERO);
    } else {
        printf("Lectura de fichero Empleados correcta.\n");
         // Mientras que haya lieneas, coge cada linea y hace lo de dentro del while
        while(fgets(linea, 100,  pfich1)){
            // Por cada SEPARADOR (;) lo separa y lo almacena segun corresponda
            ptrtoken = strtok(linea, SEPARADOR);
            if(ptrtoken != NULL){
                strcpy(e[contadorNE].Nombre, ptrtoken);
            }
            if((ptrtoken = strtok(NULL, SEPARADOR)) != NULL){
                strcpy(e[contadorNE].Apellido1 , ptrtoken);
            } 
            if((ptrtoken = strtok(NULL, SEPARADOR)) != NULL){
                strcpy(e[contadorNE].Apellido2 , ptrtoken);
            }
            if((ptrtoken = strtok(NULL, SEPARADOR)) != NULL){
                e[contadorNE].Sueldo = strtol(ptrtoken,NULL,10);
            }
            contadorNE++;
        }
    }
    // cerramos el archivo y si nos da error, lo imprimimos
    if(fclose(pfich1) != 0){
        printf("Error al cerrar el archivo.\n");
        exit(ERROR_LECT_FICHERO);
    }
    return 0;
}

// Leemos el fichero NomFichero
int LeerFicheroR (char NomFichero[], tRango *r)
{
   
    // Abrimos el arichivo NomFicheo, de lectura solo
    pfich2 = fopen(NomFichero , "r");
    if(pfich2 == NULL){
        printf("Error al abrir el archivo\n\n");
        exit(ERROR_LECT_FICHERO);
    } else {

        printf("Lectura de fichero Rangos correcta.\n");
        // Separa cada linea
        while(fgets(linea, 100,  pfich2)){

            // cada linea, la separa por el separador (;)
            // lo almacena en el puntero rango
            ptrtoken = strtok(linea, SEPARADOR);
            if(ptrtoken != NULL){
                r[contadorNR].Maximo = strtol(ptrtoken,NULL,10);
            }
            if((ptrtoken = strtok(NULL, SEPARADOR)) != NULL){
                r[contadorNR].Incremento = strtol(ptrtoken,NULL,10);
            } 
            contadorNR++;
        }
    }

    // Se cierra el archivo, si da error
    // Se sale del programa con exit(1);
    if(fclose(pfich2) != 0){
        printf("Error al cerrar el archivo.\n");
        exit(ERROR_LECT_FICHERO);
    }
    return 0;
}


// Funcion que crea o abre un fichero y escribe 
// en ese fichero el empleado con los nuevos sueldos
int EscribirFichero (char NomFichero[], tEmpleado *e)
{


    FILE *fichero;
    fichero = fopen(NomFichero, "wt"); //abrimos el archivo de texto en modo escritura

    if (fichero == NULL) {
        printf("Error, no se encuentra el archivo:\n");
        exit(ERROR_LECT_FICHERO);
    }else{
        //Escribimos los atributos en una linea con cada separador, con fputs iremos escribiendo los valores y con SEPARADOR pondremos el ;
        for (int i = 0; i < NE; i++) {
            fputs(e[i].Nombre, fichero);
            fputs(SEPARADOR, fichero);
            fputs(e[i].Apellido1, fichero);
            fputs(SEPARADOR, fichero);
            fputs(e[i].Apellido2, fichero);
            fputs(SEPARADOR, fichero);
            fprintf(fichero, "%ld", e[i].Sueldo);
            fputs("\n", fichero);//Hacemos el salta de linea para que cada linea sea un empleado

        }
        printf("Fichero creado.\n");
        fclose(fichero); //Cerramos archivo
    }
    return CORRECTO;
}


// Funcion que imprime las opciones de menu
// y te da a elegir
// Devuelve un int que luego se usara para el switch
int menu(void){
    int menu;
    printf("\n\n1. Leer información de entrada.\n");
    printf("2. Calcular el máximo, el mínimo, la media aritmética, la varianza y la desviación típica de los sueldos actuales de los empleados.\n");
    printf("3. Calcular los nuevos sueldos y almacenarlos en un archivo.\n");
    printf("4. Salir del programa.\n");
    printf("\nIntroduzca una Opcion (1-4) ");
    scanf("%d" , &menu);
    return menu;
}


int main(void){

    finalizador = 0;      
    while(finalizador == 0){
        opcion = menu();
        switch (opcion) {
            case OPCION_UNO:

                // Lectura de los dos ficheros
                strcpy(fichero1 , "./fich01.txt");
                strcpy(fichero2 , "./fich02.txt");
                LeerFicheroE(fichero1 , empleados);
                LeerFicheroR(fichero2 , listaRango);

                break;
                
            case OPCION_DOS:

                // Funciones para sacar los datos pedidos
                ExtraerSueldos(empleados , NE , sueldos);
                media = CalcularMedia(sueldos , NE);
                varianza = CalcularVarianza(sueldos , NE);
                desviacion = CalcularDesviacionTipica(varianza);
                maximo = CalcularMaximo(empleados , NE);

                // Si todo es 0, quiere dedir que no hay datos, por lo tanto, no se han leido los ficheros, 
                // el usuario ha debido de dar a la opcion 2 sin leer los datos antes
                if(maximo == 0.000000 && varianza == 0.000000 && desviacion == 0.000000 && media == 0.000000){
                    printf("\nNo se han leido los ficheros, por lo tanto no se pueden calcular los estadisticos.\n");
                }else {
                    printf("\nEl sueldo mas alto es: %.2lf Euros.\n",  maximo);
                    printf("La media de todos los sueldos es: %.2lf Euros.\n", media);
                    printf("La varianza de los suelos es: %.2lf Euros.\n", varianza);
                    printf("La desviacion tipica de los sueldos es: %.2lf Euros.\n", desviacion);
                }

                break;

            case OPCION_TRES:
                // Calcula los nuevos sueldos
                // y llama a la funcion para escribirlos.
                strcpy(fichero3, "fich03.txt");
                CalcularNuevosSueldos(empleados, listaRango );
                EscribirFichero(fichero3, empleados);
                break;

            case OPCION_CUATRO:
                
                // finalizador es 1, por lo que se sale del programa
                finalizador = 1;
                system("clear");
                printf("Adios.\n\n");
                break;

            default:
                printf("ERROR: Opcion introducida no valida\n\n");
        }
    }
}

