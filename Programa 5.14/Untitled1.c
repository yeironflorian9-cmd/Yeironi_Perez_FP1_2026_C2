#include <stdio.h>
#include <math.h>

const int MAX = 100;

void Lectura(int *, int);
float Media(int *, int);
float Varianza(int *, int, float);
float Desviacion(float);
void Frecuencia(int *, int, int *);
int Moda(int *, int);

void main(void) {
    int TAM, MOD, ALU[MAX], FRE[11] = {0};
    float MED, VAR, DES;

    do {
        printf("Ingrese el tamaño del arreglo: ");
        scanf("%d", &TAM);
    } while (TAM > MAX || TAM < 1);

    Lectura(ALU, TAM);
    MED = Media(ALU, TAM);
    VAR = Varianza(ALU, TAM, MED);
    DES = Desviacion(VAR);
    Frecuencia(ALU, TAM, FRE);
    MOD = Moda(FRE, 11);

    printf("\nMedia: %.2f", MED);
    printf("\nVarianza: %.2f", VAR);
    printf("\nDesviación: %.2f", DES);
    printf("\nModa: %d", MOD);
}

void Lectura(int A[], int T) {
    int I;
    for (I = 0; I < T; I++) {
        printf("Calificacion [%d]: ", I + 1);
        scanf("%d", &A[I]);
    }
}

float Media(int *A, int T) {
    int I;
    float S = 0;
    for (I = 0; I < T; I++)
        S += A[I];
    return S / T;
}

float Varianza(int *A, int T, float MED) {
    int I;
    float S = 0;
    for (I = 0; I < T; I++)
        S += pow(A[I] - MED, 2);
    return S / T;
}

float Desviacion(float VAR) {
    return sqrt(VAR);
}

void Frecuencia(int *A, int T, int *FRE) {
    int I;
    for (I = 0; I < T; I++)
        if ((A[I] >= 0) && (A[I] <= 10))
            FRE[A[I]]++;
}

int Moda(int *FRE, int T) {
    int I, MVAL = FRE[0], MPOS = 0;
    for (I = 1; I < T; I++)
        if (FRE[I] > MVAL) {
            MVAL = FRE[I];
            MPOS = I;
        }
    return MPOS;
}
