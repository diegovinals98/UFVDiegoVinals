#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 



int main( void ) { 
    printf( "PADRE: Soy el proceso Padre: mi (PID) es %d\n", (int) getpid() ); 
    
    int pid = fork(); 
    // fork le devuelve 0 al hijo
    // le devuelve el PID de P1 al padre
    
    if ( pid == 0 ) { 
        printf( "HIJO: después de fork()\n");       // ejemplo 2 es P1, el proceso padre
        printf( "HIJO: soy el proceso Hijo, mi (PID) es %d\n", (int) getpid() ); 
        sleep(60);
        printf( "HIJO: el Id de mi padre es: %d\n", getppid());
    } else { 
        printf( "PADRE: después de fork()\n");  // a nivel de codigo, P2 es un clon de P1
        sleep(60);
        printf( "PADRE: el (PID) del Padre sigue siendo %d - fork() retorna %d\n", (int) getpid(), pid ); 
    } 
    
    return 0; 
} 