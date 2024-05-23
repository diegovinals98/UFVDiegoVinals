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
#define OPCION_CUATRO 4
#define OPCION_CINCO 5
int finalizador = 0;
int opcion = 0;
int numeroEn = 0;
int numeroPE = 0;


typedef enum {EN, PE} tTipo;



typedef struct {
  tTipo tipo;
  char Nombre[30];
} elemento;

typedef struct _pnodo {
  elemento Elem;
  struct _pnodo *Sig;
} nodo;

typedef nodo pila;

typedef struct {
  nodo *pCab, *pCol; 
} cola;





cola *crearCola();
pila *crearPila();


void introducirDatos(cola *c);
void cuantificarCola(cola *c);
void invertirCola(cola *c);
void colarPerifericos(cola *colaPeriferico , cola *c, pila *nucleares, pila *perifericos);

cola *colaElementos;
cola *nuevaCola;
pila *pilaAuxiliar;
pila *nucleares;
pila *perifericos;


// Menu
int menu (void)
{
  int menu;
  printf("\n\n1. Introducir los Datos.\n");
  printf("2. Cuantificar tipo de componentes e invertir cola.\n");
  printf("3. Colar Perifericos\n");
  printf("4. Salir.\n");
  printf("\nIntroduzca una Opcion (1-4) ");
  scanf("%d" , &menu);
  return menu;
} 

int main() { 

  

  colaElementos = crearCola();
  pilaAuxiliar = crearPila();
  nuevaCola = crearCola();
  nucleares = crearPila();
  perifericos = crearPila();

  while(finalizador == 0){
    opcion = menu();
    switch (opcion) {
      case OPCION_UNO:

        introducirDatos(colaElementos);
        
        
        break;
      
      case OPCION_DOS:
        cuantificarCola(colaElementos);
        printf("La funcion Invertir Cola no me funciona, y me da un error que sale del programa\n");
        printf("Esta en el codigo pero no la llamo, para que el programa no se salga.\n");
        // invertirCola(colaElementos, pilaAuxiliar);
        break;
      
      case OPCION_TRES:
        colarPerifericos(nuevaCola , colaElementos, nucleares, perifericos);
        break;
      
      case OPCION_CUATRO:
       // Finalizado = 1; por lo que sale del bucle
        finalizador = 1;
        printf("Adios.\n");
        break;
        
        
      
      default:
        printf("ERROR: Opcion introducida no valida\n\n");
        break;
    }
    
    
  }
}

cola *crearCola() {

  cola *q;

  q = (cola*) malloc(sizeof(cola)); 
  q->pCab = NULL; 
  q->pCol = NULL;

  return(q); 

}   


cola *Encolar(cola *q,  elemento e) {

  nodo *qAux;

  qAux = (nodo *) malloc(sizeof(nodo)); /* Creamos un nodo. */
  qAux->Elem = e; /* Almacenamos el elemento e. */
  qAux->Sig = NULL;
  if (q->pCab == NULL) /* Si no hay ningun elemento, entonces */    
    q->pCab = qAux; /* pcab apunta al nuevo nodo creado, */
  else /* y sino, */   
    q->pCol->Sig = qAux;/* el nodo nuevo va despues del que apunta pcol. */

  q->pCol = qAux;/* El nuevo nodo pasa a estar apuntado por pcol. */
  return(q); /* Devolvemos un puntero a la cola modificada. */
}   

cola *Desencolar(cola *q) {
  nodo *qAux;
  qAux = q->pCab; /* Guardamos un puntero al nodo a borrar. */
  q->pCab = q->pCab->Sig; /* Actualizamos pCab. */
  if (q->pCab == NULL) /* Si la cola se queda vacia, entonces */  
    q->pCol = NULL; /* actualizamos pCol. */
  free(qAux); /* Liberamos la memoria ocupada por el nodo. */
  return(q); /* Devolvemos un puntero a la cola modificada. */
} 

void VisualizarCola(cola *p) { 
  nodo * pAux;  
  pAux = p->pCab; 
  while (pAux != NULL) {   
    printf("\tNombre: %s\n", pAux->Elem.Nombre);   
    printf("\tTipo: %u\n", pAux->Elem.tipo);   
    pAux = pAux->Sig; 
  } 
}



nodo *crearPila() {
  return(NULL); 
}  


pila *apilar(pila *p, elemento el) {

  nodo *pAux;
  
  pAux = (nodo *) malloc(sizeof(nodo)); 

  pAux->Elem = el; 
  pAux->Sig = p;
  p = pAux;
  
  return(p); 
} 

pila *Desapilar(pila *p) {
  nodo *pAux;
  pAux = p; /* Guardamos un puntero al nodo a borrar. */
  p = p->Sig;/* El nuevo tope sera el nodo apuntado por el tope actual. */
  free(pAux);/* Liberamos la memoria ocupada por el tope actual. */
  return(p); /* Devolvemos un puntero al nuevo tope. */
}

int esPilaVacia(pila *p) {  
  if (p==NULL)     
    return 1;   
  else     
    return 0;/* Devolvemos FALSE si la pila no esta vacia y TRUE en caso contrario. */
}


void introducirDatos(cola *c){
  elemento aux;

  char tipoAuxiliar[30];
  printf("Tipo de Elemento (Nuclear o Periferico).\n");
  scanf("%s", tipoAuxiliar);
  if(!strcmp(tipoAuxiliar, "Nuclear")){
    aux.tipo = EN;
  } 
  if(!strcmp(tipoAuxiliar, "Periferico")){
    aux.tipo = PE;
  }



  printf("Nombre: \n");
  scanf("%s", aux.Nombre);

  if(strcmp(tipoAuxiliar, "Periferico") && strcmp(tipoAuxiliar, "Nuclear")){
    printf("No se ha creado el elemento, por que el tipo introducido no es ninguno de los dos.\n");
  } 

  Encolar(c, aux);
  

  


}

void cuantificarCola(cola *c){

  numeroEn = 0;
  numeroPE = 0;

  nodo * pAux;  
  pAux = c->pCab; 
  while (pAux != NULL) {   
    if(pAux->Elem.tipo == EN){
      numeroEn++;
    } else if(pAux->Elem.tipo == PE){
      numeroPE++;
    }
    pAux = pAux->Sig; 
  } 
  printf("Numero de Elementos Nucleares: %d\n", numeroEn);
  printf("Numero de Elementos Perifericos: %d\n", numeroPE);

}

void invertirCola(cola *c){
    elemento e;
    pila *pPila;

    pPila = NULL;

    while ((pCola->pCab) !=NULL)
    {
      e= ExtraerCabeza(pCola);
      pCola=Desencolar(pCola);
      pPila=apilar(pPila, e);
    }

    while (pPila!=NULL)
    {
      e=DevolverTope(pPila);
      pPila=Desapilar(pPila);
      pCola=Encolar(pCola, e);
    }

    return (pCola);


}

void colarPerifericos(cola *colaPeriferico , cola *c, pila *nucleares, pila *perifericos){
  nodo * pAux;  
  pAux = c->pCab;

  // Dependiendo del tipo, los meto en sus respectivas pilas
  while (pAux != NULL) {   
    if(pAux->Elem.tipo == EN){
      apilar(nucleares, pAux->Elem );
    } else if(pAux->Elem.tipo == PE){
      apilar(perifericos, pAux->Elem);
    }
    pAux = pAux->Sig; 
  } 

  while(!esPilaVacia(perifericos)){
    nodo *pAux2;
    pAux2 = perifericos; /* Guardamos un puntero al nodo a borrar. */
    perifericos = perifericos->Sig;
    Encolar(colaPeriferico, pAux2->Elem);
    Desapilar(pAux2);
  }
  while(!esPilaVacia(nucleares)){
    nodo *pAux2;
    pAux2 = nucleares; /* Guardamos un puntero al nodo a borrar. */
    nucleares = nucleares->Sig;
    Encolar(colaPeriferico, pAux2->Elem);
    Desapilar(pAux2);
  }

  printf("Cola ordenada: \n");
  VisualizarCola(colaPeriferico);



}

tElem ExtraerCabeza(tCola *q) {
return(q->pCab->Elem);
}





