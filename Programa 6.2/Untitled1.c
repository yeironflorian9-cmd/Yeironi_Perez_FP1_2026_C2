#include <stdio.h>

const int MAX = 50;

void Lectura(int [][MAX], int, int);
void Suma(int [][MAX], int [][MAX], int [][MAX], int, int);
void Imprime(int [][MAX], int, int);

void main(void) {
    int MA[MAX][MAX], MB[MAX][MAX], MC[MAX][MAX];
    int FIL, COL;

    do {
        printf("Ingrese el número de filas de los arreglos: ");
        scanf("%d", &FIL);
    } while (FIL > MAX || FIL < 1);

    do {
        printf("Ingrese el número de columnas de los arreglos: ");
        scanf("%d", &COL);
    } while (COL > MAX || COL < 1);

    printf("\nLectura del Arreglo MA\n");
    Lectura(MA, FIL, COL);

    printf("\nLectura del Arreglo MB\n");
    Lectura(MB, FIL, COL);

    Suma(MA, MB, MC, FIL, COL);

    printf("\nImpresión del Arreglo MC\n");
    Imprime(MC, FIL, COL);
}

void Lectura(int A[][MAX], int F, int C) {
    int I, J;
    for (I = 0; I < F; I++)
        for (J = 0; J < C; J++) {
            printf("Elemento [%d][%d]: ", I, J);
            scanf("%d", &A[I][J]);
        }
}

void Suma(int A[][MAX], int B[][MAX], int C[][MAX], int F, int COL) {
    int I, J;
    for (I = 0; I < F; I++)
        for (J = 0; J < COL; J++)
            C[I][J] = A[I][J] + B[I][J];
}

void Imprime(int A[][MAX], int F, int C) {
    int I, J;
    for (I = 0; I < F; I++) {
        printf("\n");
        for (J = 0; J < C; J++)
            printf("%d\t", A[I][J]);
    }
}
