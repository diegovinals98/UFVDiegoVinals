//Para esta práctica he utilizado los ficheros anteriores, ya que no entendía el significado de los ficheros actuales en el canvas
//Librerías estándar

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>
#include <unistd.h>

//Delaración de constantes
#define NE 3
#define NR 6
#define CORRECTO 0
#define ERROR_LECT_FICHERO 1
#define MAX_CARACTERES 100
#define SEPARACION ";"

typedef struct{
    char Nombre[MAX_CARACTERES];
    char Apellido[MAX_CARACTERES];
    char Apellido2[MAX_CARACTERES];
    long Sueldo; }tEmpleado;

typedef struct{
    long Maximo;
    long Incremento; } tRango;


int LeerFicheroE (char NomFichero[],tEmpleado *lista);
int LeerFicheroR (char NomFichero[],tRango *Lista);
void CalcularEstadisticos (tEmpleado *listaE);
void CalcularNuevosSueldos (tEmpleado *listaE, tRango *listaR);
int EscribirFichero (char NomFichero[], tEmpleado *listaE);



//PROGRAMA//
int main(void){
    int leer = 0; //Variable para comprobar si se han leido los ficheros
    char opcion; //Variable para el switch del menú

    tEmpleado listaE[NE];
    tRango listaR[NR];

    tEmpleado *e;
    e =listaE;

    tRango *r;
    r = listaR;

    do{
        printf("1: Leer informacion de entrada\n");
        printf("2: Obtener el maximo, el minimo, la media aritmetica, la varianza, y la desviacion tipica de los sueldos actuales de los empleados\n");
        printf("3: Obtener los nuevos sueldos y almacenarlos en un archivo\n");
        printf("4: Salir del programa\n");
        fflush(stdin); //limpiamos el valor escrito
        scanf("%c",&opcion); //Al poner un carácter, a menos que concuerde con un caso del switch, el programa no parará

        switch(opcion){
            case '1':
                //Pasamos los ficheros y lo leemos
                
                printf("1)\n");
                LeerFicheroE("fich01.txt", e);
                LeerFicheroR("fich02.txt", r);
                leer=1;
                printf("\n\n");
                //Una vez que hemos leido los ficheros, la opción leer cambiara a 1
                break;
            case '2':
                
                printf("2)\n");
                if(leer != 0){// Con la variable leer, nos aseguramos de que los ficheros hayan sido leidos
                CalcularEstadisticos(e); //Calculamos los datos que nos piden de la lista empleados
                }
                else
                    printf("No se han leido los ficheros\n"); //Si no se han leido los ficheros devolveremos error
                    printf("\n\n");
                break;



            case '3':
                
                printf("3)\n");
                if(leer != 0){// Con la variable leer, nos aseguramos de que los ficheros hayan sido leidos
                CalcularNuevosSueldos(e, r);
                    EscribirFichero("fich03.txt", e);
                }
                else
                    printf("No se han leido los ficheros\n");
                    printf("\n\n");
                break;

            case '4':
                
                printf("4)\n");
                printf("Adios");
                break;
            default:
                printf("Valor incorrecto\n");
                break;
        }
    }
    while(opcion != '4'); //Mientras no demos un valor 4,salir del programa, el menu seguirá activo

    return 0;

}

//Lee el fichero y se guarda en un array
int LeerFicheroE (char NomFichero[],tEmpleado lista[]){
    char  cadena[MAX_CARACTERES];
    char *array[NE];
    int numElem, i = 0;
    char* elemento;

    FILE *fichero;
    // Abrimos el archivo en modo lectura
    fichero = fopen(NomFichero, "r");

    //Si no se encuentra el fichero dara error
    if (fichero == NULL) {
        printf("Error, no se encuentra el archivo");
        exit(ERROR_LECT_FICHERO);
    }

    else{

        while(fgets(cadena, MAX_CARACTERES, fichero)){ //Usamos fgets para leer el archivo, a base de strings
            numElem = 0;
            array[i] = cadena; //Guardamos cada linea leida mediante el while en un array
            elemento = strtok(array[i], SEPARACION);

            if(elemento != NULL){
            strcpy(lista[i].Nombre, elemento); //Guardaremos el primer atributo como el nombre

            }
            while((elemento = strtok(NULL, SEPARACION)) !=NULL){
                if(numElem == 0)
                    //Separamos los elementos segun el separador ; y los guardamos en posiciones del array
                    strcpy(lista[i].Apellido, elemento);//Lo anadimos a la lista de empleados como apellido

                else if(numElem == 1)
                    strcpy(lista[i].Apellido2, elemento);//Lo anadimos a la lista de empleados como segundo apellido

                else
                    lista[i].Sueldo = atol(elemento);//Usamos atol para pasar el tipo char leido a long
                numElem++;
            }
            i++; //Aumentamos el contador para pasar a la siguiente linea
        }
        printf("Primer archivo leido correctamente\n");

        fclose(fichero);
        return CORRECTO;
        }
}

//Leemos el segundo fichero
int LeerFicheroR (char NomFichero[],tRango Lista[]){

    char cadena[MAX_CARACTERES];
    char *array[NR];
    int i = 0;
    char* elemento;


    FILE *fichero;
    fichero = fopen(NomFichero, "r");
    if (fichero == NULL) {
        printf("Error, no se encuentra el archivo");
        exit(ERROR_LECT_FICHERO);
    }else{
        //Almacenamos el valor maximo y el incremento
        while (fgets(cadena, MAX_CARACTERES, fichero)) {
            array[i] = cadena;

            elemento = strtok(array[i], SEPARACION);
            if(elemento != NULL){
            Lista[i].Maximo = atol(elemento);
            }
            while((elemento = strtok(NULL, SEPARACION)) !=NULL){

                    Lista[i].Incremento = atol(elemento);
            }

            i++;
            //Aumentamos el contador para pasar a la siguiente linea
        }
        fclose(fichero);
        printf("Segundo archivo leido correctamente\n");

    return CORRECTO;
    }
}
void CalcularEstadisticos (tEmpleado *listaE){

    long min = listaE->Sueldo;
    long max = listaE[0].Sueldo;
    float mediarit = 0;
    float varianza = 0;
    float desviaciontip;
    for (int i = 0; i < NE; i++) {
        if (max < listaE[i].Sueldo)
            max = listaE[i].Sueldo; // Se guarda el maximo
        if (min > (listaE+i)->Sueldo)
            min = (listaE+i)->Sueldo; //Se guarda el minimo
    }

    printf("El maximo es: %ld\n", max);
    printf("El minimo es: %ld\n", min);

    for(int i = 0; i < NE; i++){
        mediarit =mediarit + listaE[i].Sueldo; //Sumamos los sueldos
    }
    mediarit = mediarit / NE; //media
    printf("La media es: %.1f\n", mediarit);

    for(int i = 0; i < NE; i++){
        varianza = varianza + pow((listaE[i].Sueldo - mediarit),2); //varianza
    }
    varianza = varianza/NE;
    printf("La varianza es: %.1f\n", varianza);
    desviaciontip = sqrtf(varianza);  //Desviacion
    printf("La desviacion tipica es de: %.1f E\n",desviaciontip);

}

void CalcularNuevosSueldos (tEmpleado *listaE, tRango *listaR){

    int a = 0, b = 0;
    float na = 0,nb = 0;

    for(int i = 0; i < NE; i++){
        for(int j =  0; j < NR; j++) {
            if(listaE[i].Sueldo > listaR[j].Maximo){//Buscamos el valor para aplicar el cambio de sueldo, el sueldo tiene que ser mayor al valor maximo, vamos comparando en las 2 listas y
                    //obtenemos la posicion de la lista 2 que correspondera al incremento en la lista 1.
                a = j;
                b = i;
            }
        }
            nb = (100 + listaR[a].Incremento)*(0.01);//Se calcula el nuevo incremento

            na = listaE[b].Sueldo * nb;//Se aplica el incremento
            listaE[b].Sueldo = na;//Se guarda el nuevo sueldo, luego se utilizara para imprimir en el archivo
    }

    printf("Incrementos calculados y almacenados\n");
}

int EscribirFichero (char NomFichero[], tEmpleado *listaE){

    FILE *fichero;
    fichero = fopen(NomFichero, "wt"); //abrimos el archivo de texto en modo escritura

    if (fichero == NULL) {
        printf("Error, no se encuentra el archivo:\n");
        exit(ERROR_LECT_FICHERO);
    }else{
        //Escribimos los atributos en una linea con cada separador, con fputs iremos escribiendo los valores y con Separacion pondremos el ;
        for (int i = 0; i < NE; i++) {
            fputs(listaE[i].Nombre, fichero);
            fputs(SEPARACION, fichero);
            fputs(listaE[i].Apellido, fichero);
            fputs(SEPARACION, fichero);
            fputs(listaE[i].Apellido2, fichero);
            fputs(SEPARACION, fichero);
            fprintf(fichero, "%ld", listaE[i].Sueldo);
            fputs("\n", fichero);//Hacemos el salta de linea para que cada linea sea un empleado

        }
        printf("Fichero con la nueva informacion\n");
        fclose(fichero); //Cerramos archivo
    }
    return CORRECTO;

}

