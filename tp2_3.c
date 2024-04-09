#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 7

int main() {
    int mt[N][M];
    srand(time(NULL));

    int *ptr = mt[0]; 

    for (int i = 0; i < N * M; i++) {
        *(ptr + i) = 1 + rand() % 100; // Asignación de valores aleatorios utilizando aritmética de punteros
    }

    // Impresión de la matriz utilizando aritmética de punteros
    for (int i = 0; i < N * M; i++) {
        printf("%lf ", (double)*(ptr + i));
        if ((i + 1) % M == 0) {
            printf("\n");
        }

    }

    return 0;
}