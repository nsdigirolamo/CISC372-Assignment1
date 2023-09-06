#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 6

void matrixArrayOfArrays (int n, int m) {

    float** my_array = malloc(m * sizeof(float*));

    for (int i = 0; i < m; i++) {
        my_array[i] = malloc(n * sizeof(float));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            my_array[i][j] = (n * i) + j + 1;
            printf("%f\t", my_array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        free(my_array[i]);
    }

    free(my_array);

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

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%f\t", ptr_array[i][j]);
        }
        printf("\n");
    }

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
