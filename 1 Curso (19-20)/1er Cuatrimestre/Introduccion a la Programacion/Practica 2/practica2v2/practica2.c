//  Viñals Lage, Diego
//  Ruiperez Ojea, Gonzalo

// Practica 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define MAX_CAD 100

// Creamos la estructura de Persona para almacenar los datos del nombre, edad, nacionalidad y alias
struct persona{
    char nombre[MAX_CAD];
    int edad;
    char nacionalidad[MAX_CAD];
    char alias[MAX_CAD];
};

// Implementamos todas las funciones que vamos a usar en el prrograma
void flush(void);
void restaurarUniverso(struct persona universo[], int capacidad_max, struct persona eliminados[]);
int chascar(struct persona universo[] , int capacidadUniverso , struct persona eliminados[]);
int sumaletrasnombre(char nombre[]);
int chascarInverso(struct persona universo[], int capacidad_max, struct persona eliminados[]);
void crearPersona(struct persona universo[], int capacidad_max);
void mostrarUniverso(struct persona universo[] , int capacidad_max);
int insertarPersona(struct persona universo[], int capacidad_max, struct persona nueva);
int personaMostrador(struct persona mostrador[], int capacidad_max, struct persona nueva, int posicion);
void eliminarElemento(struct persona universo[], int capacidad_max, int elem);
void ordenarUniverso (struct persona universo[] , int capacidad_max);
int aleat();

// El main, lo que se ejecuta
int main() {
    
    // Definimos que la capacidad del Universo es 1000, aunque puede ser cualquier numero
    int capacidadUniverso = 1000;
    
    // Definimos un array de structuras persona, que sera nuestro universo
    struct persona universo[capacidadUniverso];
    
    // Llenamos el array creado anteriormente de guiones en los campos de texto
    // y de -1 en los numericos
    for(int i = 0 ; i < capacidadUniverso ; i++){
        strcpy(universo[i].nombre, "-");
        strcpy(universo[i].nacionalidad, "-");
        strcpy(universo[i].alias, "-");
        universo[i].edad = -1;
    }
    
    // Creamos otro universo paralelo que es donde van a estar las personas eliminadas
    struct persona eliminados[capacidadUniverso];
    
    // Lo llenamos de guiones y de -1 como en el array universo
    for(int i = 0 ; i < capacidadUniverso ; i++){
        strcpy(eliminados[i].nombre, "-");
        strcpy(eliminados[i].nacionalidad, "-");
        strcpy(eliminados[i].alias, "-");
        eliminados[i].edad = -1;
    }
    
    // declaramos la variable que almacena el numero de ejercicio
    int ejercicio = 0;
    // Variable para poder luego finalizar el programa
    int finalizador = 1;
    
    // Con este do while y el switch, llamaremos a una funcion u otra dependiendo del ejercicio que haya dicho el usuario
    do{
        
        printf("1. Crear Persona\n2. Mostrar Universo\n3. Thanos Chascar\n4. Restaurar Universo\n5. Salir\n");
        // Le preguntamos al usuario que escoja un ejercicio
        printf("\nIntroduzca una Opcion: ");
        scanf("%d" , &ejercicio);
        flush();
        
        switch (ejercicio) {
            case 1:
                // Llamamos al ejercicio 1
                crearPersona(universo, capacidadUniverso);
                break;
            case 2:
                // Llamamos al ejercicio 2
                mostrarUniverso(universo, capacidadUniverso);
                break;
                
            case 3:
                // Llamamos al ejercicio 3
                chascar(universo, capacidadUniverso, eliminados);
                break;
                
            case 4:
                // Llamamos al ejercicio 3 Opcional
                restaurarUniverso(universo, capacidadUniverso , eliminados);
                break;
            case 5:
            default:
                // Finalizador es 0, por lo tanto las condicioned del while no se cumple y finaliza el programa
                finalizador = 0;
                break;
        }
        
        if(ejercicio < 1 || ejercicio > 5){
            printf("ERROR: Opcion introducida no valida\n");
        }
    } while(ejercicio < 1 || ejercicio > 5 || finalizador != 0);
    
}

// Esta es la funcion que inserta una persona en el universo.
int insertarPersona(struct persona universo[], int capacidad_max, struct persona nueva){
    
    // Con este while loop lo que hacemos es comprobar el primer espacio en blanco que hay en el universo
    // para poder meter la persona en ese hueco libre.
    // Los espacios en blanco son las personas con guion en los campos de texto y -1 en los numericos
    // po
    int i = 0;
    while(strcmp(universo[i].nombre , "-") && strcmp(universo[i].alias , "-") && strcmp(universo[i].nacionalidad , "-") && universo[i].edad != -1 && (i < capacidad_max)){
        i++;
    }
    
    // Aqui, sabiendo el hueco libre que hay, que es i, anadimos la persona nueva al universo
    strcpy(universo[i].nombre , nueva.nombre);
    strcpy(universo[i].nacionalidad , nueva.nacionalidad);
    strcpy(universo[i].alias , nueva.alias);
    universo[i].edad = nueva.edad;
    
    return 0;
}

// Esta funcion lo que hace es crear una nueva persona. Luego usaremos la funcion anterior para anadirla al universo
void crearPersona(struct persona universo[] , int capacidad_max){
    // Creamos una persona temporal, para luego meterla en nuestra funcion insertar Persona
    struct persona temporal;
    
    // Le pedimos al usuario que nos diga el Nombre, Nacionalidad, Edad y Alias de la persona
    printf("\nIntroduce Nombre: ");
    gets(temporal.nombre);
    printf("\n\nIntroduce Edad: ");
    scanf("%d" , &temporal.edad);
    flush();
    printf("\n\nIntroduce Nacionalidad: ");
    gets(temporal.nacionalidad);
    printf("\n\nIntroduce Alias: ");
    gets(temporal.alias);
    printf("\n");
    
    // Este int lo usaremos para comprobar si esa persona ya esta en el universo
    // lo que haremos es comparar el nombre de la persona creada con los nombres de todas las
    // personas que estan en el universo, si no coincide con nadie, lo dejamos como esta,
    // si coincide con alguien que ya esta en el universo entonces lo igualaremos a 1.
    int comprobador = 0;
    
    // Aqui contamos el numero de personas que hay en el universo,
    // para saber si el universo esta completo, si esta completo, no se creara la persona
    int contador = 0;
    for(int i = 0 ; i < capacidad_max ; i++){
        if(strcmp(universo[i].nombre , "-") && strcmp(universo[i].alias , "-") && strcmp(universo[i].nacionalidad , "-") && universo[i].edad != -1)
            contador++;
    }
    
    // creamos una string vacia para meter aqui la palabra de la nueva persona en minusculas
    char temporalMinusculas[strlen(temporal.nombre)];
    
    // hacemos un loop para convertir esta palabra a todo minusculas, para que asi sea mas facil de comparar.
    for(int j = 0 ; j < strlen(temporal.nombre); j++){
        temporalMinusculas[j] = tolower(temporal.nombre[j]);
    }
    
    // hacemos un loop para convertir cada palabra del universo en minusculas y comprarla con el nombre de
    // la nueva persona, si no coinciden, pasamos a comprobar a la siguiente persona.
    for(int i = 0; i < capacidad_max; i++){
        char enMinusculas[strlen(universo[i].nombre)];
        
        // Aqui es donde pasamos a minusculas
        for(int j = 0 ; j < strlen(universo[i].nombre); j++){
            enMinusculas[j] = tolower(universo[i].nombre[j]);
        }
        
        // y aqui es donde comparamos los dos nombres.
        // como he dicho antes, si son iguales entonces igualamos el comprobador a 1
        if(!strcmp(enMinusculas, temporalMinusculas) || contador >= capacidad_max){
            comprobador = 1;
        }
    }
    
    // Una vez recorrido toda el universo y comparado todos los nombres con el de la persona nueva.
    // Si el comprobador nos da 0, quiere decir que ningun nombre a coincidido, es decir, esa persona no existe en el universo
    // por lo tanto, llamamos a la funcion instertarPersona() para insertarla en el universo.
    // Si nos da distinto de 0, quiere decir que esa persona ya existe.
    // No la anadimos al universo e imprimimos el mensaje de error.
    if(comprobador == 0){
        insertarPersona(universo , 1000 , temporal);
        printf("Persona creada en el universo\n\n");
        
    }else
        printf("ERROR: no se puede crear la persona en el universo\n\n");
}

// Esta funcion lo que hace es mostarnos el universo en pantalla
void mostrarUniverso(struct persona universo[], int capacidad_max){
    
    ordenarUniverso(universo, capacidad_max);
    // Comprobamos cuantas personas existen en el universo
    int contador = 0;
    for(int i = 0 ; i < capacidad_max ; i++){
        if (strcmp(universo[i].nombre , "-")){
            contador++;
        }
    }
    
    // Si el contador es distinto de 0, quiere decir que por lo menos una persona existe, asi que tenemos que imprimir en pantalla
    // la tabla del universo.
    
    if(contador != 0){
        printf("\n\n%s\t%-35s%-25s\t%-20s%10s\n=========================================================================================================\n" , "#pers" , "Nombre" , "Alias" , "Nacionalidad" , "Edad");
        for(int j = 0 ; j < 1000 ; j++){
            if(strcmp(universo[j].nombre , "-") && strcmp(universo[j].alias , "-") && strcmp(universo[j].nacionalidad , "-") && universo[j].edad != -1){
                printf("%d\t%-35s%-25s\t%-20s%10d\n" , j + 1 , universo[j].nombre , universo[j].alias, universo[j].nacionalidad , universo[j].edad);
            }
        }
        
    }else // si nos da 0, como en este else, quiere decir que no existe nadie en el universo, por lo tanto no ponemos
        // la tabla y ponemos en pantalla que el universo no esta habitado
        printf("Universo no habitado\n");
    
    printf("\n\n\n");
}

// Esta funcion lo que hace es eliminar a personas del universo de forma aleatoria y meterlas en el universo de las
// personas eliminadas.
int chascar(struct persona universo[] , int capacidadUniverso , struct persona eliminados[]){
    
    // Pasamos por todos los elementos del universo y si el nombre es distinto de guion
    // entonces le aplicamos la formula dada.
    for(int x = 0; x < capacidadUniverso; x++){
        if(strcmp(universo[x].nombre , "-") && strcmp(universo[x].alias , "-") && strcmp(universo[x].nacionalidad , "-") && universo[x].edad != -1){
            int valor = sumaletrasnombre(universo[x].nombre) * universo[x].edad * aleat();
            // si el valor es 0, entonces eliminamos esa persona
            if(valor == 0){
                // copiamos la persona del universo en el universo de los eliminados
                // y la borramos del universo con la funcion eliminarElemento
                eliminados[x] = universo[x];
                eliminarElemento(universo , capacidadUniverso , x);
            }
        }
    }
    
    // En este loop vamos a comprar cuantas personas hemos eliminado
    int contadorEliminados = 0;
    for(int i = 0; i < capacidadUniverso ; i++){
        if(strcmp(eliminados[i].nombre , "-") && strcmp(eliminados[i].alias , "-") && strcmp(eliminados[i].nacionalidad , "-") && eliminados[i].edad != -1){
            contadorEliminados++;
        }
    }
    
    // En este if vemos si eisten personas eliminadas ( es decir contador de personas eliminadas > 0)
    if(contadorEliminados != 0){
        ordenarUniverso(eliminados, capacidadUniverso);
        // si solo se ha eliminado una persona ponemos en pantalla que se ha eliminado solo 1
        if(contadorEliminados == 1){
            printf("Se ha eliminado 1 persona del mundo\n\n");
            printf("[%s]\n\n", eliminados[0].nombre);
        }else {
            
            // Si se han eliminado varias lo ponemos con el prinft
            printf("Se ha eliminado %d personas del mundo\n\n", contadorEliminados);
            
            // Nos creamos una nueva lista, que sera la lista de eliminados pero solo con
            // las personas, sin los huecos vacios
            struct persona imprimirEliminados[contadorEliminados];

            for(int i = 0 ; i <=  capacidadUniverso ; i++){
                if(strcmp(eliminados[i].nombre , "-") && strcmp(eliminados[i].alias , "-") && strcmp(eliminados[i].nacionalidad , "-") && eliminados[i].edad != -1)
                    imprimirEliminados[i] = eliminados[i];
            }
            
            // Aqui imprimimos en formato vector el nombre de las personas que pertenecen
            // al universo de las personas eliminadas
            printf("[");
            for(int i = 0 ; i < contadorEliminados - 1 ; i++){
                printf("%s, ", imprimirEliminados[i].nombre);
            }
            printf("%s]\n\n", imprimirEliminados[contadorEliminados - 1].nombre);
        }
    }else
        // si no se ha eliminado a nadie, ponemos en pantalla el mensaje de error.
        printf("ERROR: no se ha eliminado a nadie\n\n");
    
    return 0;
}

// Esta funcion es una funcion que suma los valores ASCII de cada letra de una palabra dada.
// La usaremos para ver que persona se elimina y cual no.
int sumaletrasnombre(char nombre[]){
    
    // Calculamos la longitud de la palabra
    int longitud = strlen(nombre);
    // Con esta variables es donde guardaremos la suma de los valores
    int sumaLetras = 0;
    // Sumamos los valores
    for(int i = 0 ; i < longitud ; i++){
        sumaLetras = sumaLetras + nombre[i];
    }
    
    return sumaLetras;
}

// funcion que nos devuelve un numero alatorio entre 0 y 1
int aleat(){
    srand(time(NULL));
    return rand() % 2;
}

// Esta funcion es la que hace el chasquido inverso
int chascarInverso(struct persona universo[], int capacidad_max, struct persona eliminados[]){
    // con este loop lo que hacemos es sumar 5 anos a las personas no eliminadas
    for(int i = 0; i < capacidad_max ; i++){
        if(strcmp(universo[i].nombre , "-") && strcmp(universo[i].alias , "-") && strcmp(universo[i].nacionalidad , "-") && universo[i].edad != -1)
            universo[i].edad = universo[i].edad + 5;
    }
    
    // Creamos un contador, que cuenta el numero de personas restaruadas,
    // esto es lo que devolvera la funcion, para que la funcion restaurarUniverso() compruebe el numero
    // e imprima el numero y luego el universo
    int contadorRestaurar = 0;
    for(int i = 0 ; i < capacidad_max ; i++){
        for(int j = 0 ; j < capacidad_max ; j++){
            if(universo[i].edad == -1 && eliminados[j].edad != -1){
                // Pasamos la persona eliminada al universo y luego la borramos
                // del universo eliminado
                universo[i] = eliminados[j];
                eliminarElemento(eliminados, capacidad_max, j);
                contadorRestaurar++;
            }
        }
    }
    
    return  contadorRestaurar;
}

// Esta funcion lo que hace es restaurar el universo
// Comprobamos el numero de personas retauradas y dependiendo de ese numero haremos una cosa u otra
void restaurarUniverso(struct persona universo[], int capacidad_max, struct persona eliminados[]){
    
    // En esta variable guardamos el numero de personas restauradas
    int Restaurados = chascarInverso(universo, capacidad_max, eliminados);
    
    // si es 0, damos el mensaje de que nadie se ha restaurado
    if(Restaurados == 0)
        printf("ERROR: no se ha restaurado a nadie\n\n");
    // si es 1, damos el mensaje de que se ha restaurado 1 sola persona
    else if(Restaurados == 1)
        printf("Se ha restaurado 1 persona\n\n");
    else
        // si es mayor que 1, damos el mensaje, e imprimos el numero de personas restauradas
        printf("Se han restaurado %d personas", Restaurados);
    
    // Mostramos el universo con las personas restauradas anadidas.
    mostrarUniverso(universo, capacidad_max);
}

// Funcion que limpia el buffer de entrada
void flush(){
    while (getchar() != '\n')
        ;
}

// funcion que elimina cualquer elemento de un array de personas
void eliminarElemento(struct persona universo[], int capacidad_max, int elem){
    
    // Lo que hacemos es empezar el for con el indice de la persona que queremos borrar
    // e igualamos el siguente a si mismo, asi, con todos los siguientes al elemento que queremos borrar
    for(int i = elem; i < capacidad_max; i++){
        universo[i]= universo[i+1];
    }
    
    // como el ultimo elemento nos queda undefined y puede ser cualquier cosa
    // metemos a esa persona los valores del hueco vacio, guiones y -1
    strcpy(universo[capacidad_max -1].nombre,  "-");
    strcpy(universo[capacidad_max-1].nacionalidad,  "-");
    strcpy(universo[capacidad_max-1].alias,  "-");
    universo[capacidad_max-1].edad = -1;
}

// Funcion que ordena el universo
void ordenarUniverso (struct persona universo[] , int capacidad_max){
    
    int i = 0;
    int j = 0;
    int r = 0;
    
    // Creamos una persona auxuliar para poder intercambiar de posicion 
    // las personas
    struct persona auxiliar;
    
    for (i = 0; i < capacidad_max - 1; i++)
        for (j = i + 1; j < capacidad_max; j++){
            r = strcmp(universo[i].alias, universo[j].alias);
            if (r > 0 && universo[i].edad != -1 && universo[j].edad !=-1){
            	// si existen personas y r es mayor que 0,
            	// Intercambiamos las personas.
            	// Hacemos esto con todas las personas del universo
                auxiliar = universo[i];
                universo[i] = universo[j];
                universo[j] = auxiliar;
            }
        }
    
}

