/*EDA Curso 2020-2021 
* PRACTICA 2 PARTE 3
*/


/* LIBRERÕAS EST¡NDAR*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>

/* ZONA DE DECLARACI”N DE CONSTANTES*/

#define CORRECTO 0
#define ERR_COLA_VACIA 1
#define ERR_MEMORIA 2
#define OPCION_UNO 1
#define OPCION_DOS 2
#define OPCION_TRES 3
#define OPCION_CUATRO 4
#define OPCION_CINCO 5



/* ZONA DE DECLARACI”N DE TIPOS*/

typedef enum {FALSE, TRUE} tBoolean;

// typedef struct {
//   int Num;
// } tElemento;


typedef struct _pnodo {
  int Elem; 
  struct _pnodo *Sig;
} nodo;

typedef nodo pila;

typedef struct {
  nodo *pCab, *pCol; 
} cola;

// Inicializamos Variables
int finalizador = 0;
int opcion = 0;
double i = 0;
int j = 0;
int absi = 0;

cola *pCola1;
cola *pCola2;
cola *pCola3;
cola *pCola4;

nodo *pPila1;
nodo *pPila2; 
nodo *pPila3; 
nodo *pPila4;

/* Funcion: crearPila
* Crea una pila Vacia
* Paramentros entrada:
* no tiene.
* Parametros Salida:
* no tiene.
*/
pila *crearPila(void);


/* Funcion: apilar
* Devuelve la pila modificada.
* Parametros de entrada: 
* Pila y Elemento Añadir a la pila.
* Precondiciones: 
* no tiene 
* Parametros de salida: 
* Pila modificada. Valor devuelto por la Funcion.
*/
pila *apilar(pila *p, int el); 




/* Funcion: visualizarPila
* Imprime la Pila
* Parametros de entrada: 
* Pila .
* Precondiciones: 
* no tiene 
* Parametros de salida: 
* no tiene
*/
void visualizarPila(pila *p);




/* Funcion: esPilaVacia
* Devuelve si la pila esta o no vacÌa.
* Parametros de entrada: 
* Pila
* Precondiciones: 
* no tiene 
* Parametros de salida: 
* Pila vacÌa o no. Valor devuelto por la Funcion              
* 
*/
tBoolean esPilaVacia(pila *p);




/* Funcion: encolar
* Devuelve el resultado de la operacion (correcto o error).
* Parametros de entrada: 
* Elemento Añadir a la cola y la cola
* Precondiciones: 
* no tiene 
* Parametros de salida: 
* Int. Valor devuelto por referencia.
* Resultado de la operacion. Valor devuelto por la Funcion.
*/
int encolar(cola *p, int E);





/* Funcion: desencolar
* Devuelve el resultado de la operacion (correcto o error).
* Parametros de entrada: 
* La cola.
* Precondiciones: 
* no tiene 
* Parametros de salida: 
* Cola. Valor devuelto por referencia.
* Elemento desapilado. Valor devuelto por referencia.
* Resultado de la operacion. Valor devuelto por la Funcion.
*/
int desencolar (cola *p);





/* Funcion: verCola
* Devuelve el resultado de la operacion (correcto o error).
* Parametros de entrada: 
* Cola
* Precondiciones: 
* no tiene 
* Parametros de salida: 
* no tiene               
* Resultado de la operacion. Valor devuelto por la Funcion.
*/
int verCola(cola *p);


/* Funcion: esColaVacia
* Devuelve si la cola esta o no vacÌa.
* Parametros de entrada: 
* Cola
* Precondiciones: 
* no tiene 
* Parametros de salida: 
* Cola vacÌa o no. Valor devuelto por la Funcion              
* 
*/
tBoolean esColaVacia(cola *p);


/* Funcion: Menu
* Presenta el menu y devuelve la opcion elegida por el
* usuario.
* Parametros de entrada: 
* No tiene
* Precondiciones: 
* no tiene 
* Parametros de salida: 
* Opcion. Valor devuelto por la Funcion.
* 
*/
int menu (void);


// --------------------------------------------------- FUNCIONES PILAS --------------------------------------------------------------//
nodo *crearPila() {
  return(NULL); 
}   


// Funcion apilar
pila *apilar(pila *p, int el) {

  nodo *pAux;
  
  pAux = (nodo *) malloc(sizeof(nodo)); 

  pAux->Elem = el; 
  pAux->Sig = p;
  p = pAux;
  
  return(p); 
  
}

// Funcion Visualizar Pila
void visualizarPila(pila *p) {


  nodo * pAux;
  pAux = (nodo *) malloc(sizeof(nodo));
  
  int cont2 = 0;

  pAux = p;
  while (pAux != NULL)
  {
    printf("\tElemento %d: %d\n", cont2, pAux->Elem);
    pAux = pAux->Sig;
    cont2++;
  } 
  
  
}


pila *desapilar(pila *p) {

  nodo *pAux;
  
  pAux = p; 
  p = p->Sig;
  free(pAux);

  return (p);
}

tBoolean esPilaVacia(pila *p) {
  if (p==NULL)
    return TRUE;
  else
    return FALSE;
  
}



int gestionarPila (int i, int j, pila *pila)
{
  
  if (i > 0)
  {
    //  entoAux;
    // elementoAux.Num = j;
    
    pila = apilar(pila, j);

  }
  else if (i < 0){
    if (esPilaVacia(pila))
    {
      printf("No se puede eliminar ningun elemento, porque no hay elementos en la cola.");
    } else
    {
      pila = desapilar(pila);
    }
  }
  return 1;

}





// --------------------------------------------------- FUNCIONES COLAS --------------------------------------------------------------//


int encolar(cola *p, int E) {

  nodo *qAux;

  qAux = (nodo *) malloc(sizeof(nodo)); 
  qAux->Elem = E; 
  qAux->Sig = NULL;
  
  if (p->pCab == NULL) 
    p->pCab = qAux; 
  else 
    p->pCol->Sig = qAux;
  
  
  p->pCol = qAux;
  
  return p->pCol->Elem;
}

int desencolar (cola *p){
  nodo *qAux;
  nodo *aux2;

  qAux = p->pCab; 
  p->pCab = p->pCab->Sig; 
  if (p->pCab == NULL)
    ;
  p->pCol = NULL; 

  aux2= qAux;
  free(qAux);
  return aux2->Elem;
 
  
  
}

int verCola(cola *p) {
  nodo * pAux;
  
  pAux = p->pCab;
  int cont = 0;
  while (pAux != NULL)
  {
    printf("\tElemento %d: %d\n", cont, pAux->Elem);
    pAux = pAux->Sig;
    cont++;
  } 
  
  return 1;
  
}

cola *crearCola() {

  cola *q;

  q = (cola*) malloc(sizeof(cola)); 
  q->pCab = NULL; 
  q->pCol = NULL;

  return(q); 


}   

tBoolean esColaVacia(cola *p) {

  if (p->pCab == NULL)
    return TRUE;
  else
    return FALSE;
  
}


void eliminarCola(int numero, cola *colas){

  cola *aux = crearCola();

  int x= 0;
  int y =0;

  while((x = desencolar(colas) != numero)){
    encolar(aux, x);
  }

  while (!esColaVacia(aux))
  {

    y = desencolar(aux);
    encolar(colas, y);
    
  }

}





int gestionarCola (int i, int j, cola *pCola)
{

  

  if (i > 0)
  {
    
    encolar(pCola , j);
  }
  else if (i < 0){
    if (esColaVacia(pCola1))
    {
      printf("No se puede eliminar ningun elemento, porque no hay elementos en la cola.");
    } else
    {
      eliminarCola(j, pCola );
    }
  }

  return 1;
  
}


// --------------------------------------------------- PROGRAMA PRINCIPAL --------------------------------------------------------------//

int menu (void)
{

  int menu;
  printf("\n\n1. Gestonar Pilas.\n");
  printf("2. Mostrar Pilas.\n");
  printf("3. Gestionar Colas.\n");
  printf("4. Mostrar Colas.\n");
  printf("5. Salir del programa.\n");
  printf("\nIntroduzca una Opcion (1-5) ");
  scanf("%d" , &menu);
  return menu;

  
} 


  int main() { 


    pCola1 = crearCola();
    pCola2 = crearCola();
    pCola3 = crearCola();
    pCola4 = crearCola();

    pPila1 = crearPila();
    pPila2 = crearPila();
    pPila3 = crearPila();
    pPila4 = crearPila();


    while(finalizador == 0){
      opcion = menu();
      switch (opcion) {
        case OPCION_UNO:
          printf("Elija numero i: "); // NUMERO i ES LA PILA
          scanf("%lg" , &i);
          printf("Elija numero j: "); // NUMERO j ES EL NUMERO A ANADIR
          scanf("%d" , &j);
          absi = (int) fabs(i);

          switch (absi)
          {
            case 1:
            gestionarPila(i, j , pPila1);
            break;
            case 2:
            gestionarPila(i, j , pPila2);
            break;
            case 3:
            gestionarPila(i, j , pPila3);
            break;
            case 4:
            gestionarPila(i, j , pPila4);
            break;
            default:
            printf("No se ha hecho nada, porque el numero i es mayor que 4 o menos que -4.\n");
            break;
          }
          break;


        break;

        case OPCION_DOS:
          printf("Pila 1: \n");
          visualizarPila(pPila1);
          printf("Pila 2: \n");
          visualizarPila(pPila2);
          printf("Pila 3: \n");
          visualizarPila(pPila3);
          printf("Pila 4: \n");
          visualizarPila(pPila4);
        
        break;

        case OPCION_TRES:
        
          printf("Elija numero i: "); // NUMERO i ES LA PILA
          scanf("%lg" , &i);
          printf("Elija numero j: "); // NUMERO j ES EL NUMERO A ANADIR
          scanf("%d" , &j);
          absi = (int) fabs(i);

          switch (absi)
          {
            case 1:
            gestionarCola(i, j , pCola1);
            break;
            case 2:
            gestionarCola(i, j , pCola2);
            break;
            case 3:
            gestionarCola(i, j , pCola3);
            break;
            case 4:
            gestionarCola(i, j , pCola4);
            break;
            default:
            printf("No se ha hecho nada, porque el numero i es mayor que 4 o menos que -4.\n");
            break;
          }
          break;

        case OPCION_CUATRO:

          printf("Cola 1: \n");
          verCola(pCola1);
          printf("Cola 2: \n");
          verCola(pCola2);
          printf("Cola 3: \n");
          verCola(pCola3);
          printf("Cola 4: \n");
          verCola(pCola4);
        
          break;

        case OPCION_CINCO:
        finalizador = 1;
        printf("Adios.\n");
        break;

        default:

        printf("ERROR: Opcion introducida no valida\n\n");
      }


    }

  }











