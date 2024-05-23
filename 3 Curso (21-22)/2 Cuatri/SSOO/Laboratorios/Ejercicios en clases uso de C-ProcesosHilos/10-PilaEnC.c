#include <stdio.h>

struct elemento{
   int x;
   int y;
};


struct pila {
   struct elemento *elementos;
   int contador;
   int tope;
};

int crear_pila(struct pila *, int);
int isEmpty(struct pila);
int isFull(struct pila);
int push(struct pila*, struct elemento);
int pop(struct pila*, struct elemento *);

int main(){
   struct pila mipila; 
   if (!crear_pila(&mipila, 10)) {
	  printf("No se pudo crear la pila\n");
	  return -1;
   }

   struct elemento e1;
   e1.x = 0;
   e1.y = 0;
   struct elemento e2;
   e2.x = 1;
   e2.y = 1;
   struct elemento e3;
   e3.x = 2;
   e3.y = 3;
   struct elemento e4;
   e4.x = 3;
   e4.y = 3;
   push(&mipila, e1);
   printf("Apilo primer elemento \n");
   push(&mipila, e2);
   printf("Apilo segundo elemento \n");
   push(&mipila, e3);
   printf("Apilo tercer elemento \n");
   push(&mipila, e4);
   printf("Apilo cuarto elemento \n");

   struct elemento e5; 
   int result = pop(&mipila, &e5);
   return 0;
}

/*
 * Con esta funcion creamos una nueva pila y la retornamos para que el usuario la use */
int crear_pila(struct pila *p, int nro_elementos){

   /* Siempre siempre tenemos que validar las entradas, siempre en este caso decidimos retornar NULL */

   if( nro_elementos < 0) { 
		return 0; 
	}
   
   struct elemento arreglo_elementos[nro_elementos];
   p->elementos = &arreglo_elementos;
   p->tope = nro_elementos - 1;
   p->contador = 0;
   return 1;
}

int push(struct pila *p, struct elemento elem){
   /*
    * Nuevamente validamos las entradas, la pila no puede ser NULL
    */
   if (p == NULL ) {return -1;}
   
   /* Comprobamos si la pila esta llena, esto quiere decir,
    * que con este elemento estaria superando el tope
    * si es asi retorno un error;
    */
   if (isFull(*p) == 1) { return -2; }

   p->elementos[p->contador] = elem;

   /*
    * Acabamos de introducir un elemento nuevo en la pila asi que el contador
    * debe aumentar
    */
   p->contador++;

   // Todo salio bien? retornamos 1
   return 1;
}

int pop(struct pila *p, struct elemento *e){
   /*
    * Validaciones validaciones, la pila es null?
    */
   if (p == NULL) { return -1; }
   // La pila esta vacia?
   if (isEmpty(*p)) { return -2; }

   struct elemento resp = (*p).elementos[(*p).contador - 1 ];
   p->contador--;

   e->x = resp.x;
   e->y = resp.y;
   return 1;
   
}

/* 
 * Comprobamos si la pila esta vacia.
 */
int isEmpty(struct pila p){
   if(p.contador == 0) {return 1;}
   return 0;
}

/* 
 * Comprobamos si la pila esta llena.
 */
int isFull(struct pila p){
   if(p.contador > p.tope) {return 1;}
   return 0;
}

/*
 * Cuantos elementos hay en la pila?
 */
int count (struct pila p){
   return p.contador;
}
