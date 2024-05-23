  //
//  main.c
//  Practica1
//
//  Created by Diego Viñals on 16/10/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>

/* ZONA DE DECLARACI”N DE CONSTANTES*/

#define fichero1 "./fich01.txt"
#define fichero2 "./fich02.txt"
#define fichero3 "fich03.txt"

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


char linea[MAX_CARACTERES];
FILE *pfich1;
FILE *pfich2;
FILE *pfich3;
char *ptrtoken;
long sueldos[100];
int finalizador;
int opcion;
int contadorNE = 0;
int contadorNR = 0;
float varianza = 0;
float desviacion = 0;
float media = 0;
float maximo = 0;
tEmpleado *punteroEmpleado;
tRango *punteroRango;



float CalcularMedia (long *S, int Num){
    float suma = 0;
    
    for (int i =0 ; i <Num; i++){
        suma = suma + S[i];
    }

    return suma / Num;

}


float CalcularVarianza (long *S, int Num)
{


    float suma = 0;
    for(int i = 0 ; i <  Num ; i++){
        suma = suma + pow(S[i] - media, 2);
    }
    
    return suma / (Num-1);
}

float CalcularDesviacionTipica (float var)
{

    return sqrt(var);
}

void ExtraerSueldos(tEmpleado *e, int Num, long *S)
{
    
    for (int i = 0; i < Num; ++i){
        S[i] = e[i].Sueldo;
    }
}


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

void CalcularNuevosSueldos (tEmpleado *e, tRango *R, int NumE, int NumR)
{
    for(int i =0 ; i < NE ; i++){

        long nuevoSueldoTemporal = 0;
        long porcentaje = 0;

        for(int j = 0; j < NR ; j++){
            if(e[i].Sueldo <= R[j].Maximo){
                porcentaje = (e[i].Sueldo * R[j].Incremento) / 100;
                nuevoSueldoTemporal = e[i].Sueldo + porcentaje;
                e[i].Sueldo = nuevoSueldoTemporal;
            }
        }
    }
   

}

int LeerFicheroE (char NomFichero[], tEmpleado *e)
{

    


    pfich1 = fopen(NomFichero , "r");
    if(pfich1 == NULL){
        printf("Error al abrir el archivo\n\n");
        exit(ERROR_LECT_FICHERO);
    } else {

    
        printf("Lectura de fichero Empleados correcta.\n");
        
        while(fgets(linea, MAX_CARACTERES,  pfich1)){

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
            // anadirEmpleado(&auxiliar);
            
            contadorNE++;

            // auxiliar = (tEmpleado * ) realloc(auxiliar , sizeof(tEmpleado));
        }
       
    }

    if(fclose(pfich1) != 0){
        printf("Error al cerrar el archivo.\n");
        exit(ERROR_LECT_FICHERO);
    }
    return 0;
}

int LeerFicheroR (char NomFichero[], tRango *r)
{
   // Trabajamos con el fichero de los rangos de sueldos

    //system("clear"); // Aplica el comando de dentro en el terminal

    // Trabajamos con el fichero de los empleados
    // lo cogemos por linea
    
    
    pfich2 = fopen(NomFichero , "r");
    if(pfich2 == NULL){
        printf("Error al abrir el archivo\n\n");
        exit(ERROR_LECT_FICHERO);
    } else {

        printf("Lectura de fichero Rangos correcta.\n");
        while(fgets(linea, 100,  pfich2)){

            ptrtoken = strtok(linea, SEPARADOR);
            if(ptrtoken != NULL){
                r[contadorNR].Maximo = strtol(ptrtoken,NULL,10);

            }
            if((ptrtoken = strtok(NULL, SEPARADOR)) != NULL){
                r[contadorNR].Incremento = strtol(ptrtoken,NULL,10);
            } 
            contadorNR++;
        }
        

        // for(int i = 0 ; i < NR ; i++){
        //     printf("Maximo: %ld\n", r[i].Maximo );
        //     printf("\t%ld\n", r[i].Incremento);
        // }
        
    }

    if(fclose(pfich2) != 0){
        printf("Error al cerrar el archivo.\n");
        exit(ERROR_LECT_FICHERO);
    }


    return 0;
}



int EscribirFichero (char NomFichero[], tEmpleado *e)
{

    pfich3 = fopen(NomFichero , "w");
    if(pfich3 == NULL){
        printf("Error al crear el nuevo archivo\n");
        return(ERROR_LECT_FICHERO);
    } else {
        printf("Creacion de fichero nuevos sueldos correcta.\n");
        CalcularNuevosSueldos(punteroEmpleado, punteroRango, NE, NR);
        for(int i = 0 ; i < NE ; i++){
            fprintf(pfich3, "%s;%s;%s;%ld\n", e[i].Nombre , e[i].Apellido1 , e[i].Apellido2 , e[i].Sueldo);
        }
        
    }

    if(fclose(pfich3) != 0){
        printf("Error al cerrar el archivo.\n");
        exit(ERROR_LECT_FICHERO);
    }

    return 0;
}


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


    punteroEmpleado = (tEmpleado *) calloc(NE, sizeof(tEmpleado));
    punteroRango = (tRango *) calloc(NR, sizeof(tRango));

    finalizador = 0;
    while(finalizador == 0){
        opcion = menu();
        switch (opcion) {
            case OPCION_UNO:
                
                LeerFicheroE(fichero1 , punteroEmpleado);
                LeerFicheroR(fichero2 , punteroRango);
                
                break;
                
            case OPCION_DOS:

                ExtraerSueldos(punteroEmpleado , NE , sueldos);
                media = CalcularMedia(sueldos , NE);
                varianza = CalcularVarianza(sueldos , NE);
                desviacion = CalcularDesviacionTipica(varianza);
                maximo = CalcularMaximo(punteroEmpleado , NE);

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

                
                CalcularNuevosSueldos(punteroEmpleado, punteroRango , NE, NR);
                EscribirFichero(fichero3, punteroEmpleado);
                break;

            case OPCION_CUATRO:
                
                finalizador = 1;
                free(punteroEmpleado);
                free(punteroRango);
                system("clear");
                printf("Adios.\n\n");
                break;

            default:
                printf("ERROR: Opcion introducida no valida\n\n");
        }
        

    }
}

