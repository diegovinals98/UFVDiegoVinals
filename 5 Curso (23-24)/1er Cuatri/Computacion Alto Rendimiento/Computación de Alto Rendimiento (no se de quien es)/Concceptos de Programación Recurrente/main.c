#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// Defino mis funciones en
static void * Tarea1 (void* arg) ;
static void * Tarea2 (void* arg) ;
static void * Tarea3 (void* arg) ;
static void * Monitorizacion (void* arg) ;
long int cont_0 = 0;
long int cont_1 = 0;
struct datos {int segundo;
    int sensor;};
struct datos pulso[3];
struct datos con_oxigeno[3];
struct datos diastolica[3];
struct datos sistolica[3];
int monitor=10;

sem_t sem1,sem2,sem3,sem4;

int main (void) {
    cont_0 = (unsigned long)time(NULL);
    srand(time(NULL));
    pthread_t thread_1, thread_2,thread_3,thread_4;
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 0);
    sem_init(&sem4, 0, 0);

    pthread_create(&thread_1, NULL, *Tarea1, NULL);
    pthread_create(&thread_2, NULL, *Tarea2, NULL);
    pthread_create(&thread_3, NULL, *Tarea3, NULL);
    pthread_create(&thread_4, NULL, *Monitorizacion, NULL);

    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    pthread_join(thread_3, NULL);
    pthread_join(thread_4, NULL);

    sem_destroy(&sem1);
    sem_destroy(&sem2);
    sem_destroy(&sem3);
    sem_destroy(&sem4);

    return 0;
}
static void * Tarea1(void* arg){
    while(1){
        sem_wait(&sem1);
        //printf(" Primer hilo\n");
        cont_1 = (unsigned long)time(NULL) ;

        int resta = (cont_1 - cont_0);

        if (resta<=3 && resta!=0){
            if (resta % 1 == 0) {

                if (pulso[resta - 1].segundo != resta) {
                    pulso[resta - 1].segundo = resta;
                    printf("\nSegundo actual %d\n", pulso[resta-1].segundo);
                    printf("Tarea 1 - ritmo_cardiaco:\n");

                    pulso[resta - 1].sensor = rand() % (120 - 40 + 1) + 40;

                    printf("Ritmo cardiaco:%d\n", pulso[resta - 1].sensor);



                }
            }
        }
        else {
            if (resta % 1 == 0) {
                if (pulso[(resta - 1) % 3].segundo != resta) {
                    pulso[(resta - 1) % 3].segundo = resta;
                    printf("\nSegundo actual: %d\n\n", pulso[(resta - 1) % 3].segundo);
                    printf("Tarea 1 - ritmo_cardiaco:\n");

                    pulso[(resta - 1) % 3].sensor = rand() % (120 - 40 + 1) + 40;
                    printf("Ritmo cardiaco:%d\n", pulso[(resta - 1) % 3].sensor);

                }
            }

        }
        sem_post(&sem2);
    }


}






static void * Tarea2 (void* arg){
    while(1){
        sem_wait(&sem2);
        //printf(" Primer hilo\n");
        cont_1 = (unsigned long)time(NULL) ;

        int resta = (cont_1 - cont_0);

        if (((resta/2)-1)<3 && resta!=0){
            if (resta % 2 == 0) {
                if (con_oxigeno[((resta/2)-1)].segundo != resta) {

                    printf("\nTarea 2 - concentracion_oxigeno: \n");

                    con_oxigeno[((resta/2)-1)].sensor = rand() % (98 - 88 + 1) + 88;
                    con_oxigeno[((resta/2)-1)].segundo = resta;
                    printf("Concentracion de oxigeno:%d\n", con_oxigeno[(resta/2-1)].sensor);



                }
            }
        }
        else if (resta%6==0){
            if (con_oxigeno[2].segundo != resta) {
                printf("\nTarea 2 - concentracion_oxigeno: \n");
                con_oxigeno[2].sensor = rand() % (98 - 88 + 1) + 88;
                con_oxigeno[2].segundo = resta;
                printf("Concentracion de oxigeno:%d\n", con_oxigeno[(2)].sensor);



            }
        }
        else{
            if (resta % 2 == 0) {
                if (con_oxigeno[((resta%6)/2)-1].segundo != resta) {
                    printf("\nTarea 2 - concentracion_oxigeno: \n");
                    con_oxigeno[((resta%6)/2)-1].segundo = resta;
                    con_oxigeno[((resta%6)/2)-1].sensor = rand() % (98 - 88 + 1) + 88;
                    printf("Concentracion de oxigeno:%d\n", con_oxigeno[((resta%6)/2)-1].sensor);

                }
            }

        }
        sem_post(&sem3);
    }



}




static void * Tarea3(void* arg) {
    while(1){
        sem_wait(&sem3);
        //printf(" Primer hilo\n");
        cont_1 = (unsigned long)time(NULL) ;

        int resta = (cont_1 - cont_0);

        if (((resta/3)-1)<3 && resta!=0){
            if (resta % 3 == 0) {
                if (diastolica[((resta/3)-1)].segundo != resta) {
                    printf("\nTarea 3 - tension_arterial: \n");

                    diastolica[((resta/3)-1)].sensor = rand() % (100 - 50 + 1) + 50;
                    diastolica[((resta/3)-1)].segundo = resta;
                    sistolica[(resta/3-1)].segundo = resta;
                    sistolica[(resta/3-1)].sensor = rand() % (100 - 50 + 1) + 50;

                    printf("Tension diastolica:%d\n", diastolica[(resta/3-1)].sensor);
                    printf("Tension sistolica:%d\n", sistolica[(resta/3-1)].sensor);




                }
            }
        }
        else if (resta%6==0){
            if (diastolica[2].segundo != resta) {
                printf("\nTarea 3 - tension_arterial: \n");
                diastolica[2].sensor = rand() % (100 - 50 + 1) + 50;
                diastolica[2].segundo = resta;
                sistolica[2].segundo = resta;
                sistolica[2].sensor = rand() % (180 - 110 + 1) + 110;

                printf("Tension diastolica:%d\n", diastolica[(2)].sensor);
                printf("Tension sistolica:%d\n", sistolica[(2)].sensor);


            }
        }
        else{
            if (resta % 3 == 0) {
                if (diastolica[((resta%9)/3)-1].segundo != resta) {
                    printf("\nTarea 3 - tension_arterial: \n");
                    diastolica[((resta % 9) / 3) - 1].segundo = resta;
                    diastolica[((resta % 9) / 3) - 1].sensor = rand() % (100 - 50 + 1) + 50;
                    sistolica[((resta % 9) / 3) - 1].segundo = resta;
                    sistolica[((resta % 9) / 3) - 1].sensor = rand() % (100 - 50 + 1) + 50;

                    printf("Tension diastolica:%d\n", diastolica[((resta%9)/3)-1].sensor);
                    printf("Tension sistolica:%d\n", sistolica[((resta%9)/3)-1].sensor);

                }
            }

        }
        sem_post(&sem4);
    }

}




static void * Monitorizacion(void* arg) {
    while(1){
        sem_wait(&sem4);
        cont_1 = (unsigned long)time(NULL) ;
        int resta = (cont_1 - cont_0);
        if (resta%10==0 && resta!=0){
            if (resta==monitor) {
                int bradicardia=0;
                int taquicardia=0;
                int hipoxia=0;
                int tension_alta=0;
                int tension_baja=0;
                printf("\n\nMONITORIZACION\n");
                monitor+=10;
                if (((pulso[0].sensor > 60) && (pulso[0].sensor < 120)) &&
                    ((pulso[1].sensor > 60) && (pulso[1].sensor < 120)) &&
                    ((pulso[2].sensor > 60) && (pulso[2].sensor < 120))) {
                    printf("\nRitmo cardiaco normal\n");
                    printf("Valor cardiado 1:%d\n", pulso[0].sensor);
                    printf("Valor cardiado 2:%d\n", pulso[1].sensor);
                    printf("Valor cardiado 3:%d\n", pulso[2].sensor);
                }
                if  ((pulso[0].sensor < 60) &&
                     (pulso[1].sensor < 60) &&
                     (pulso[2].sensor < 60)) {
                    printf("\nBRADICARDIA\n");
                    printf("Valor cardiado 1:%d\n", pulso[0].sensor);
                    printf("Valor cardiado 2:%d\n", pulso[1].sensor);
                    printf("Valor cardiado 3:%d\n", pulso[2].sensor);
                    bradicardia=1;
                }
                if  ((pulso[0].sensor > 100) &&
                     (pulso[1].sensor > 100) &&
                     (pulso[2].sensor > 100)) {
                    printf("\nTAQUICARDIA\n");
                    printf("Valor cardiado 1:%d\n", pulso[0].sensor);
                    printf("Valor cardiado 2:%d\n", pulso[1].sensor);
                    printf("Valor cardiado 3:%d\n", pulso[2].sensor);
                    taquicardia=1;
                }
                if (((con_oxigeno[0].sensor > 92) && (con_oxigeno[0].sensor < 98)) &&
                    ((con_oxigeno[1].sensor > 92) && (con_oxigeno[1].sensor < 98)) &&
                    ((con_oxigeno[2].sensor > 92) && (con_oxigeno[2].sensor < 98))) {
                    printf("\nSPo Normal\n");
                    printf("Concentracion de oxigeno 1:%d\n", con_oxigeno[0].sensor);
                    printf("Concentracion de oxigeno 2:%d\n", con_oxigeno[1].sensor);
                    printf("Concentracion de oxigeno 3:%d\n", con_oxigeno[2].sensor);
                }

                if  ((con_oxigeno[0].sensor < 92) &&
                     (con_oxigeno[1].sensor < 92) &&
                     (con_oxigeno[2].sensor < 92)) {
                    printf("\nHipoxia\n");
                    printf("Concentracion de oxigeno 1:%d\n", con_oxigeno[0].sensor);
                    printf("Concentracion de oxigeno 2:%d\n", con_oxigeno[1].sensor);
                    printf("Concentracion de oxigeno 3:%d\n", con_oxigeno[2].sensor);
                    hipoxia=1;
                }

                if ((((sistolica[0].sensor > 90) && (sistolica[0].sensor < 120)) &&
                     ((sistolica[1].sensor > 90) && (sistolica[1].sensor < 120)) &&
                     ((sistolica[2].sensor > 90) && (sistolica[2].sensor < 120))) &&
                    (((diastolica[0].sensor > 60) && (diastolica[0].sensor < 80)) &&
                     ((diastolica[1].sensor > 60) && (diastolica[1].sensor < 80)) &&
                     ((diastolica[2].sensor > 60) && (diastolica[2].sensor < 80)))){
                    printf("\nTENSION ARTERIAL NORMAL\n");
                    printf("Tension sistólica 1:%d\n", sistolica[0].sensor);
                    printf("Tension sistólica 2:%d\n", sistolica[1].sensor);
                    printf("Tension sistólica 3:%d\n", sistolica[2].sensor);
                    printf("Tension diastólica 1:%d\n", diastolica[0].sensor);
                    printf("Tension diastólica 2:%d\n", diastolica[1].sensor);
                    printf("Tension diastólica 3:%d\n", diastolica[2].sensor);
                }

                if ((((sistolica[0].sensor >120)) &&
                     ((sistolica[1].sensor > 120)) &&
                     ((sistolica[2].sensor > 120))) &&
                    ((((diastolica[0].sensor > 90) )) &&
                     ((diastolica[1].sensor > 90)) &&
                     ((diastolica[2].sensor > 90)))){
                    printf("\nTENSION ARTERIAL ALTA\n");
                    printf("Tension sistolica 1:%d\n", sistolica[0].sensor);
                    printf("Tension sistolica 2:%d\n", sistolica[1].sensor);
                    printf("Tension sistolica 3:%d\n", sistolica[2].sensor);
                    printf("Tension diastolica 1:%d\n", diastolica[0].sensor);
                    printf("Tension diastolica 2:%d\n", diastolica[1].sensor);
                    printf("Tension diastolica 3:%d\n", diastolica[2].sensor);
                    tension_alta=1;
                }

                if ((((sistolica[0].sensor < 120)) &&
                     ((sistolica[1].sensor < 120)) &&
                     ((sistolica[2].sensor < 120))) &&
                    ((((diastolica[0].sensor < 60) )) &&
                     ((diastolica[1].sensor < 60)) &&
                     ((diastolica[2].sensor < 60)))){
                    printf("\nTENSIÓN ARTERIAL BAJA\n");
                    printf("Tension sistolica 1:%d\n", sistolica[0].sensor);
                    printf("Tension sistolica 2:%d\n", sistolica[1].sensor);
                    printf("Tension sistolica 3:%d\n", sistolica[2].sensor);
                    printf("Tension diastolica 1:%d\n", diastolica[0].sensor);
                    printf("Tension diastolica 2:%d\n", diastolica[1].sensor);
                    printf("Tension diastolica 3:%d\n", diastolica[2].sensor);
                    tension_baja=1;
                }


                if (((bradicardia==1)||(taquicardia==1)) && hipoxia==1 && ((tension_alta=1)||(tension_baja=1))) {
                    printf("\033[0;31m"); // El color del texto pasa a rojo
                    printf("EMERGENCIA, Llamando al 112...");
                    printf("\033[0m"); //Resets the text to default color
                }
                printf("\nFIN DE LA MONITORIZACION\n");
            }
        }

        sem_post(&sem1);}
}

