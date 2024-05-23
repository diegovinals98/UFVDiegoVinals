#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


/* ZONA DE DECLARACIÓN DE CONSTANTES*/
#define NUM 20

typedef struct _pnodo {
  int Elem; /* Variable para almacenar un elemento de la pila. */
  struct _pnodo *Sig;
/* Puntero al siguiente nodo que contiene un elemento. */
} tNodo;
/* Tipo nodo. Cada nodo contiene un elemento de la pila. */


typedef tNodo * tPosicion;
/* Cada posicion se referencia con un puntero. */

typedef struct { /* Definimos el tipo lista con un puntero */
tPosicion Primero, Ultimo; /* al primero y ultimo nodos. */
} tLista;



tLista *CrearLista();
tLista *Insertar(tLista *l, int e, tPosicion p);
tLista *Borrar(tLista *l, tPosicion p);
void VisualizarLista(tLista *p);



void VisualizarLista(tLista *p) {

 tNodo * pAux;

 pAux = p->Primero->Sig;
 printf("Contenido de la cola:\n");
 while (pAux != NULL)
 {
   printf("%d\n", pAux->Elem);
   pAux = pAux->Sig;
 }


}



tLista *CrearLista() {

  tLista *l;

   l = (tLista *) malloc(sizeof(tLista)); /* Creamos una lista. */
  l->Primero = (tNodo *) malloc(sizeof(tNodo));
   /* Creamos el centinela */
  l->Primero->Sig = NULL;
  l->Ultimo = l->Primero;
  return(l); /* Devolvemos un puntero a la lista creada. */
}

/*
 *
 * Función: Insertar
 *
 * inserta e en la posición p+1 de la lista l. Los elementos que estan a partir de la posición p+1
 * se desplazan una posición.
 * Parámetro de entrada:
 * Elemento, Posicion
 * Parámetro de entrada/salida:
 *        Lista.
 * Parámetro de salida:  Lista.
 *
 */

tLista *Insertar(tLista *l, int e, tPosicion p) {

  tPosicion q;
q = p->Sig; /* Dejamos q apuntando al nodo que se desplaza. */
  p->Sig = (tNodo *) malloc(sizeof(tNodo));
/* Creamos un nodo. */

p->Sig->Elem = e; /* Guardamos el elemento. */
  p->Sig->Sig = q;
/* El sucesor del nuevo nodo esta apuntado por q. */
/* Si el nodo insertado ha pasaso a ser el ultimo, */
  if (p == l->Ultimo)
  l->Ultimo = p->Sig; /* actualizamos ultimo. */
    return(l);
/* Devolvemos un puntero a la lista modificada. */
}



/*
 *
 * Función: Borrar
 *
 * Borra el elemento de la posición p de la lista l.
 * Parámetro de entrada:
 * Elemento, Posicion
 * Parámetro de entrada/salida:
 *        Lista.
 * Parámetro de salida:  Lista.
 *
 */


tLista *Borrar(tLista *l, tPosicion p) {

  tPosicion q;
  if (p->Sig == l->Ultimo)
/* Si el nodo que borramos es el ultimo, */
  l->Ultimo = p; /* actualizamos ultimo. */
 q = p->Sig; /* Dejamos q apuntando al nodo a borrar. */
 p->Sig = p->Sig->Sig; /* p->sig apuntara a su sucesor. */
   free(q);
/* Liberamos la memoria ocupada por el nodo a borrar. */
 return(l);
/* Devolvemos un puntero a la lista modificada. */
}


int Recuperar(tLista *l, tPosicion p) {
  return(p->Sig->Elem);
}


