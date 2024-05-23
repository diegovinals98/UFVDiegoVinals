// Viñals Lage, Diego
// Practica1
// Created by diego viñals lage on 10/17/19.
// Copyright © 2019 diego viñals lage. All rights reserved.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Ejercicio 1
// creamos una funcion para luego llamarla en la funcion main()
void ejercicio1(){
    // Declaramos la variable que va a guardar la longitud de la telarana
    int longitud = 0;
    
    // Preguntamos por la longitud de la telarana
    printf("Numero: ");
    scanf("%d" , &longitud);
    
    // Si es 1 dibujamos un asterisco ( es lo que nos pide el ejercicio
    // si no es uno, hacemos el else
    if(longitud == 1){
        printf("*\n\n");
    } else{
        // Declaramos variables
        int espacios = longitud - 1;
        int asteriscos=  longitud - espacios;
        int linea;
        
        // Dibujamos la primera linea
        int q = longitud - 1;
        while (q > 0) {
            printf(" ");
            q--;
        }
        // Dibujamos los asteriscos de la primera linea
        int e = longitud;
        while (e > 0) {
            printf("* ");
            e--;
        }
        
        // Cambiamos de linea y restamos uno al espacio
        printf("\n");
        espacios--;
        
        // Hacemos el resto de lineas de la parte de arriba
        int x = 2;
        while (x < longitud) {
            asteriscos = longitud - espacios;
            // Dibujamos los espacios
            int u = espacios;
            while (u > 0){
                printf(" ");
                u--;
            }
            linea = x;
            printf("* ");
            // Ahora dependiendo de la posicion, dibujamos espacios o asteriscos
            int r = asteriscos - 2;
            while(r > 0){
                // Si la linea es par
                if(linea % 2 == 0){
                    if(r % 2 == 0){
                        printf("  ");
                    }else{
                        printf("* ");
                    }
                }else{
                    if(r % 2 == 0){
                        printf("* ");
                    }else{
                        printf("  ");
                    }
                }
                r--;
            }
            // Dibujamos el asterisco que nos falta
            printf("* ");
            int j = espacios - 1;
            while (j > 0 ) {
                if(x % 2 == 0){
                    printf("  ");
                }else{
                    printf("* ");
                }
                
                j--;
            }
            // Dibujamos la segunda piramide
            printf("* ");
            int c = asteriscos -2;
            while(c > 0){
                if(c % 2 == 0){
                    printf("* ");
                    c--;
                }else{
                    printf("  ");
                    c--;
                }
            }
            printf("* ");
            printf("\n");
            espacios--;
            x++;
        }
        
        // Dibujamos la linea central, con todo asteriscos
        for(int y = (longitud * 2) - 1; y > 0; y--){
            printf("* ");
            
        }
        espacios = 1;
        printf("\n");

        // Dubujamos la parte de abajo, sera igual que la de arriba, pero invertido
        int i = 2;
        while (i < longitud) {
            asteriscos = longitud - espacios;
            linea = i;
            int u = espacios;
            while (u > 0) {
                printf(" ");
                u--;
            }
            
            // Dibujamos la primera piramide
            printf("* ");
            int k = asteriscos - 2;
            while (k > 0) {
                if(longitud % 2 == 0){
                    if(k % 2 != 0){
                        if(linea % 2 == 0){
                            printf("  ");
                        }else{
                            printf("* ");
                        }
                    }else{
                        if(linea % 2 == 0){
                            printf("* ");
                        }else{
                            printf("  ");
                        }
                    }
                }else{
                    if(k % 2 != 0){
                        if(linea % 2 == 0){
                            printf("* ");
                        }else{
                            printf("  ");
                        }
                    }else{
                        if(linea % 2 == 0){
                            printf("  ");
                        }else{
                            printf("* ");
                        }
                    }
                }
                k--;
            }
            
            printf("* ");
            // Dibujamos una separacion entre piramides
            int j = espacios - 1;
            while (j > 0) {
                if(longitud % 2 != 0){
                    if(i % 2 == 0){
                        printf("  ");
                    }else{
                        printf("* ");
                    }
                }else{
                    if(i % 2 == 0){
                        printf("* ");
                    }else{
                        printf("  ");
                    }
                }
                j--;
            }
            
            // Dibujamos la segunda piramide
            printf("* ");
            for(int i = asteriscos - 2; i > 0; i--){
                if(i % 2 != 0){
                    printf("  ");
                }else{
                    printf("* ");
                }
            }
            printf("* ");
            printf("\n");
            espacios++;
            i++;
        }
        
        // Dibujamos la ultima linea
        for(int z = espacios; z > 0; z--){
            printf(" ");
        }
        for(int v = longitud ; v > 0; v--){
            printf("* ");
        }
        
        // Saltamos de linea para que quede bonito
        printf("\n\n");
        
    }
}

// Funcion que cuenta el numero de digitos que tiene un numero
int numeroDigitos(int valor){
    // Inicializamos la variable que alamacena el numero de digitos
    int contadorValor = 0;
    
    // mientras que el numero origial no sea 0
    // lo dividimos entre 10, asi, tenemos un digito menos,
    // y le sumamos 1 al contador
    // cuando la division sea 0, quiere decir que ya no nos quedan digitos,
    // por lo tanto paramos el while
    while(valor !=0){
        valor = valor/10;
        contadorValor++;
        
    }
    return contadorValor;
}

// Funcion que, dado un numero y dada una posicion,
// nos saca el digito en esa posicion de ese numero.
int digitos(int numeroOriginal, int posicion){
    int potencia = pow(10, posicion);
    int DigitoenPosicion = (numeroOriginal % potencia) / (potencia / 10);
    return DigitoenPosicion;
}

// Funcion que nos da un numero aleatorio entre dos numeros
int numeroAleatorio(int menor, int mayor){
    int PosicionAleatoria = rand() % (mayor-menor+1) + menor;
    return PosicionAleatoria;
}


// Ejercicio 2
// creamos una funcion para luego llamarla en la funcion main()
void ejercicio2(){
    // Inicializamos las variables donde vamos a almacenar los dos numeros
    int numero1 = 0;
    int numero2 = 0;
    
    // creamos un array para cada numero, para que luego nos sea mas facil manejar los numeros individuales con for loops
    int valor1[7];
    int valor2[9];
    
    // inicializamos las variables que van a almacenar la suma de cada numero
    // tambien inicializamos la variable que va a alamcenar la suma final
    int sumafinal = 0;
    int sumaN1 = 0;
    int sumaN2 = 0;
    
    // Preguntamos que escriba el primer numero y lo almacenamos en la variable creada anteriormente
    printf("Introduce el valor del primer numero: ");
    scanf("%d" , &numero1);
    
    if(numero1 > 1000000){
        // Preguntamos que escriba el segundo numero y lo almacenamos en la variable creada anteriormente
        printf("Introduce el valor del segundo numero: ");
        scanf("%d" , &numero2);
    }
    
    // declaramos un if que comprueba si los numeros que nos han dado tienen 7 y 9 digitos respectivamente y no empiezan por 0
    // para ello, hacemos uso de una funcion creada que cuenta el numero de digitos en un numero y otra funcion que saca el digito deseado, para
    // saber si empieza por 0 o no, cogemos el digito 7 y 9 empezando por la derecha de cada numero
    if((numero1 > 1000000 && numero2 > 100000000) && (digitos(numero1, 7) != 0 && digitos(numero2, 9) != 0 )){
        
        // separamos los digitos de cada valor y los ponemos en un array
        // esta lista es para los digitos del numero 1
        for(int i = 0; i <= 7; i++){
            valor1[i] = digitos(numero1, i + 1);
        }
        
        // separamos los digitos de cada valor y los ponemos en un array
        // esta lista es para los digitos del numero 2
        for(int i = 0; i <= 9; i++){
            valor2[i] = digitos(numero2, i + 1);
        }
        
        // Ahora, teniendo ya nuestros arrays fabricados, cogemos los impares del primer numero ( que equivalen a los pares si juntamos los dos numeros principales)
        // y los multiplicamos por 2, los almacenamos donde estaban antes los digitos iniciales, ya que a partir de ahora no nos van a hacer falta
        for (int i = 0; i < 7; i++) {
            if(i % 2 == 0){
                valor1[i] = valor1[i] * 2;
            }
        }
        
        // Hacemos lo mismo que en el for loop anterior, pero con los numeros pares
        for (int i = 0; i < 9; i++) {
            if(i % 2 != 0){
                valor2[i] = valor2[i] * 2;
            }
        }
        
        // Ahora vamos a comprobar si los numeros tienen dos digitos
        // Lo vamos a hacer para los digitos del numero 1
        for(int i = 0 ; i < 7; i++){
            if(numeroDigitos(valor1[i]) != 1){
                int digito1 = digitos(valor1[i] , 1);
                int digito2 = digitos(valor1[i], 2);
                valor1[i] = digito1 + digito2;
            }
        }
        
        // Hacemos lo mimso que en el for loop anterior, pero para los digitos del numero 2
        for(int i = 0 ; i < 9; i++){
            if(numeroDigitos(valor2[i]) != 1){
                int digito1 = digitos(valor2[i] , 1);
                int digito2 = digitos(valor2[i], 2);
                valor2[i] = digito1 + digito2;
            }
        }
        
        // sumamos los valores para el numero1
        for (int i = 0 ; i < 7; i++) {
            sumaN1 = sumaN1 + valor1[i];
        }
        
        // sumamos los valores para el numero2
        for (int i = 0 ; i < 9; i++) {
            sumaN2 = sumaN2 + valor2[i];
        }
        
        // ahora sumamos estos dos valores
        sumafinal = sumaN1 + sumaN2;
        
        // comprobamos si la suma final es divisor de 10
        // si lo es, escrbimos uso autorizado,
        // si no, no autorizado
        if((sumafinal) % 10 == 0){
            printf("Uso autorizado. Bienvenido\n");
        } else{
            printf("Uso no autorizado. Contactando con J.A.R.V.I.S.\n");
        }
    } else{
        printf("Valor no valido\n");
    }
}

// Funciones para el ejercicio 3
// Suma uno a la posicion de altura, es decir, movimiento para subir una planta
void movientoArriba(int posicion[]){
    posicion[0] = posicion[0] + 1;
}

// Resta uno a la posicion de altura, es decir, movimiento para bajar una planta
void movimientoAbajo(int posicion[]){
    posicion[0] = posicion[0] - 1;
}

// Suma uno a la posicion horizontal, es decir, movimiento para ir a la derecha en una misma planta
void movimientoDerecha(int posicion[]){
    posicion[1] = posicion[1] + 1;
}

// Resta uno a la posicion horizontal, es decir, movimiento para ir a la izquierda en una misma planta
void movientoIzquierda(int posicion[]){
    posicion[1] = posicion[1] - 1;
}

// Suma uno a las dos posiciones, vertical y horizoantal, movimiento para subir una planta e ir a la derecha
void movimientoDiagonalArribaDerecha(int posicion[]){
    posicion[0] = posicion[0] + 1;
    posicion[1] = posicion[1] + 1;
}

// Suma uno a la posicion vertical y resta a la horizontal, movimiento para subir una planta e ir a la izquierda
void movimientoDiagonalArribaIzquierda(int posicion[]){
    posicion[0] = posicion[0] + 1;
    posicion[1] = posicion[1] - 1;
}

// Resta uno a las dos posiciones, vertical y horizoantal, movimiento para bajar una planta e ir a la izquierda
void movimientoDiagonalAbajoIzquierda(int posicion[]){
    posicion[0] = posicion[0] - 1;
    posicion[1] = posicion[1] - 1;
}

// Resta uno a la posicion vertical y suma a la horizontal, movimiento para bajar una planta e ir a la derecha
void movimientoDiagonalAbajoDerecha(int posicion[]){
    posicion[0] = posicion[0] - 1;
    posicion[1] = posicion[1] + 1;
}

// Ejercicio 3
void ejercicio3(){
    // Para que los numeros aleatorios no sean siempre los mismos
    srand(time(NULL));
    
    // Inicializamos las variables de las posiciones de loki y hulk, van a ser dos arrays, que contiene la posicion vertical y horizontal
    int posicionHulk[2];
    int posicionLoki[2];
    
    // Le damos a la posicion de hulk dos numeros aleatorios entre 0 y 25 para altura, y entre 0 y 10 para la planta
    posicionHulk[0] = numeroAleatorio(0, 25); // Vertical
    posicionHulk[1] = numeroAleatorio(0, 10); // horizontal
    
    // Le damos a la posicion de Loki dos numeros aleatorios entre 0 y 25 para altura, y entre 0 y 10 para la planta
    posicionLoki[0] = numeroAleatorio(0, 25); // Vertical
    posicionLoki[1] = numeroAleatorio(0, 10); // Horizontal
    
    // Inicializamos el contador, cada vez que hulk haga un movimiento, se suma uno
    int contador = 0;
    
    // Printf para ver en pantalla la posicion inicial y los movimientos
    printf("Posicion Loki. Planta %d. Habitacion %d.\n", posicionLoki[0] , posicionLoki[1]);
    printf("MovHulk\tPlanta\t\thabitcion\n=======================================\n");
    printf("-\t\t%2d\t\t\t%2d\n" , posicionHulk[0] , posicionHulk[1]);
    
    // While loop, va a ejecutar lo de dentro mientras que las posiciones de loki y hulk no sean iguales o mientras que el contador no sea 10 o mas, por que hulk solo puede hacer 10 movimientos
    while ((posicionLoki[0] != posicionHulk[0] || posicionLoki[1] != posicionHulk[1]) && contador < 10 ) {
        
        // Una serie de ifs, que comprueban las posiciones de los dos, y dependiendo de cual este mas alto o mas a la derecha, ejecute el movimiento adecuado
        if (posicionLoki[0] < posicionHulk[0] && posicionLoki[1] < posicionHulk[1]) {
            movimientoDiagonalAbajoIzquierda(posicionHulk);
            printf("C\t\t%2d\t\t\t%2d\n" , posicionHulk[0] , posicionHulk[1]);
            contador++;
        } else if(posicionLoki[0] > posicionHulk[0] && posicionLoki[1] > posicionHulk[1]){
            movimientoDiagonalArribaDerecha(posicionHulk);
            printf("A\t\t%2d\t\t\t%2d\n" , posicionHulk[0] , posicionHulk[1]);
            contador++;
        } else if(posicionLoki[0] > posicionHulk[0] && posicionLoki[1] < posicionHulk[1]){
            movimientoDiagonalArribaIzquierda(posicionHulk);
            printf("E\t\t%2d\t\t\t%2d\n" , posicionHulk[0] , posicionHulk[1]);
            contador++;
        } else if(posicionLoki[0] < posicionHulk[0] && posicionLoki[1] > posicionHulk[1]){
            movimientoDiagonalAbajoDerecha(posicionHulk);
            printf("B\t\t%2d\t\t\t%2d\n" , posicionHulk[0] , posicionHulk[1]);
            contador++;
        } else if(posicionLoki[0] < posicionHulk[0] && posicionLoki[1] == posicionHulk[1]){
            movimientoAbajo(posicionHulk);
            printf("D\t\t%2d\t\t\t%2d\n" , posicionHulk[0] , posicionHulk[1]);
            contador++;
        } else if (posicionLoki[0] > posicionHulk[0] && posicionHulk[1] == posicionLoki[1]) {
            movientoArriba(posicionHulk);
            printf("U\t\t%2d\t\t\t%2d\n"  , posicionHulk[0] , posicionHulk[1]);
            contador++;
        } else if(posicionLoki[1] < posicionHulk[1] && posicionLoki[0] == posicionHulk[0]){
            movientoIzquierda(posicionHulk);
            printf("L\t\t%2d\t\t\t%2d\n" , posicionHulk[0] , posicionHulk[1]);
            contador++;
        } else if(posicionLoki[1] > posicionHulk[1] && posicionLoki[0] == posicionHulk[0]){
            movimientoDerecha(posicionHulk);
            printf("R\t\t%2d\t\t\t%2d\n", posicionHulk[0] , posicionHulk[1]);
            contador++;
        }
    }
    
    // Si el contador es menor que 10, imprimir el mensaje de victoria, si no, el de derrota
    if(contador < 10)
        printf("Vengadores, hemos vencido\n\n");
    else
        printf("¡Ya basta! Todos están por debajo de mi. Yo soy un dios, criatura tonta, y no me va a intimidar una bes... Debilucho\n\n");
}

// Funcion del ejercicio opcional 3
// Luego la llamamos en el main
void ejercicio3Op(){
    printf("Parte no realizada\n\n");
}

// Funcion que es la que llama a las demas funciones
int main() {
    // declaramos la variable que almacena el numero de ejercicio
    int ejercicio = 0;
    // Variable para poder luego finalizar el programa
    int finalizador = 1;
    
    // Con este do while y el switch, llamaremos a una funcion u otra dependiendo del ejercicio que haya dicho el usuario
    do{
        
        printf("1.- Spiderman\n2.- Armadura\n3.- Batalla\n4.- Torre Stark\n5.- Salir\n");
        // Le preguntamos al usuario que escoja un ejercicio
        printf("\nIntroduzca una Opcion (1-5) ");
        scanf("%d" , &ejercicio);
        
        switch (ejercicio) {
            case 1:
                // Llamamos al ejercicio 1
                ejercicio1();
                break;
            case 2:
                // Llamamos al ejercicio 2
                ejercicio2();
                break;
                
            case 3:
                // Llamamos al ejercicio 3
                ejercicio3();
                break;
                
            case 4:
                // Llamamos al ejercicio 3 Opcional
                ejercicio3Op();
                break;
            case 5:
                // Finalizador es 0, por lo tanto las condicioned del while no se cumple y finaliza el programa
                finalizador = 0;
                break;
        }
        
        if(ejercicio < 1 || ejercicio > 5){
            printf("ERROR: Opcion introducida no valida\n");
        }
    } while(ejercicio < 1 || ejercicio > 5 || finalizador != 0);
    
}








