#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 
#include <stdio.h> 
#include <errno.h> 
#include <stdlib.h> 

int main() { 
    pid_t childpid, waitreturn; 
    int status; 
    childpid = fork();
    if (childpid == -1) { 
        fprintf(stderr, "Error en fork %d\n", errno); 
        exit(1); 
    } 
    else if (childpid == 0) { /* codigo del proceso hijo */ 
        if (execl ("/bin/ps", "ps", "-fu", getenv ("USER"), 0) < 0) { 
            fprintf(stderr, "Error en exec %d\n", errno); 
            exit(1); 
        } 
    } 
    else /* codigo del proceso padre */ 
        while(childpid != (waitreturn = wait(&status))) 
            if ((waitreturn == -1) && (errno != EINTR)) 
                break; 
    
    exit(0); 
}