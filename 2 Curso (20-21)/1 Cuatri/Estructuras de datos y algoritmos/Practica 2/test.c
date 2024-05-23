#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <stdlib.h>

typedef struct Nodo_Aux{
	int numero;
	struct Nodo_Aux *Sig;
} Nodo;

typedef Nodo Pila;


typedef struct {
Nodo CabezaCol, *FinCol; 
} Cola_;//la cola va de cabeza hacia cola es decir que si va desde cabeza a finCol

typedef Cola_ Cola;//le asignamos un nombre


Pila *Apilar(Pila *Pila_, int numero_);
Pila *Desapilar(Pila *Pila_);
void MostrarPila(Pila *Pila_);

Cola *Encolar(Cola *puntCola, int numero_);
Cola *Desencolar(Cola *puntCola);
void MostrarCola(Cola *puntCola);

int  main(){
	int opcion, opcionSec;//paara menus
	int num;//numero a introducir
	
	Nodo *Pila = NULL;
	
	Cola_ *Cola = NULL;
	Cola = (Cola_*) malloc(sizeof(Cola_));//pido memoria para la cola y así puedo poner el tope y el fin de la cola a NULL
	Cola->CabezaCol = NULL;
	Cola->FinCol = NULL;
	do
	{
		printf("\n1.Gestionar pilas.\n");
		printf("2.Mostrar pilas.\n");
		printf("3.Gestionar colas.\n");
		printf("4.Mostrar colas.\n");
		printf("5.Salir del programa.\n");	
		printf("Introduzca opcion del menu: ");
		scanf("%d", &opcion);
		
		switch(opcion)
		{
			case 1:
				
				printf("\n\t-  >0 (Aniadir Elemento)\n");
				printf("\t-  =0 (Nada)\n");
				printf("\t-  <0 (Eliminar elemento)\n");
				printf("Introduzca un numero entero para elegir opcion ");
				scanf("%d", &opcionSec);
				if(opcionSec > 0){
					opcionSec = 1;
				}
				else if(opcionSec == 0){
					opcionSec = 2;
				}
				else{
					opcionSec = 3;
				}
				switch(opcionSec)
				{
					case 1:
						printf("Introduzca el numero que desea aniadir: ");
						scanf("%d", &num);
						Pila = Apilar(Pila, num);
					break;
					case 2:
					break;
					case 3:
						Pila = Desapilar(Pila);
					break;
				}
			break;
			case 2: 
				MostrarPila(Pila);
			break;
			case 3:
					
				printf("\n\t-  >0 (Aniadir Elemento)\n");
				printf("\t-  =0 (Nada)\n");
				printf("\t-  <0 (Eliminar elemento)\n");
				printf("Introduzca un numero entero para elegir opcion ");
				scanf("%d", &opcionSec);
				if(opcionSec > 0){
					opcionSec = 1;
				}
				else if(opcionSec == 0){
					opcionSec = 2;
				}
				else{
					opcionSec = 3;
				}
				switch(opcionSec)
				{
					case 1:
						printf("Introduzca el numero que desea aniadir: ");
						scanf("%d", &num);
						Cola = Encolar(Cola, num);
					break;
					case 2:
					break;
					case 3:
						Cola = Desencolar(Cola);
					break;
				}
			break;
			case 4: 
				MostrarCola(Cola);
			break;
			case 5:
			break;
			default:
				printf("Error, introduce una opcion correcta. \n");
			break;
				
		}
	}
	while(opcion!=5);
	
}

Pila *Apilar(Pila *Pila_, int num){
	
	Nodo *Aux;
	Aux = (Nodo *) malloc(sizeof(Nodo));//pido memoria para aux
	
	if(Pila_ == NULL){
		
		Aux->numero = num;
		Pila_ = Aux;//pone Aux como primer elemento
		Aux->Sig = NULL;//el siguiente elemento sería Null indicando que así este es el primer elemento de la pila
		
	}
	else{
		
		Aux->numero = num;
		Aux->Sig = Pila_;//se pone pila como el siguiente elemento de aux
		Pila_ = Aux;//así ponemos aux como tope y se "introduce"
		
	}
	return(Aux);
	free(Aux);
}

Cola *Encolar(Cola *puntCola, int num){
	Nodo *Aux;//se crea un Nodo
	Aux = (Nodo *)malloc(sizeof(Nodo));//pide memoria para aux
	
	
	Aux->numero = num;
	Aux->Sig = NULL;//como Aux irá el último no tendrá siguiente elemento por eso lo ponemos a null
	
	if(puntCola->CabezaCol == NULL){
		puntCola->CabezaCol = Aux;//copias en el tope aux, es decir lo pones como el primer elemento, será el primero en salir
	}
	else{
		puntCola->FinCol->Sig = Aux;//introduces después del último elemento de la cola a Aux, es decir como el siguiente elemento de la cola después del último
	}
	puntCola->FinCol = Aux;//Igualamos el final de la cola a Aux, de forma que el último elemento sea el contenido de Aux y por tanto siguiente vuelva a ser Null
	//en caso de que cola estuviera vacía entonces Aux sería cola y cabeza a la vez
	return(puntCola);
	free(Aux);
	
}

Pila *Desapilar(Pila *Pila_){
	Nodo *Aux;
	Aux = (Nodo *) malloc(sizeof(Nodo));
	Aux = Pila_;//igualamos aux a la pila
	if(Aux == NULL){
		printf("\nLa pila esta vacia\n");
	}
	else{
		Aux = Aux->Sig;//pila lo igualamos a los elementos de la pila salvo el tope, para eliminarlo
		return(Aux);
		free(Aux->Sig);		
	}
}

Cola *Desencolar(Cola *puntCola){
	Nodo *Aux;
	Aux = (Nodo *)malloc(sizeof(Nodo));
	Aux = puntCola->CabezaCol;//guardamos en aux el primer elemento en aux
	puntCola->CabezaCol = puntCola->CabezaCol->Sig; //hacemos que ek primer elemento sea el siguiente al actual
	if (puntCola->CabezaCol == NULL) /* Si la cola se queda vacia, entonces */  
	{
		puntCola->FinCol = NULL; /* actualizamos pCol. */
	}
	return(puntCola); /* Devolvemos un puntero a la cola modificada. */
	free(Aux); /* Liberamos la memoria ocupada por el nodo. */
	
}

void MostrarPila(Pila *Pila_){
	Nodo *Aux;
	Aux = (Nodo *) malloc(sizeof(Nodo));
	Aux = Pila_;
	if(Aux == NULL){
		printf("\nLa pila esta vacia\n");
	}
	else{
		
		while(Aux != NULL){
			printf("%d\n", Aux->numero);
			Aux = Aux->Sig;
		}
	
	}
}

void MostrarCola(Cola *puntCola){
	Nodo *Aux;
	Aux = (Nodo *)malloc(sizeof(Nodo));
	Aux = puntCola->CabezaCol;
		if(Aux == NULL){
		printf("\nLa cola esta vacia\n");
	}
	else{
		
		while(Aux != NULL){
			printf("%d\n", Aux->numero );
			Aux = Aux->Sig;
		}
	
	}
	
}