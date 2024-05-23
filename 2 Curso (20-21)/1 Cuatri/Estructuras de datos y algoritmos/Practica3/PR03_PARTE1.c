// Practica 3
/*EDA Curso 2020-2021
 * PRACTICA 3 PARTE 1
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



#define MAX_CARACTERES 15000
#define MAX_CIUDAD 100
#define MAX_PAIS 100
#define MAX_ALUMNO 150
#define NOM_FICHERO "cal.csv"
#define CORRECTO 0
#define ERROR_LECT_FICHERO 1
#define ERR_ELE_NO_ENCONTRADO 2
#define ORD_QUICKSORT 0
#define ORD_SEL_DIRECTA 1
#define ORD_BURBUJA 2
#define OPCION_UNO 1
#define OPCION_DOS 2
#define OPCION_TRES 3
#define OPCION_CUATRO 4
#define SEPARADOR ";"



/* ZONA DE DECLARACIÓN DE TIPOS*/

typedef enum {FALSE, TRUE} tBoolean;

typedef char tCiudad [MAX_CIUDAD];
typedef char tAlumno [MAX_ALUMNO];


typedef struct {
  int Num;
  tAlumno Alumno;
  tCiudad Ciudad;
  int EDA;
  int AOC;
  int DW;
  int ADSI;
  float Media;
} tAlumnos;

/* DECLARACION DE FUNCIONES */
int finalizador = 0;
int opcion = 0;
FILE *pfich1;
char *ptrtoken;
char linea[MAX_CARACTERES];
tAlumnos listaAlumnos[MAX_CARACTERES];
int numeroAlmunos = 0;
int contador = 0;
int metodoBusqueda;
int numeroDelAlumno = 0;

/* Función: LeeFichero
* Lee un fichero con la información sobre las intoxicaciones y almacena la
* información.
* Autor: Mary Luz Mouronte
* Parámetros de entrada:
* Nombre de fichero.
* Precondiciones:
* no tiene
* Parámetros de salida:
* puntero, permite guardar los datos de intoxicaciones. Valor devuelto por referencia.
* Resultado de la operación. Valor devuelto por la función.
*/

int LeeFichero (char *NomFichero, tAlumnos *p)
{
  // abrimos el fichero NomFichero
  pfich1 = fopen(NomFichero , "r");
  if(pfich1 == NULL){
    printf("Error al abrir el archivo\n\n");
    exit(ERROR_LECT_FICHERO);
  } else {
    printf("Lectura de fichero Alumnos correcta.\n");
         // Mientras que haya lieneas, coge cada linea y hace lo de dentro del while
    while(fgets(linea, 100,  pfich1)){
            // Por cada separacion (;) lo separa y lo almacena segun corresponda
      ptrtoken = strtok(linea, SEPARADOR);
      if(ptrtoken != NULL){
       numeroAlmunos++;

     }
            // Metemos todos los datos en el alumno
     if((ptrtoken = strtok(NULL, SEPARADOR)) != NULL){
      p[contador].Num = numeroAlmunos;
      strcpy(p[contador].Alumno, ptrtoken);
    } 
    if((ptrtoken = strtok(NULL, SEPARADOR)) != NULL){
      strcpy(p[contador].Ciudad , ptrtoken);
    } 
    if((ptrtoken = strtok(NULL, SEPARADOR)) != NULL){
      p[contador].EDA = strtol(ptrtoken,NULL,10);
    }
    if((ptrtoken = strtok(NULL, SEPARADOR)) != NULL){
      p[contador].AOC = strtol(ptrtoken,NULL,10);
    }
    if((ptrtoken = strtok(NULL, SEPARADOR)) != NULL){
      p[contador].DW = strtol(ptrtoken,NULL,10);
    }
    if((ptrtoken = strtok(NULL, SEPARADOR)) != NULL){
      p[contador].ADSI = strtol(ptrtoken,NULL,10);
    }
    p[contador].Media = ((float) p[contador].EDA + (float) p[contador].ADSI + (float) p[contador].DW + (float) p[contador].AOC) / 4;
    contador++;
  }
}
    // cerramos el archivo y si nos da error, lo imprimimos
if(fclose(pfich1) != 0){
  printf("Error al cerrar el archivo.\n");
  exit(ERROR_LECT_FICHERO);
}
return 0;
}


// Funcion que nos imprime la nota media de todos los alumnos junton con el nombre
void imprimirAlumnos(tAlumnos *v){
	for(int i =0 ; i < contador ; i++){
		printf("Nombre: %s\n" , v[i].Alumno);
		printf("Nota Media: %lf\n", v[i].Media);
	}
}


// Funcion que imprime un alumno en la posicion a 
void imprimirAlumno(int a , tAlumnos *p){
	printf("Nombre: %s\n" , p[a].Alumno);
  printf("Ciudad: %s\n", p[a].Ciudad );
  printf("Nota EDA: %d\n", p[a].EDA);
  printf("Nota AOC: %d\n", p[a].AOC);
  printf("Nota DW: %d\n", p[a].DW);
  printf("Nota ADSI: %d\n", p[a].ADSI);
  printf("Nota Media: %f\n", p[a].Media);
}

// Funcionq que imprime los 15 alumnos con mejor nota media
void imprimirAlumnosMayor(tAlumnos *v){
	for(int i = contador - 15 ; i < contador ; i++){
		printf("Nombre: %s\n" , v[i].Alumno);
		printf("Nota Media: %lf\n", v[i].Media);	

	}
}

// Funcion que imprime los 15 alumnos con peor nota media
void imprimirAlumnosMenor(tAlumnos *v){
	for(int i = 3 ; i < 18 ; i++){
		printf("Nombre: %s\n" , v[i].Alumno);
		printf("Nota Media: %lf\n", v[i].Media);	

	}
}


// Intercambia dos alumnos
void intercambiar(tAlumnos *a, tAlumnos *b) {
  tAlumnos temporal = *a;
  *a = *b;
  *b = temporal;
}

/* Función: Partir
* Devuelve la nueva posición del pivote y separa los dos subvectores que son  tratados en las llamadas
* recursivas a QuickSort.
* Autor: Mary Luz Mouronte
* Parámetros de entrada:
* Puntero a puntero tIntoxicacion que contiene los valores a ordenar.
* Primero: posición del primer elemento
* Ultimo: posición del último elemento
* TipoOrd: Campo por el que ordenar
* Precondiciones:
* no tiene
* Parámetros de salida:
* Nueva posición del pivote. Valor devuelto por la función.
*/
int Partir (tAlumnos *v, int primero, int ultimo)
{
// Elegimos el pivote, es el primero
  tAlumnos pivote = v[primero];
  // Ciclo infinito
  while (1) {
    // Mientras cada elemento desde la primero esté en orden (sea menor que el
    // pivote) continúa avanzando el índice
    while (v[primero].Media < pivote.Media) {
      primero++;
    }
    // Mientras cada elemento desde la ultimo esté en orden (sea mayor que el
    // pivote) continúa disminuyendo el índice
    while (v[ultimo].Media > pivote.Media) {
      ultimo--;
    }
    /*
    Si la primero es mayor o igual que la ultimo significa que no
    necesitamos hacer ningún intercambio
    de variables, pues los elementos ya están en orden (al menos en esta
    iteración)
    */
    if (primero >= ultimo) {
      // Indicar "en dónde nos quedamos" para poder dividir el v de nuevo
      // y ordenar los demás elementos
      return ultimo;
    } else {//Nota: yo sé que el else no hace falta por el return de arriba, pero así el algoritmo es más claro
      /*
      Si las variables quedaron "lejos" (es decir, la primero no superó ni
      alcanzó a la ultimo)
      significa que se detuvieron porque encontraron un valor que no estaba
      en orden, así que lo intercambiamos
      */
      intercambiar(&v[primero], &v[ultimo]);
      /*
      Ya intercambiamos, pero seguimos avanzando los índices
      */
      primero++;
      ultimo--;
    }
    // El while se repite hasta que primero >= ultimo
  }

}





/* Función: Quicksort
* Implementa el algoritmo de ordenación QuickSort.
* Autor: Mary Luz Mouronte
* Parámetros de entrada:
* Primera posición del vector a ordenar
* Última posición del vector a ordenar
* Campo por el que ordenar
* Precondiciones:
* no tiene
* Parámetros de salida:
* Puntero que contiene los valores a ordenar/ordenados. Valor devuelto por referencia.
* Puntero a tDesNum.
*/
void QuickSort (tAlumnos *v, int izda, int dcha)
{

  if (izda < dcha) {
    int indiceParticion = Partir(v, izda, dcha);
    QuickSort(v, izda, indiceParticion);
    QuickSort(v, indiceParticion + 1, dcha);
  }
}

/* Función: Burbuja
* Implementa el algoritmo de ordenación de búrbuja.
* Autor: Mary Luz Mouronte
* Parámetros de entrada:
* Primera posición del vector a ordenar
* Última posición del vector a ordenar
* Campo por el que ordenar
* Precondiciones:
* no tiene
* Parámetros de salida:
* Puntero a un puntero a tipo tIntoxicacion que contiene los valores a ordenar. Valor devuelto por referencia.
*
*/
void Burbuja (tAlumnos *p, int l, int r){

	for(int i = l ; i < r ; i++){
		for(int j = r - 1 ; j >= i ; j--){
			
			if(p[j].Media > p[j+1].Media){
				intercambiar(&p[j] , &p[j+1]);
			}
		}
	}
}
/* Función: SelDirecta
* Implementa el algoritmo de ordenación de selección directa.
* Autor: Mary Luz Mouronte
* Parámetros de entrada:
* Primera posición del vector a ordenar
* Última posición del vector a ordenar
*Campo de ordenación
* Precondiciones:
* no tiene
* Parámetros de salida:
* Puntero a un puntero a tipo tAlumnos que contiene los valores a ordenar. Valor devuelto por referencia.
*/
void SelDirecta(tAlumnos *p,int l,int r)
{

  for (int k = l; k <= contador; k++) {
    int i = k;
    tAlumnos aux = p[k];
    for (int j = k + 1; j <= r; j++) {
     if (p[j].Media < aux.Media) {
      i = j;
      aux = p[i];
      }
    }
    p[i] = p[k];
    p[k] = aux;
  }
}




/* PROGRAMA PRINCIPAL */

// Menu
int menu (void){
  int menu;
  printf("\n\n1. 15 alumnos con mayor nota media. \n");
  printf("2. 15 alumnos con menor nota media.\n");
  printf("3. Mostrar datos alumno.\n");
  printf("4. Salir del programa.\n");
  printf("\nIntroduzca una Opcion (1-4) ");
  scanf("%d" , &menu);
  return menu; 
}





int main() {


  LeeFichero("Alumnos.csv" , listaAlumnos);
  
  while(finalizador == 0){
    opcion = menu();
    switch (opcion) {
      case OPCION_UNO:
      do{
        // Menu
        printf("Seleccione el metodo de busqueda (0-2).\n");
        printf("0. QuickSort.\n");
        printf("1. Seleccion Directa.\n");
        printf("2. Burbuja.\n");
        scanf("%d",&metodoBusqueda);
        switch(metodoBusqueda){
         case 0: 
         //Hacemos quicksort
         QuickSort(listaAlumnos , 0 , contador);
         imprimirAlumnosMayor(listaAlumnos);
         break;
         case 1:
         // hacemos seleccion directa
         SelDirecta(listaAlumnos, 0, contador);
         imprimirAlumnosMayor(listaAlumnos);
         break;
         case 2:
         // Hacemos burbuja
         Burbuja(listaAlumnos , 0 , contador);
         imprimirAlumnosMayor(listaAlumnos);
         break;
         default:
         printf("No se ha seleccionado ninguna opcion valida.\n");
         break;
       }

     }while (metodoBusqueda < 0 || metodoBusqueda > 2);

     break;

     case OPCION_DOS:
     do{
       printf("Seleccione el metodo de busqueda (0-2).\n");
       printf("0. QuickSort.\n");
       printf("1. Seleccion Directa.\n");
       printf("2. Burbuja.\n");
       scanf("%d",&metodoBusqueda);
       switch(metodoBusqueda){
        case 0: 

        QuickSort(listaAlumnos , 0 , contador);
        imprimirAlumnosMenor(listaAlumnos);
        break;
        case 1:
        SelDirecta(listaAlumnos, 0, contador);
        imprimirAlumnosMenor(listaAlumnos);
        break;
        case 2:
        Burbuja(listaAlumnos , 0 , contador);
        imprimirAlumnosMenor(listaAlumnos);
        break;
        default:
        printf("No se ha seleccionado ninguna opcion valida.\n");
        break;
      }

    }while (metodoBusqueda < 0 || metodoBusqueda > 2);




    break;

    case OPCION_TRES:
    // Como en el enunciado pone el numero del alumno, he supuesto que es la posicion
    // que ocupa ese alumno en la lista
    // por lo que le pido al usuario que diga el numero
    // e imprimo ese alumno
    printf("%d\n",contador );
    printf("Numero del Alumno: \n");
    scanf("%d", &numeroDelAlumno);
    imprimirAlumno(numeroDelAlumno , listaAlumnos);




    break;

    case OPCION_CUATRO:
        // Finalizado = 1; por lo que sale del bucle
    finalizador = 1;
    printf("Adios.\n");


    break;


    default:

    printf("ERROR: Opcion introducida no valida\n\n");
    
  }

}

}










