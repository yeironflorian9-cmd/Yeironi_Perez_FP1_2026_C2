#include <stdio.h>

const int TAM = 50;

void Lectura(int *, int);
void Frecuencia(int *, int, int *, int);
void Impresion(int *, int);
void Mayor(int *, int);

void main(void) {
    int CAL[TAM], FRE[6] = {0};

    Lectura(CAL, TAM);
    Frecuencia(CAL, TAM, FRE, 6);

    printf("\nFrecuencia de Calificaciones\n");
    Impresion(FRE, 6);
    Mayor(FRE, 6);
}

void Lectura(int VEC[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("Calificacion [%d]: ", I);
        scanf("%d", &VEC[I]);
    }
}

void Impresion(int VEC[], int T) {
    int I;
    for (I = 0; I < T; I++)
        printf("Calificacion %d: %d\n", I, VEC[I]);
}

void Frecuencia(int *A, int N, int *B, int M) {
    int I;
    for (I = 0; I < N; I++)
        if ((A[I] >= 0) && (A[I] < 6))
            B[A[I]]++;
}

void Mayor(int *X, int T) {
    int I, MFRE = 0, MVAL = X[0];
    for (I = 1; I < T; I++)
        if (X[I] > MVAL) {
            MVAL = X[I];
            MFRE = I;
        }
    printf("\nLa frecuencia mas alta es %d con %d apariciones\n", MFRE, MVAL);
}
