
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>

typedef enum {FALSE, TRUE} tBoolean;

typedef struct _pnodo {
  int Elem; 
  struct _pnodo *Sig;
} nodo;

typedef nodo pila;


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
  
  return(pAux); 
  
}

// Devovemos el tope de la pila, pero no desapilamos
// consultar tope de la pila.
int DevolverTope(tPila *p) {
return(p->Elem); /* Devolvemos el elemento apuntado por p */
}


// Funcion Visualizar Pila
void visualizarPila(pila *p) {

  tPila * pAux; 
  pAux = p; 
  printf("Contenido de la pila:\n"); 
  while (pAux != NULL) {   
  	printf("%d\n", pAux->Elem);   
  	pAux = pAux->Sig; 
  } 
  
}

tPila *Desapilar(tPila *p) {
  tNodo *pAux;
  pAux = p; /* Guardamos un puntero al nodo a borrar. */
  p = p->Sig;/* El nuevo tope sera el nodo apuntado por el tope actual. */
  free(pAux);/* Liberamos la memoria ocupada por el tope actual. */
  return(p); /* Devolvemos un puntero al nuevo tope. */
}

tBoolean esPilaVacia(tPila *p) {  
	if (p==NULL)     
		return TRUE;   
	else     
		return FALSE;/* Devolvemos FALSE si la pila no esta vacia y TRUE en caso contrario. */
}

void *VisualizarCima(tPila *p) { 
  printf("El elemento cima es: "); 
  printf(" %d\n", p->Elem);
}






