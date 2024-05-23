#include <stdio.h>
#include <pthread.h>

#define ROWS 3
#define COLS 3

int A[ROWS][COLS], B[ROWS][COLS], result[ROWS][COLS];

// Function to add rows of matrices A and B in parallel
void *addRows(void *row) {
    int rowNum = *(int *)row;
    for (int j = 0; j < COLS; j++) {
        result[rowNum][j] = A[rowNum][j] + B[rowNum][j];
    }
    pthread_exit(NULL);
}

int main() {
    // Input matrices A and B
    printf("Enter elements of matrix A (3x3):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of matrix B (3x3):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Create an array of threads for adding rows
    pthread_t threads[ROWS];

    // Create and run the threads
    int threadArgs[ROWS];
    for (int i = 0; i < ROWS; i++) {
        threadArgs[i] = i;
        pthread_create(&threads[i], NULL, addRows, &threadArgs[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < ROWS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the result matrix
    printf("Result Matrix (A + B):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
