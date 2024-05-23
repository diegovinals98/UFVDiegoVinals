#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

void *printStrings(void *arg) {
    int threadId = *(int *)arg;
    char *string1 = (char *)arg + sizeof(int);
    char *string2 = string1 + MAX_STRING_LENGTH;
    int numTimes = *((int *)(string2 + MAX_STRING_LENGTH));

    for (int i = 1; i <= numTimes; i++) {
        printf("Hilo (%d): %d %s %s\n", threadId, i, string1, string2);
    }

    pthread_exit(NULL);
}

int main() {
    int num, i;
    printf("Ingresa un número: ");
    scanf("%d", &num);

    char string1[MAX_STRING_LENGTH];
    char string2[MAX_STRING_LENGTH];

    printf("Ingresa la primera cadena: ");
    scanf("%s", string1);
    printf("Ingresa la segunda cadena: ");
    scanf("%s", string2);

    pthread_t threads[2];
    int threadArgs[2][3];

    for (i = 0; i < 2; i++) {
        threadArgs[i][0] = i + 1;
        strncpy(threadArgs[i] + 1, string1, MAX_STRING_LENGTH);
        strncpy(threadArgs[i] + 1 + MAX_STRING_LENGTH, string2, MAX_STRING_LENGTH);
        threadArgs[i][2] = num;

        pthread_create(&threads[i], NULL, printStrings, threadArgs[i]);
    }

    for (i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
