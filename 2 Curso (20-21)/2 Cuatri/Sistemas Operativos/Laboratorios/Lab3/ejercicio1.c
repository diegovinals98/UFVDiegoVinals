#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    pid_t pid1, pid2, pid3;
    int status1, status2, status3;
 
    if ( (pid1=fork()) == 0 )
    { 
        if ( (pid2=fork()) == 0 )
        { 
        	if((pid3 = fork()) == 0){
        		printf("Soy el D = %d, hijo de %d\n",
				getpid(), getppid());
        	}
        	else{
        		wait(&status3);
            	printf("Soy el C = %d, hijo de %d\n",
				getpid(), getppid());
        	}
        	
        }
        else
        { 
            wait(&status2);
            printf("Soy el B = %d, hijo de %d\n",
			getpid(), getppid());
        }
    }
    else
    {
        wait(&status1);
        printf("Soy el A = %d, hijo de %d\n", getpid(),
		getppid());
    }
 
    return 0;
}