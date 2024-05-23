#include <stdio.h>
#include <sys/types.h> 
#include <unistd.h> 
 
int main(void) 
{ 
    printf("ID de proceso: %ld\n", (long) getpid()); // Id del proceso que estamos ejecutando (ejemplo 1)
    printf("ID de proceso padre: %ld\n", (long) getppid()); // Id del bash. Padre del proceso
    printf("ID de usuario propietario: %ld\n", (long) getuid()); 
    return 0; 
} 