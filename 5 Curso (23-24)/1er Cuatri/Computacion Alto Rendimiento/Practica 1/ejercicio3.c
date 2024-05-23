#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define VECTOR_SIZE 20
#define NUM_THREADS 4

int vector[VECTOR_SIZE];
int target = 6; // Number to find
int occurrences = 0;

pthread_mutex_t mutex;

// Function for each thread to count occurrences
void *countOccurrences(void *arg) {
    int thread_id = *(int *)arg;
    int start = thread_id * (VECTOR_SIZE / NUM_THREADS);
    int end = (thread_id + 1) * (VECTOR_SIZE / NUM_THREADS);

    int localOccurrences = 0;

    for (int i = start; i < end; i++) {
        if (vector[i] == target) {
            localOccurrences++;
        }
    }

    // Lock the mutex and update the shared 'occurrences' variable
    pthread_mutex_lock(&mutex);
    occurrences += localOccurrences;
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    // Initialize the vector with random values (for demonstration)
    printf("Original Vector:\n");
    for (int i = 0; i < VECTOR_SIZE; i++) {
        vector[i] = rand() % 10; // Filling vector with random values between 0 and 9
        printf("%d ", vector[i]);
    }
    printf("\n");

    pthread_mutex_init(&mutex, NULL);

    // Create and run threads
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, countOccurrences, &thread_ids[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    printf("Number of occurrences of %d: %d\n", target, occurrences);

    return 0;
}
