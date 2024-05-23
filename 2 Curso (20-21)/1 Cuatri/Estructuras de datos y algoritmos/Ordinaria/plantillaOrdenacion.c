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

int finalizador = 0;
int opcion = 0;
char linea[MAX_CARACTERES];
tAlumnos listaAlumnos[MAX_CARACTERES];
int numeroAlmunos = 0;
int contador = 0;
int metodoBusqueda;
int numeroDelAlumno = 0;

// Intercambia dos alumnos o lo que sea
void intercambiar(tAlumnos *a, tAlumnos *b) {
  tAlumnos temporal = *a;
  *a = *b;
  *b = temporal;
}

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


void QuickSort (tAlumnos *v, int izda, int dcha)
{

  if (izda < dcha) {
    int indiceParticion = Partir(v, izda, dcha);
    QuickSort(v, izda, indiceParticion);
    QuickSort(v, indiceParticion + 1, dcha);
  }
} 

void Burbuja (tAlumnos *p, int l, int r){

	for(int i = l ; i < r ; i++){
		for(int j = r - 1 ; j >= i ; j--){
			
			if(p[j].Media > p[j+1].Media){
				intercambiar(&p[j] , &p[j+1]);
			}
		}
	}
}

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
	while(finalizador == 0){
	    opcion = menu();
	    switch (opcion) {
	      case OPCION_UNO:
	      
	     	break;

	     case OPCION_DOS:

	    	break;

	    case OPCION_TRES:

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





