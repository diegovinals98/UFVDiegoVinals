/**
 * Crea un arbol binario de búsqueda y lo recorre en
 * preorden, inorden, y en postOrden
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _nodoArbol {
int Elem;
struct _nodoArbol *pHijoIzq;
struct _nodoArbol *pHijoDer;
} tNodoArbol;

void InsertarNodo(tNodoArbol **pArbol, int valor);
void inOrden(tNodoArbol *pArbol);
void preOrden(tNodoArbol *pArbol);
void postOrden(tNodoArbol *pArbol);

int main()
{
 int i;
 int Elem;
 tNodoArbol *pRaiz;
 pRaiz = NULL;
 srand(time(NULL));

 for (i = 1; i <= 10; i++) {
    Elem = rand() % 100;
    printf("%d ", Elem);
    InsertarNodo(&pRaiz, Elem);
 }

  printf("\n Recorrido en InOrden \n");
  inOrden(pRaiz);

  printf("\n Recorrido en PreOrden \n");
  preOrden(pRaiz);

  printf("\n Recorrido en PostOrden \n");
  postOrden(pRaiz);



}

void InsertarNodo(tNodoArbol **pArbol, int valor)
{


// Creamos el arbol si este esta vacio
 if (*pArbol == NULL) {
   *pArbol = (tNodoArbol *) malloc(sizeof(tNodoArbol));
 if (*pArbol != NULL) {
      (*pArbol)->Elem = valor;
      (*pArbol)->pHijoIzq = NULL;
      (*pArbol)->pHijoDer = NULL;
 } else {
  printf("No insertado %d. No hay memoria disponible.\n", valor);
  }
}
/*Si ya hay elementos en el árbol*/
else {
 /* el dato a insertar es menor que el dato en el nodo actual */
  if (valor < (*pArbol)->Elem) {
     InsertarNodo(&((*pArbol)->pHijoIzq), valor);
  }
  else if (valor > (*pArbol)->Elem) {
    InsertarNodo(&((*pArbol)->pHijoDer), valor);
  }
  else {
     printf(" No se puede insertar para respetar criterio. ");
  }
}

}

void inOrden(tNodoArbol *pArbol)
{


 if (pArbol != NULL) {

   printf("LL: %d \n", pArbol->Elem);
   inOrden(pArbol->pHijoIzq);
   printf("%d ", pArbol->Elem);
   inOrden(pArbol->pHijoDer);
 }
}

void preOrden(tNodoArbol *pArbol)
{
 /* si el árbol no está vacío, entonces lo recorremos */
 if (pArbol != NULL) {
 printf("LL: %d \n", pArbol->Elem);
 printf("%d ", pArbol->Elem);
 preOrden(pArbol->pHijoIzq);
 preOrden(pArbol->pHijoDer);
 }
}

void postOrden(tNodoArbol *pArbol)
{
 /* si el árbol no está vacío, entonces lo recorremos */
 if (pArbol != NULL) {
 printf("LL: %d \n", pArbol->Elem);
 postOrden(pArbol->pHijoIzq);
 postOrden(pArbol->pHijoDer);
 printf("%d ", pArbol->Elem);
 }
}

