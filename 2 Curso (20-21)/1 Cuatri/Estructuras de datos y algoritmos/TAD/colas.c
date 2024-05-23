
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

typedef struct {
  nodo *pCab, *pCol; 
} cola;

cola *crearCola() {

  cola *q;

  q = (cola*) malloc(sizeof(cola)); 
  q->pCab = NULL; 
  q->pCol = NULL;

  return(q); 


}   

tCola *Encolar(tCola *q, int e) {
	tNodo *qAux;
	qAux = (tNodo *) malloc(sizeof(tNodo)); /* Creamos un nodo. */
	qAux->Elem = e; /* Almacenamos el elemento e. */
	qAux->Sig = NULL;
	if (q->pCab == NULL) /* Si no hay ningun elemento, entonces */    
		q->pCab = qAux; /* pcab apunta al nuevo nodo creado, */
	else /* y sino, */   
		q->pCol->Sig = qAux;/* el nodo nuevo va despues del que apunta pcol. */

	q->pCol = qAux;/* El nuevo nodo pasa a estar apuntado por pcol. */
	return(q); /* Devolvemos un puntero a la cola modificada. */
}   

tCola *Desencolar(tCola *q) {
	tNodo *qAux;
	qAux = q->pCab; /* Guardamos un puntero al nodo a borrar. */
	q->pCab = q->pCab->Sig; /* Actualizamos pCab. */
	if (q->pCab == NULL) /* Si la cola se queda vacia, entonces */  
		q->pCol = NULL; /* actualizamos pCol. */
	free(qAux); /* Liberamos la memoria ocupada por el nodo. */
	return(q); /* Devolvemos un puntero a la cola modificada. */
} 

int ExtraerCabeza(tCola *q) {
	return(q->pCab->Elem);/* Devolvemos el elemento que hay en la cabeza. */
}

int EsColaVacia(tCola *q) {    
	if (q->pCab == NULL)      
		return TRUE;    
	else      
		return FALSE;/* Devolvemos 0 (falso) si la cola no esta vacia y  1 (cierto) en caso contrario. */
}

void VisualizarCola(tCola *p) { 
	tNodo * pAux;  
	pAux = p->pCab; 
	printf("Contenido de la cola:\n"); 
	while (pAux != NULL) {   
		printf("%d\n", pAux->Elem);   
		pAux = pAux->Sig; 
	} 
}









