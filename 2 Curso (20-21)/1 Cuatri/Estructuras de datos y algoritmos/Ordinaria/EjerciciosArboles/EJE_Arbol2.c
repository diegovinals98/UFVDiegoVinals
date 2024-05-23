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
int mayor (int n1, int n2);
int CalcularAlturaArbol (tNodoArbol *pArbol);



int main()
{
 int i;
 int Elem;
 tNodoArbol *pRaiz;
 pRaiz = NULL;
 srand(time(NULL));
 int NumHojas;

 for (i = 1; i <= 10; i++) {
    Elem = rand() % 100;
    printf("%d ", Elem);
    InsertarNodo(&pRaiz, Elem);
 }




 printf("\n La altura del arbol es %d\n", CalcularAlturaArbol(pRaiz));

}

int CalcularAlturaArbol (tNodoArbol *pArbol)
{
    if (pArbol != NULL)
    {
         return 1+mayor(CalcularAlturaArbol(pArbol->pHijoIzq), CalcularAlturaArbol(pArbol->pHijoDer));
    }
    else
      return 0;
}

int mayor (int n1, int n2)
{
    if (n1 > n2)
      return n1;
    else
      return n2;
}

void InsertarNodo(tNodoArbol **pArbol, int valor)
{

 if (*pArbol == NULL) {
   *pArbol = (tNodoArbol *) malloc(sizeof(tNodoArbol));
 if (*pArbol != NULL) {
 (*pArbol)->Elem = valor;
 (*pArbol)->pHijoIzq = NULL;
 (*pArbol)->pHijoDer = NULL;
 }
else {
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



