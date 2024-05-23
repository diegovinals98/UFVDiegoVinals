/*EDA Curso 2020-2021 
 * PRACTICA 3 PARTE 2
 */

/** 
 * Crea un arbol binario y lo recorre en
 * preorden, inorden, y en postOrden 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OPCION_UNO 1
#define OPCION_DOS 2
#define OPCION_TRES 3

/* estructura autoreferenciada */
typedef enum {FALSE, TRUE} tBoolean;

struct NodoArbol { 
	struct NodoArbol *pIzq; 
	int Dato;
	struct NodoArbol *pDer; 
};

typedef struct NodoArbol tNodoArbol; /* sinonimo de la estructura NodoArbol */
typedef tNodoArbol *tpNodoArbol; 
int finalizador = 0;
int opcion = 0;
int numeroOpciones = 0;
int valor = 0;
int alturaArbol = 0;
tNodoArbol *pRaiz;



/* prototipos */
void InsertarNodo(tpNodoArbol *pArbol, int Valor);
int menu (void);
tBoolean comprobarSumaClavesDosNiveles (tNodoArbol *pArbol, int nivel);
int suma (tNodoArbol *arbol, int n1, int n2, int nivel);




/* inserta un nodo dentro del árbol */
void InsertarNodo( tpNodoArbol *pArbol, int valor )
{ 
	if (*pArbol == NULL) {
		*pArbol = (tNodoArbol *) malloc(sizeof(tNodoArbol));
		if (*pArbol != NULL) {
			(*pArbol)->Dato = valor;
			(*pArbol)->pIzq = NULL;
			(*pArbol)->pDer = NULL;
		}
		else {
			printf("No insertado %d. No hay memoria disponible.\n", valor);
		}
	}
/*Si ya hay Datoentos en el árbol*/
	else {
 /* el dato a insertar es menor que el dato en el nodo actual */
		if (valor < (*pArbol)->Dato) {
			InsertarNodo(&((*pArbol)->pIzq), valor);
		}
		else if (valor > (*pArbol)->Dato) {
			InsertarNodo(&((*pArbol)->pDer), valor);
		}
		else {
			printf(" No se puede insertar para respetar criterio. ");
		}
	}
} 

// Menu
int menu (void)
{
	 int menu;
  printf("\n\n1. Crear arbol binario de busqueda. \n");
  printf("2. Comprobar suma de claves\n");
  printf("3. Salir del programa.\n");
  printf("\nIntroduzca una Opcion (1-3) ");
  scanf("%d" , &menu);
  return menu; 
}

int suma (tNodoArbol *arbol, int n1, int n2, int nivel) 
{
   /* A RELLENAR POR EL ALUMNO*/
	return 1;
}

// Devuelve el numero mayor 
int mayor (int n1, int n2)
{
    if (n1 > n2)
      return n1;
    else
      return n2;
}

// Devuelve la altura del arbol
int CalcularAlturaArbol (tNodoArbol *pArbol)
{
    if (pArbol != NULL)
    {
         return 1+mayor(CalcularAlturaArbol(pArbol->pIzq), CalcularAlturaArbol(pArbol->pDer));
    }
    else
      return 0;
}

tBoolean comprobarSumaClavesDosNiveles (tNodoArbol *pArbol, int nivel) 
{
  
    if(CalcularAlturaArbol(pArbol) == nivel)
		return TRUE;
    else
    	return FALSE;
}


int main()
{ 
 while(finalizador == 0){
    opcion = menu();
    switch (opcion) {
      case OPCION_UNO:
      		
	      	while(numeroOpciones < 10){
	      		printf("Escriba un numero:\n");
	      		scanf("%d" ,&valor);
	      		InsertarNodo(&pRaiz, valor);
	      		numeroOpciones++;
	      	}    
	      	numeroOpciones = 0;
	        break;
      
      case OPCION_DOS:
        printf("%d\n", CalcularAlturaArbol(pRaiz) );
      		
        
        
        break;
      
      case OPCION_TRES:
        // Finalizado = 1; por lo que sale del bucle
        finalizador = 1;
        printf("Adios.\n");
        
        
        break;
   
        
      default:
      
        printf("ERROR: Opcion introducida no valida\n\n");
    
    }
    
  }
}


