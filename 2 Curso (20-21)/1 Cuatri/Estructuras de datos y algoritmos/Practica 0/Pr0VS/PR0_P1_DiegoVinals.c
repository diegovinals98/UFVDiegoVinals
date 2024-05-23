// Practica 0: Parte 1
// Nombre: Diego Vinals Lage
// Curso: 2A

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <math.h>

// Declaracion de constantes


#define PI 3.141592
#define menosPI -3.141592


// declarancion de variables


double calcula_term_N (double t_ant, double x, int n);
double coseno (double ang);
double seno (double ang);
double x;


double calcula_term_N (double t_ant, double x, int n){
    if(n > 0){
        double terminoCalculado = (-1*t_ant*pow(x,2))/((2* (double) n) * (2*(double) n - 1));
        return terminoCalculado;
        
    }
    else return 0;
}

double Calcularseno (double ang){
    
    double tanterior = ang;
    double termino = 0;
    double total = 0;
    int i = 1;
     
    while(fabs(tanterior) > pow(10,-6)){
        termino = calcula_term_N(tanterior, ang, i);
        total = tanterior + termino;
        tanterior = termino;
        i++;
    }
    
    return total;
}


double Calcularcoseno (double ang){

    double cosen;


    double seno = Calcularseno(ang);
    cosen = sqrt(1-pow(seno, 2));

    
    if((ang >= -PI && ang < -PI/2) || (ang > PI/2 && ang <= PI)){
        return -cosen;
    } else if(ang >= -PI/2 && ang <= PI/2){
        return cosen;
    } else {
        return cosen;
    }


}
int main(void){

    do{
        printf("Escribe el angulo (En Radianes -Pi hasta Pi): \n");
        scanf("%lf", &x);
    } while(x >= PI || x < menosPI);
    
    
    printf("El seno de %.5lf radianes es: %.2lf\n", x , Calcularseno(x));
    printf("El coseno de %.5lf radianes es: %.2lf\n", x , Calcularcoseno(x));
    

}

