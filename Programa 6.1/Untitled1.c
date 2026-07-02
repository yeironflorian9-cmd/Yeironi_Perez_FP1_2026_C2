#include <stdio.h>

const int TAM = 10;

void Lectura(int [][TAM], int);
void Imprime(int [][TAM], int);

void main(void) {
    int MAT[TAM][TAM];

    Lectura(MAT, TAM);
    Imprime(MAT, TAM);
}

void Lectura(int A[][TAM], int F) {
    int I, J;
    for (I = 0; I < F; I++)
        for (J = 0; J < F; J++) {
            printf("Elemento [%d][%d]: ", I, J);
            scanf("%d", &A[I][J]);
        }
}

void Imprime(int A[][TAM], int F) {
    int I;
    printf("\nDiagonal principal:\n");
    for (I = 0; I < F; I++)
        printf("A[%d][%d] = %d\n", I, I, A[I][I]);
}
