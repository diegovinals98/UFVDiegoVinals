#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <errno.h> 
#include <stdlib.h> 
 
int main() { 
    int status; 
    printf( "Soy el proceso Padre, mi (PID) es %d\n", (int) getpid() ); 
    printf ("Listar los procesos \n"); 
    if (execl ("/bin/ps", "ps", "-f", NULL) < 0) { 
    //if (exec ("ps") < 0) { 
        fprintf(stderr, "Error en exec %d\n", errno); 
        exit(1); 
    } 
    printf ("Fin de la lista de procesos\n"); 
    exit(0); 
} 