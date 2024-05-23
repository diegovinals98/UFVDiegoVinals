#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <pthread.h>
#include <string.h>



void *funcionHilo(char *sensor);

int main(){
    pthread_t idHilo1;
    pthread_t idHilo2;
    pthread_t idHilo3;

    int sensor1;
    int sensor2;
    int sensor3;

    
    
    sensor1 = pthread_create (&idHilo1, NULL, funcionHilo, "S1");
    sensor2 = pthread_create (&idHilo2, NULL, funcionHilo, "S2");
    sensor3 = pthread_create (&idHilo3, NULL, funcionHilo, "S3");

 

}


void *funcionHilo(char *sensor){
    printf("Dentro del hilo\n");
    while (1){
        if (!strcmp(sensor,"S1")){
            printf("Sensor 1: %d\n", 40 + rand() % (121 -40));
            sleep(100);
        }

        if (!strcmp(sensor,"S2")){
            printf("Sensor 2: %d\n", 88 + rand() % (99 -88));
            sleep(200); 
        }
        if (!strcmp(sensor,"S3")){
            printf("Sensor 3: %d\n", 50 + rand() % (1001 -50));
            sleep(300);
        }
    }
    
}