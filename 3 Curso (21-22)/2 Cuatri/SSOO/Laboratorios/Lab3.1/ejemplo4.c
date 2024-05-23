#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <stdio.h> 

int main (void) { 

    pid_t childpid; 
    int status=0; 
    int result; 
    if ((childpid = fork()) == -1) { 
        perror("Error en llamada a fork\n"); 
        exit(1); 
    } 
    else if (childpid == 0) { 
        result = getpid() < getppid() ; 
        fprintf(stdout, "Soy el proceso hijo (%ld) y voy a devolver a mi padre (%ld)  el  valor  %d  después  de  esperar  2  segundos\n",  (long)getpid(), 
        (long)getppid(), result); 
        sleep(2); 
        exit (result); 
    } 
    else { 
        while( childpid != wait(&status)); 
        fprintf(stdout,  "Soy  el  proceso  padre  (%ld)  y  mi  hijo  (%ld)  me  ha 
        devuelto %d\n", (long)getpid(), (long)childpid, status); 
    } 
    return (0); 
} 