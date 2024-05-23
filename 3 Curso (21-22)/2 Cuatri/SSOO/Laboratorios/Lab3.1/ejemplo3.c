#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
 
int main (void) { 
int i; 
int padre; 
padre = 1; 
for (i=0; i < 3; i++) { 
    if (padre == 1){ 
        if (fork() == 0) /* Proceso hijo */ 
        { 
            fprintf(stdout, "Este es el proceso hijo (%ld) con padre %ld\n", 
            (long) getpid(),
            (long) getppid()); 
            sleep(60);
            padre = 0; 
        } else /* Proceso padre */ 
        { 
            fprintf(stdout, "Este es el proceso padre con ID %ld\n", 
            (long)getpid()); 
            padre = 1; 
        } 
    } 
} 
return 0; 
} 