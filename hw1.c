#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 6

void printArray (float** a, int n, int m) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f\t", a[i][j]);
        }
        printf("\n");
    }
}

void printArrayTranspose (float** a, int n, int m) {
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            printf("%f\t", a[i][j]);
        }
        printf("\n");
    }
}

void matrixArrayOfArrays (int n, int m) {

    float** array = malloc(m * sizeof(float*));

    for (int i = 0; i < m; i++) {
        array[i] = malloc(n * sizeof(float));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = (n * i) + j + 1;
        }
    }

    printArray(array, n, m);
    printf("\n");
    printArrayTranspose(array, n, m);

    for (int i = 0; i < m; i++) {
        free(array[i]);
    }

    free(array);

    return;
}

void matrixOneBigArray (int n, int m) {

    float** ptr_array = malloc(m * sizeof(float*));
    float* num_array = malloc(m * n * sizeof(float));

    for (int i = 0; i < m; i++) {
        ptr_array[i] = &num_array[i * n];
    }

    for (int j = 0; j < m * n; j++) {
        num_array[j] = j + 1;
    }

    printArray(ptr_array, n, m);
    printf("\n");
    printArrayTranspose(ptr_array, n, m);

    free(ptr_array);
    free(num_array);

    return;
}

int main (int argc, char** argv) {
    matrixArrayOfArrays(N, M);
    printf("\n");
    matrixOneBigArray(N, M);
    return 0;
}
