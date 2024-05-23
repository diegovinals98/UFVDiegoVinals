
/*EDA Curso 2020-2021 
* PRACTICA 2 PARTE 1
*/

/* LIBRERÍAS ESTÁNDAR*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include <time.h>
#include <locale.h>
#include <math.h>

/* ZONA DE DECLARACIÓN DE CONSTANTES*/

#define MAX_CARACTERES 15000

#define N 100 
#define MAX_CONJUNTOS 2
#define MAX_CAR_PALABRA 50
#define FICH1 "fich11.txt"
#define FICH2 "Fich12.txt"
#define MAX_NOMBRE_CONJUNTO 50
#define ERROR_LECT_FICHERO 1
#define CORRECTO 0
#define SEPARADOR " "
#define OPCION_UNO 1
#define OPCION_DOS 2
#define OPCION_TRES 3
#define OPCION_CUATRO 4
#define OPCION_CINCO 5





typedef enum {FALSE, TRUE} tBoolean;

typedef struct {
  char Palabra[MAX_CAR_PALABRA];
} tElemento;

typedef struct {
  char Nombre[MAX_NOMBRE_CONJUNTO];
  tElemento Elementos[N];
  short int Ultimo;
} tConjunto;


/* ZONA DE DECLARACIÓN DE TIPOS*/
tConjunto *conjuntos1;
tConjunto *conjuntos2;
tConjunto *conjuntoUnion;
tConjunto *conjuntoInterseccion;
tConjunto *conjuntoDiferencia;
FILE *pfich1;
FILE *pfich2;
char *ptrtoken;  
int contadorC1 = 0;
char linea[MAX_CARACTERES];
int i;
int a;
int finalizador = 0;
int opcion = 0;
int contadorElementos = 0;



// Imprime el conjunto al que 
// llama el puntero C
void ImprimeCjto (tConjunto *C)
{
  int h = 0;
  printf("Conjunto %s:\n", C->Nombre );
  for (int j = 0; j < 100; j++)
  {
    if(strcmp("empty" , C->Elementos[j].Palabra)){
      printf("\tElemento %d: %s\n" , h+1, C->Elementos[j].Palabra);
      h++;
    }
    
  }
  
}

// Lee el fichero y lo almacena dentro del conjunto
int LeeFichero1 (char *NomFichero, tConjunto *Conjunto)
{
  
  // abrimos el fichero NomFichero
  pfich1 = fopen(NomFichero , "r");
  if(pfich1 == NULL){
    printf("Error al abrir el archivo\n\n");
    exit(ERROR_LECT_FICHERO);
  } else {
    printf("Lectura de fichero correcta.\n");
    
    while(!feof(pfich1)){
      char temp[MAX_CAR_PALABRA];
      fscanf(pfich1, "%s", temp);
      if(strcmp(" " , temp)){
        strcpy(Conjunto->Elementos[i].Palabra , temp);
        contadorElementos++;
        i++;
      }
      
    }
    Conjunto->Ultimo = i;
  }
  
  // cerramos el archivo y si nos da error, lo imprimimos
  if(fclose(pfich1) != 0){
    printf("Error al cerrar el archivo.\n");
    exit(ERROR_LECT_FICHERO);
  }
  return 0;
}

// Lee el archivo y lo almacena en el conjunto
int LeeFichero2 (char *NomFichero, tConjunto *Conjunto)
{
  
  // abrimos el fichero NomFichero
  pfich2 = fopen(NomFichero , "r");
  if(pfich2 == NULL){
    printf("Error al abrir el archivo\n\n");
    exit(ERROR_LECT_FICHERO);
  } else {
    printf("Lectura de fichero correcta.\n");
    
    while(!feof(pfich1)){
      char temp[MAX_CAR_PALABRA];
      fscanf(pfich2, "%s", temp);
      if(strcmp(" " , temp)){
        strcpy(Conjunto->Elementos[a].Palabra , temp);
        contadorElementos++;
        a++;
      }
      
    }
    Conjunto->Ultimo = a;
  }
  
  // cerramos el archivo y si nos da error, lo imprimimos
  if(fclose(pfich1) != 0){
    printf("Error al cerrar el archivo.\n");
    exit(ERROR_LECT_FICHERO);
  }
  return 0;
}


// Une los dos conjuntos
// y lo almacena en un conjunto nuevo
void Union (tConjunto *X, tConjunto *Y, tConjunto *Z)
{

  int p = 0;
  for (int x = 0; x < contadorElementos; x++)
  {
    if(x < i){
      strcpy(Z->Elementos[x].Palabra , X->Elementos[x].Palabra);
      

    } else {
      
      strcpy(Z->Elementos[x].Palabra, Y->Elementos[p].Palabra );
      p++;

    }
    
  }
  
}   


// Calcula la interseccion de los dos conjuntos
// y lo almacena en el conjunto Nuevo Z
void Interseccion(tConjunto *X, tConjunto *Y, tConjunto *Z)
{
  for(int i = 0 ; i < 100 ; i++){
    for(int j = 0; j < 50 ; j++){
      if(!strcmp(X->Elementos[i].Palabra , Y->Elementos[j].Palabra)){
        strcpy(Z->Elementos[i].Palabra , X->Elementos[i].Palabra);
      }
    }
  }
  
  
} 

// Calcula la diferencia entre los dos conjuntos
// y lo almacena en el conjunto nuevo
void Diferencia (tConjunto *X, tConjunto *Y, tConjunto *Z)
{
  for(int i = 0 ; i < 100 ; i++){
    for(int j = 0; j < 50 ; j++){
      if(strcmp(X->Elementos[i].Palabra , Y->Elementos[j].Palabra)){
        strcpy(Z->Elementos[i].Palabra , X->Elementos[i].Palabra);
      }
    }
  }
  
}

// Inicalizamos un conjunto con su nombre
// y elementos "empty", para luego diferenciar bien 
// que elementos no los ha anadido el usuario
void inicializarConjunto(tConjunto *conjunto){
  char NomC[MAX_NOMBRE_CONJUNTO];    
  
  scanf("%s",NomC); 
  strcpy((conjunto)->Nombre, NomC);   

  for (int i = 0; i < 100; ++i)
  {
    strcpy(conjunto->Elementos[i].Palabra , "empty");
  }
  
}



// Menu
int menu (void)
{
  int menu;
  printf("\n\n1. Mostrar Conjuntos 1 y 2.\n");
  printf("2. Unir Conjuntos 1 y 2.\n");
  printf("3. Intersección de conjuntos 1 y 2.\n");
  printf("4. Diferencia de conjuntos 1 y 2.\n");
  printf("5. Salir del programa.\n");
  printf("\nIntroduzca una Opcion (1-5) ");
  scanf("%d" , &menu);
  return menu;
  
  
} 


/* PROGRAMA PRINCIPAL */
int main() { 

  
  // Inicializamos los conjuntos
  conjuntos1 = (tConjunto *) malloc( sizeof(tConjunto));
  conjuntos2 = (tConjunto *) malloc( sizeof(tConjunto));
  conjuntoUnion = (tConjunto *) malloc( sizeof(tConjunto)) ;
  conjuntoInterseccion = (tConjunto *) malloc( sizeof(tConjunto));
  conjuntoDiferencia = (tConjunto *) malloc( sizeof(tConjunto));
  printf("\n");
  printf("Introduzca Nombre del Conjunto 1: \n");
  inicializarConjunto(conjuntos1);
  printf("Introduzca Nombre del Conjunto 2: \n");
  inicializarConjunto(conjuntos2);
  printf("Introduzca Nombre del Conjunto Union: \n");
  inicializarConjunto(conjuntoUnion);
  printf("Introduzca Nombre del Conjunto Intersección: \n");
  inicializarConjunto(conjuntoInterseccion);
  printf("Introduzca Nombre del Conjunto Diferencia: \n");
  inicializarConjunto(conjuntoDiferencia);
  
  // Leemos los dos ficheros
  LeeFichero1(FICH1 , conjuntos1);
  LeeFichero2(FICH2 , conjuntos2);
  
  
  while(finalizador == 0){
    opcion = menu();
    switch (opcion) {
      case OPCION_UNO:
        // Imprimimos los dos conjuntos
        ImprimeCjto(conjuntos1);
        ImprimeCjto(conjuntos2);
        
        
        break;
      
      case OPCION_DOS:
        // Hacemos la union y lo imprimimos
        Union(conjuntos1, conjuntos2, conjuntoUnion);
        ImprimeCjto(conjuntoUnion);
        
        break;
      
      case OPCION_TRES:
        // Hacemos la interseccion y lo imprimimos
        Interseccion(conjuntos1, conjuntos2, conjuntoInterseccion);
        ImprimeCjto(conjuntoInterseccion);
        
        break;
      
      case OPCION_CUATRO:
        // Hacemos la diferencia y lo imprimimos
        Diferencia(conjuntos1, conjuntos2, conjuntoDiferencia);
        ImprimeCjto(conjuntoDiferencia);
        
        break;
      
      case OPCION_CINCO:
        // Finalizado = 1; por lo que sale del bucle
        finalizador = 1;
        printf("Adios.\n");
        break;
        
      default:
      
        printf("ERROR: Opcion introducida no valida\n\n");
    }
    
    
  }
  
}


