#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>



#define MAX_CARACTERES 15000
#define MAX_CIUDAD 100
#define MAX_PAIS 100
#define MAX_ALUMNO 150
#define NOM_FICHERO "cal.csv"
#define CORRECTO 0
#define ERROR_LECT_FICHERO 1
#define ERR_ELE_NO_ENCONTRADO 2
#define ORD_QUICKSORT 0
#define ORD_SEL_DIRECTA 1
#define ORD_BURBUJA 2
#define OPCION_UNO 1
#define OPCION_DOS 2
#define OPCION_TRES 3
#define OPCION_CUATRO 4
#define SEPARADOR ";"

typedef struct {
	int numero;
	int dia;
	int mes;
	int anyo;
} contratos;

char linea[MAX_CARACTERES];
contratos listaContratos[MAX_CARACTERES];
char *ptrtoken;
int contadorContratos = 0;
int finalizador = 0;
int opcion = 0;
char fichero1[MAX_CARACTERES];
FILE *pfich1;
contratos auxiliar;
int mitad = 0;


int LeerFicheroE (char NomFichero[], contratos *c)
{

    // abrimos el fichero NomFichero
    pfich1 = fopen(NomFichero , "r");
    if(pfich1 == NULL){
        printf("Error al abrir el archivo\n\n");
        exit(ERROR_LECT_FICHERO);
    } else {
        printf("Lectura de fichero Empleados correcta.\n");
         // Mientras que haya lieneas, coge cada linea y hace lo de dentro del while
        while(fgets(linea, 100,  pfich1)){
            // Por cada separacion (;) lo separa y lo almacena segun corresponda
            ptrtoken = strtok(linea, SEPARADOR);
            if(ptrtoken != NULL){
                c[contadorContratos].numero = strtol(ptrtoken,NULL,10);
            }
            if((ptrtoken = strtok(NULL, SEPARADOR)) != NULL){
                c[contadorContratos].dia = strtol(ptrtoken,NULL,10);
            } 
            if((ptrtoken = strtok(NULL, SEPARADOR)) != NULL){
                c[contadorContratos].mes = strtol(ptrtoken,NULL,10);
            }
            if((ptrtoken = strtok(NULL, SEPARADOR)) != NULL){
                c[contadorContratos].anyo = strtol(ptrtoken,NULL,10);
            }
            contadorContratos++;
        }
    }
    // cerramos el archivo y si nos da error, lo imprimimos
    if(fclose(pfich1) != 0){
        printf("Error al cerrar el archivo.\n");
        exit(ERROR_LECT_FICHERO);
    }
    return 0;
}

void imprimir(contratos *c){
	for(int i = 0 ; i< contadorContratos ; i++){
		printf("Numero: %d\n",c[i].numero);
		printf("Dia: %d\n",c[i].dia);
		printf("Mes: %d\n",c[i].mes);
		printf("Anyo: %d\n",c[i].anyo);
	}
}

int menu (void){
  int menu;
  printf("\n\n1. Introducir Datos \n");
  printf("2. Ordenar por fechas.\n");
  printf("3. Buscar por fecha\n");
  printf("4. Salir del programa.\n");
  printf("\nIntroduzca una Opcion (1-4) ");
  scanf("%d" , &menu);
  return menu; 
}


int fecha1menorqueFecha2(contratos contrato1 , contratos contrato2){

	if(contrato1.anyo < contrato2.anyo){
		return 1;
	}
	else if(contrato1.anyo == contrato2.anyo && contrato1.mes < contrato2.mes){
		return 1;
	}
	else if(contrato1.anyo == contrato2.anyo && contrato1.mes == contrato2.mes && contrato1.dia < contrato2.dia){
		return 1;
	}else {
		return 0;
	}
}

void intercambiar(contratos *a, contratos *b) {
  contratos temporal = *a;
  *a = *b;
  *b = temporal;
}

int Partir (contratos *v, int primero, int ultimo)
{
// Elegimos el pivote, es el primero
  contratos pivote = v[primero];
  // Ciclo infinito
  while (1) {
    // Mientras cada elemento desde la primero esté en orden (sea menor que el
    // pivote) continúa avanzando el índice
    while ( fecha1menorqueFecha2(v[primero] , pivote)) {
      primero++;
    }
    // Mientras cada elemento desde la ultimo esté en orden (sea mayor que el
    // pivote) continúa disminuyendo el índice
    while (!fecha1menorqueFecha2(v[ultimo] , pivote)) {
      ultimo--;
    }
    /*
    Si la primero es mayor o igual que la ultimo significa que no
    necesitamos hacer ningún intercambio
    de variables, pues los elementos ya están en orden (al menos en esta
    iteración)
    */
    if (primero >= ultimo) {
      // Indicar "en dónde nos quedamos" para poder dividir el v de nuevo
      // y ordenar los demás elementos
      return ultimo;
    } else {//Nota: yo sé que el else no hace falta por el return de arriba, pero así el algoritmo es más claro
      /*
      Si las variables quedaron "lejos" (es decir, la primero no superó ni
      alcanzó a la ultimo)
      significa que se detuvieron porque encontraron un valor que no estaba
      en orden, así que lo intercambiamos
      */
      intercambiar(&v[primero], &v[ultimo]);
      /*
      Ya intercambiamos, pero seguimos avanzando los índices
      */
      primero++;
      ultimo--;
    }
    // El while se repite hasta que primero >= ultimo
  }

}
void QuickSort(contratos *v, int izda, int dcha)
{

  if (izda < dcha) {
    int indiceParticion = Partir(v, izda, dcha);
    QuickSort(v, izda, indiceParticion);
    QuickSort(v, indiceParticion + 1, dcha);
  }
} 

void Burbuja (contratos *p, int l, int r){

	for(int i = l ; i < r ; i++){
		for(int j = r - 1 ; j >= i ; j--){
			
			if(!fecha1menorqueFecha2(p[j] , p[j+1])) {
				intercambiar(&p[j] , &p[j+1]);
			}
		}
	}
}

int busquedaBinariaRecursiva(contratos *c , contratos buscar, int izquierda, int derecha){
    if (izquierda > derecha) return -1;

    	int indiceDeLaMitad = floor((izquierda + derecha) / 2);
    	contratos valorQueEstaEnElMedio = c[indiceDeLaMitad];

    
    
    if(valorQueEstaEnElMedio.anyo == buscar.anyo){
		if(valorQueEstaEnElMedio.mes == buscar.mes){
			if(valorQueEstaEnElMedio.dia == buscar.dia){
				printf("Se ha enontrado el Contrato: \n");
  				printf("Numero de Contrato: %d\n", valorQueEstaEnElMedio.numero);
  				printf("Fecha: %d/%d/%d" , valorQueEstaEnElMedio.dia , valorQueEstaEnElMedio.mes, valorQueEstaEnElMedio.anyo);
			}
		}
	}

    if (fecha1menorqueFecha2(buscar , valorQueEstaEnElMedio)){
        // Entonces está hacia la izquierda
        derecha = indiceDeLaMitad - 1;
    }else{
        // Está hacia la derecha
        izquierda = indiceDeLaMitad + 1;
    }
    return busquedaBinariaRecursiva(c, buscar, izquierda, derecha);
}





int main() {

	strcpy(fichero1 , "fich00.txt");
	while(finalizador == 0){
	    opcion = menu();
	    switch (opcion) {
	      case OPCION_UNO:
	      	LeerFicheroE(fichero1,listaContratos);
	     	break;

	     case OPCION_DOS:
	     	Burbuja(listaContratos , 0, contadorContratos);
	     	// Lo dejo comentado, por que me da error y no me da tiempo a solucionarlo, 
	     	// por esi he usado el metdo burbuja, a parte de que a estas medidas, no hay diferencia de eficacia.
	     	// QuickSort(listaContratos , 0 , contadorContratos);
	     	imprimir(listaContratos);
	    	break;

	    case OPCION_TRES:
	    	printf("Dia Del contrato que se quiere buscar: \n");
	    	scanf("%d" , &auxiliar.dia);
	    	printf("Mes Del contrato que se quiere buscar: \n");
	    	scanf("%d" , &auxiliar.mes);
	    	printf("Anyo Del contrato que se quiere buscar: \n");
	    	scanf("%d" , &auxiliar.anyo);
	    	busquedaBinariaRecursiva(listaContratos , auxiliar, 0, contadorContratos);
	    	


	    	break;

	    case OPCION_CUATRO:
	        // Finalizado = 1; por lo que sale del bucle
		    finalizador = 1;
		    printf("Adios.\n");
		    break;
	    default:

	    	printf("ERROR: Opcion introducida no valida\n\n");
	  }

	}
}