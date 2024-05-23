#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];
int counter;

void* tuFuncionHilo(void *arg)
{
    unsigned long i = 0;
    counter += 1;
    printf("\n Tu hilo %d inicia\n", counter);

    for(i=0; i<(0xFFFFFFFF);i++);
    printf("\n Tu hilo %d finaliza\n", counter);

    return NULL;
}

int main(void)
{
    int i = 0;
    int err;

    while(i < 2)
    {
        err = pthread_create(&(tid[i]), NULL, &tuFuncionHilo, NULL);
        if (err != 0)
            printf("\n No es posible crear el hilo: [%s]", strerror(err));
        i++;
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);

    return 0;
}
