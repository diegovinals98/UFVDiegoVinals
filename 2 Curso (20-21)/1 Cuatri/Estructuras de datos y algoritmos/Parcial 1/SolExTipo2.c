/*Asignatura Estructuras de Datos y Algoritmos 2020-2021
 *Autor: Mary Luz Mouronte
 *Queda prohibida la reproducción total o parcial fuera del ámbito de la UFV*/


/* LIBRERÍAS ESTÁNDAR*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define OPCION_UNO 1
#define OPCION_DOS 2
#define OPCION_TRES 3
#define OPCION_CUATRO 4
#define MAX_CARACTERES_PALABRA 25

typedef enum {FALSE, TRUE} tBoolean;

typedef enum {EN, PE} tTipo;

typedef struct {
  char Nombre[30];
  tTipo Tipo;
} tElem;

typedef struct _pnodo {
  tElem Elem; /* Variable para almacenar un elemento de la pila. */
  struct _pnodo *Sig;
/* Puntero al siguiente nodo que contiene un elemento. */
} tNodo;
/* Tipo nodo. Cada nodo contiene un elemento de la pila. */

typedef struct {
  tNodo *pCab, *pCol; /* Punteros a la cabeza y la cola. */
} tCola;



typedef tNodo tPila;

tCola *CrearCola();
tCola *Encolar(tCola *q, tElem e);
tCola *InvertirCola (tCola *pCola);
tCola *ColarPerifericos(tCola *pCola);
void VisualizarCola(tCola *p);
void Pausar(void);
void CuantificarTipoElementos (tCola *p);



main (void)
{


  tCola *pCola;
  tElem Elem;
  tBoolean FlgSalir, FlgIntroducir;
  int TipoOperacion;
  char Ch;

  pCola=CrearCola();



  FlgSalir = FALSE;


  while(!FlgSalir)
  {

    printf("Elija la operacion a realizar\n");
    printf("1.Introducir datos en la cola\n");
    printf("2. Cuantificar tipo de componentes e invertir cola. \n");
    printf("3. Colar perifericos.\n");
    printf("4. Salir\n");
    fflush(stdin);
    scanf("%d",&TipoOperacion);

    switch (TipoOperacion)
    {
      case OPCION_UNO:

        printf("Introduzca datos:\n");
        FlgIntroducir = TRUE;
        while (FlgIntroducir == TRUE)
        {
            printf("\n Tipo elemento: ");
            fflush(stdin);
            scanf("%d", &Elem.Tipo);
            printf("\n Elemento: ");
            fflush(stdin);
            scanf("%s", Elem.Nombre);
            pCola=Encolar(pCola, Elem);
            printf("\n ¿Desea introducir otro? [S/s o N/n]\n" );
            fflush(stdin);
            scanf("%c",&Ch);
            if ((Ch != 'S') && (Ch != 's'))
            {
              FlgIntroducir=FALSE;

            }

        }


        VisualizarCola(pCola);
        Pausar();

        break;

        case OPCION_DOS:
          CuantificarTipoElementos(pCola);
          Pausar();
          pCola=InvertirCola(pCola);
          VisualizarCola(pCola);
          Pausar();

        break;


        case OPCION_TRES:
            pCola=ColarPerifericos(pCola);
            VisualizarCola(pCola);
            Pausar();
        break;

        case OPCION_CUATRO:
          printf("Adios");
          FlgSalir=TRUE;

        break;



    }

  }


}


void Pausar(void)
{
  printf("\nPulse una tecla para continuar\n");
  

}




tCola *CrearCola() {

tCola *q;

q = (tCola*) malloc(sizeof(tCola));
q->pCab = NULL;
q->pCol = NULL;

return(q);


}


tCola *Encolar(tCola *q, tElem e) {
tNodo *qAux;
qAux = (tNodo *) malloc(sizeof(tNodo));
qAux->Elem = e;
qAux->Sig = NULL;

if (q->pCab == NULL)
    q->pCab = qAux;
else
   q->pCol->Sig = qAux;


q->pCol = qAux;


return(q);
}


void VisualizarCola(tCola *p) {

 tNodo * pAux;

  pAux = p->pCab;
 printf("Contenido de la cola:\n");
 while (pAux != NULL)
 {
   printf("Tipo: %d\n", pAux->Elem.Tipo);
   printf("Nombre: %s\n", pAux->Elem.Nombre);

   pAux = pAux->Sig;
 }


}

void CuantificarTipoElementos (tCola *p) {

 tNodo * pAux;
 int NumPer, NumNucl;

 NumPer=0;
 NumNucl=0;

  pAux = p->pCab;

 while (pAux != NULL)
 {
   if (pAux->Elem.Tipo == EN)
      NumNucl++;
   else
      NumPer++;



   pAux = pAux->Sig;
 }

   printf("Elementos nucleares %d\n", NumNucl);
   printf("Elementos perifericos %d\n", NumPer);

}

tPila *Apilar(tPila *p, tElem Elem) {
tNodo *pAux;

pAux = (tNodo *) malloc(sizeof(tNodo)); /* Creamos un nodo. */
pAux->Elem= Elem; /* Almacenamos el elemento e. */
pAux->Sig = p; /* El nuevo nodo pasa a ser tope de la pila. */


p = pAux;

return(pAux); /* Devolvemos un puntero al nuevo tope. */
}

tCola *Desencolar(tCola *q) {
tNodo *qAux;

qAux = q->pCab;
q->pCab = q->pCab->Sig;
if (q->pCab == NULL)
  q->pCol = NULL;

free(qAux);
return(q);
}


tElem ExtraerCabeza(tCola *q) {
return(q->pCab->Elem);
}

tPila *Desapilar(tPila *p) {

tNodo *pAux;

pAux = p;
p = p->Sig;

free(pAux);

return(p);
}

tElem DevolverTope(tPila *p) {
return(p->Elem);
}


tCola *InvertirCola (tCola *pCola)
{
    tElem e;
    tPila *pPila;

    pPila = NULL;
    while ((pCola->pCab) !=NULL)
    {
      e= ExtraerCabeza(pCola);
      pCola=Desencolar(pCola);
      pPila=Apilar(pPila, e);
    }

    while (pPila!=NULL)
    {
      e=DevolverTope(pPila);
      pPila=Desapilar(pPila);
      pCola=Encolar(pCola, e);
    }

    return (pCola);
}

tCola *ColarPerifericos(tCola *pCola)
{
    tElem e;
    tCola *pColaAux;
    tNodo *pAux;


    pColaAux = CrearCola();
    pAux=pCola->pCab;


    while (pAux !=NULL)
    {
      if (pAux->Elem.Tipo == EN)
      {

        e.Tipo = pAux->Elem.Tipo;
        strcpy(e.Nombre,pAux->Elem.Nombre);
        pColaAux = Encolar(pColaAux, e);
        if (pAux == pCola->pCab)
          pCola->pCab=pAux->Sig;
        if (pAux->Sig!=NULL)
          pAux->Sig=pAux->Sig->Sig;
        pAux=pAux->Sig;

      }
      else
        pAux=pAux->Sig;
    }



    pCola->pCol->Sig=pColaAux->pCab;
    pCola->pCol=pColaAux->pCol;


    return (pCola);
}




