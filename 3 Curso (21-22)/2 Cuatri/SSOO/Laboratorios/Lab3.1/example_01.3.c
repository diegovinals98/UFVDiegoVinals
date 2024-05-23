#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
 
int main(int argc, char *argv[]) 
{ 
    printf("Soy example_01.3.C, mi PID es %d\n", getpid()); 
    char *args[] = {"example_01.4", "C", "Programming", NULL}; 
    execv("./example_01.4", args); 
    printf("Volviendo a example_01.3.C \n"); 
    return 0; 
} 
 
