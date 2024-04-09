#include <stdio.h>
#include <stdlib.h>

#define N 20

int main() {
    int i;
    double vt[N];
    double *ptr = vt;
    for(i = 0; i < N; i++) {
        *(ptr + i) = 1 + rand() % 100;
        printf("%f ", *(ptr + i));
    }
    return 0;
}