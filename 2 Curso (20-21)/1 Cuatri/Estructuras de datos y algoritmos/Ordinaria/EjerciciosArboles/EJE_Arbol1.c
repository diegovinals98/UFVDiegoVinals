
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
void ContarHojasArbol (tNodoArbol *pArbol, int *Cont);


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

  NumHojas=0;
ContarHojasArbol (pRaiz, &NumHojas);


 printf("\n El arbol tiene %d hojas \n", NumHojas);

}

void ContarHojasArbol (tNodoArbol *pArbol, int *Cont)
{
    if (pArbol!=NULL)
    {
        if ((pArbol->pHijoIzq == NULL) && (pArbol->pHijoDer == NULL))
          (*Cont)=(*Cont)+1;
        else
        {
          ContarHojasArbol (pArbol->pHijoIzq, Cont);
          ContarHojasArbol (pArbol->pHijoDer, Cont);
        }

    }
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



