
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _nodoArbol {
int Elem;
struct _nodoArbol *pHijoIzq;
struct _nodoArbol *pHijoDer;
} tNodoArbol;

void InsertarNodo(tNodoArbol **pArbol, int valor);

void NodosDeNivelDado (tNodoArbol *pArbol, int n);



int main()
{
 int i;
 int Elem;
 tNodoArbol *pRaiz;
 pRaiz = NULL;
 srand(time(NULL));
 int Nivel;

 for (i = 1; i <= 10; i++) {
    Elem = rand() % 100;
    printf("%d ", Elem);
    InsertarNodo(&pRaiz, Elem);
 }




 printf("\n Nivel: ");
 scanf("%d", &Nivel);
 NodosDeNivelDado (pRaiz, Nivel);

}

void NodosDeNivelDado (tNodoArbol *pArbol, int n)
{


    if (n < 0)
      printf("Error\n");

     else
     {
        if (n==0)
        {
          if (pArbol!=NULL)
            printf("%d ", pArbol->Elem);
        }
        else
        {
           if (pArbol!=NULL)
           {
             NodosDeNivelDado (pArbol->pHijoIzq, n-1);
             NodosDeNivelDado (pArbol->pHijoDer, n-1);

           }
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



