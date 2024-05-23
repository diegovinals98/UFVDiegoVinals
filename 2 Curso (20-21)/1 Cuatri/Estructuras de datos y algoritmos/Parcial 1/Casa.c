#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include <time.h>
#include <locale.h>
#include <math.h>

#define OPCION_UNO 1
#define OPCION_DOS 2
#define OPCION_TRES 3
#define MAX_NOMBRE 150
#define MAX_APELLIDOS 300

typedef char tNombre[MAX_NOMBRE];
typedef char tApellidos[MAX_APELLIDOS];

typedef struct {
	int prioridad;
	tApellidos Apellidos;
	tNombre Nombre;
	int Edad;
} tElemento;

typedef struct _pnodo{
	tElemento Elem;
	struct _pnodo *Sig;
}tNodo;

typedef struct {
	tNodo *pCab;
	tNodo *pCola;
} tCola;

typedef tNodo tPila;
tCola *crearCola();
tCola *Encolar(tCola *q, tElemento e);
tCola *Desencolar(tCola *q);
int EsColaVacia(tCola *q);
tPila *apilar(tPila *p, tElemento el);
tPila *Desapilar(tPila *p);
tNodo *crearPila();
int ComprobarPilaVacia(tPila *p);
tElemento introducirDatos(void);
void eliminarElementos(int p, tCola cola, tPila pila);
void mostrarMayorQueP(tCola cola , int p);




tCola *colaHospital;
tPila *pilaAuxiliar;


int finalizador = 0;
int p;
int opcion;

// Menu
int menu (void)
{
  int menu;
  printf("\n\n1. Introducir Datos.\n");
  printf("2. Eliminar elemento con prioridad p.\n");
  printf("3. Mostrar elementos con prioridad mayor que p.\n");
  printf("\nIntroduzca una Opcion (1-3) ");
  scanf("%d" , &menu);
  return menu;
} 

int main() { 

  
  colaHospital = crearCola();
  pilaAuxiliar = crearPila();

  while(finalizador == 0){
    opcion = menu();
    switch (opcion) {
      case OPCION_UNO:
        
        tElemento *elemento;
        elemento =  introducirDatos();
        Encolar(colaHospital , elemento);
        
        break;
      
      case OPCION_DOS:
        printf("Prioridad a borrar: \n");
        scanf("%d" , &p);
        eliminarElementos(p, colaHospital, pilaAuxiliar);
        break;
      
      case OPCION_TRES:
        mostrarMayorQueP(colaHospital , p);
        break;
      
      default:
        printf("ERROR: Opcion introducida no valida\n\n");
        break;
    }
    
    
  }
}


tCola *crearCola() {

  tCola *q;

  q = (tCola*) malloc(sizeof(cola)); 
  q->pCab = NULL; 
  q->pCola = NULL;

  return(q); 


}   

tCola *Encolar(tCola *q, tElemento e) {
	tNodo *qAux;
	qAux = (tNodo *) malloc(sizeof(tNodo)); /* Creamos un nodo. */
	qAux->Elem = e; /* Almacenamos el elemento e. */
	qAux->Sig = NULL;
	if (q->pCab == NULL) /* Si no hay ningun elemento, entonces */    
		q->pCab = qAux; /* pcab apunta al nuevo nodo creado, */
	else /* y sino, */   
		q->pCola->Sig = qAux;/* el nodo nuevo va despues del que apunta pcol. */

	q->pCola = qAux;/* El nuevo nodo pasa a estar apuntado por pcol. */
	return(q); /* Devolvemos un puntero a la cola modificada. */
}   

tCola *Desencolar(tCola *q) {
	tNodo *qAux;
	qAux = q->pCab; /* Guardamos un puntero al nodo a borrar. */
	q->pCab = q->pCab->Sig; /* Actualizamos pCab. */
	if (q->pCab == NULL) /* Si la cola se queda vacia, entonces */  
		q->pCola = NULL; /* actualizamos pCol. */
	free(qAux); /* Liberamos la memoria ocupada por el nodo. */
	return(q); /* Devolvemos un puntero a la cola modificada. */
} 

int EsColaVacia(tCola *q) {    
	if (q->pCab == NULL)      
		return 1;    
	else      
		return 0;/* Devolvemos 0 (falso) si la cola no esta vacia y  1 (cierto) en caso contrario. */
}

// Funcion apilar
tPila *apilar(tPila *p, tElemento el) {

  tNodo *pAux;
  
  pAux = (tNodo *) malloc(sizeof(tNodo)); 

  pAux->Elem = el; 
  pAux->Sig = p;
  p = pAux;
  
  return(p); 
  
}

tNodo *crearPila() {
  return(NULL); 
}   


tPila *Desapilar(tPila *p) {
  tNodo *pAux;
  pAux = p; /* Guardamos un puntero al nodo a borrar. */
  p = p->Sig;/* El nuevo tope sera el nodo apuntado por el tope actual. */
  free(pAux);/* Liberamos la memoria ocupada por el tope actual. */
  return(p); /* Devolvemos un puntero al nuevo tope. */
}

int ComprobarPilaVacia(tPila *p) {  
	if (p==NULL)     
		return 1;   
	else     
		return 0;/* Devolvemos 0 si la pila no esta vacia y 1 en caso contrario. */
}


tElemento introducirDatos(void){
	tElemento aux;
	int edadAuxiliar = 1;

	printf("Nombre: \n");
	scanf("%s" , &aux.Nombre);
	printf("Apellidos: \n");
	scanf("%s" , &aux.Apellidos);
	printf("Edad: \n");
	scanf("%d" , &edadAuxiliar);
	while(edadAuxiliar < 0 || edadAuxiliar > 99){
		printf("Error en la edad, tiene que estar entre 0 y 99 años\n");
		printf("Edad: \n");
		scanf("%d" , &edadAuxiliar);
	}
	aux.Edad = edadAuxiliar;

	printf("Prioridad:\n");
	scanf("%d" , &aux.prioridad);


	return aux;

}


void eliminarElementos(int p, tCola cola, tPila pila){
	while(!EsColaVacia(cola)){
		if(cola->pCab.Elem.prioridad != p){
			apilar(pila, cola->pCab.Elem);
		}
		Desencolar(cola);
	}


	while(!ComprobarPilaVacia(pila)){
		Encolar(pila->Elem);
		Desapilar(pila->Elem);
		
	}
}

void mostrarMayorQueP(tCola cola , int p){
	tNodo *pAux;  
	pAux = cola->pCab; 
	printf("Pacientes con prioridad mayor que P:\n"); 
	while (pAux != NULL) {   
		if(pAux->Elem.prioridad > p){
			printf("Nombre: %s\n", pAux->Elem.Nombre);  
			printf("Apellidos: %s\n", pAux->Elem.Apellidos);  
			printf("Edad: %d\n", pAux->Elem.Edad); 
			printf("Prioridad: %d\n", pAux->Elem.prioridad); 
		}

		pAux = pAux->Sig; 
	} 

}

