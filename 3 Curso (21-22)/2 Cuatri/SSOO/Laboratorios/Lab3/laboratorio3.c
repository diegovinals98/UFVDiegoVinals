#include <stdio.h>
#include <stdlib.h>

int main(){
    int numeroFilas;
    int numeroColumnas;
    int acum=0;
    
    printf("Escribe el numero de filas de la matriz: ");
    scanf("%d" , &numeroFilas);
    printf("Escribe el numero de columnas de la matriz: ");
    scanf("%d" , &numeroColumnas);
    int m[numeroFilas][numeroColumnas];
    for(int i=0;i<numeroFilas;i++){
        for(int j=0;j<numeroColumnas;j++){
            m[i][j]=rand()%100+1;
        }
    }

    printf("La matriz entera: \n");
    for(int x = 0 ; x < numeroFilas ; x++) {
        printf(" (");
        for(int y = 0 ; y < numeroColumnas ; y++){
            printf("%d ", m[x][y]);
        }
        printf(")\n");
    }

    printf("Los valores de la diagonal principal: \n");
    for(int x = 0 ; x < numeroFilas ; x++) {
        printf("%d ", m[x][x]);
    }
    printf("\n");

    printf("Los valores de la diagonal secundaria: \n");
    for(int x = 0 ; x < numeroFilas ; x++) {
        //printf("(");
        printf("Falta por hacer\n");
        //printf(")\n");
    }

    printf("Los valores pares:\n");
    for(int i=0;i<numeroFilas;i++){
        for(int j=0;j<numeroColumnas;j++){
            if (m[i][j] % 2 == 0){
                printf("%d ", m[i][j]);
                
            }
        }
    }
    printf("\n");

    printf("Los valores impares:\n");
    for(int i=0;i<numeroFilas;i++){
        for(int j=0;j<numeroColumnas;j++){
            if (m[i][j] % 2 != 0){
                printf("%d ", m[i][j]);
                
            }
        }
    }
    printf("\n");

    printf("Los valores de la diagonal superior:\n");
    for(int i=0;i<numeroFilas;i++){
        for(int j=0;j<numeroColumnas;j++){
            if (m[i][j] % 2 != 0){
                printf("Falta por hacer\n");
            }
        }
    }

    printf("Los valores de la diagonal inferior:\n");
    for(int i=0;i<numeroFilas;i++){
        for(int j=0;j<numeroColumnas;j++){
            if (m[i][j] % 2 != 0){
                printf("Falta por hacer\n");
            }
        }
    }

    
}