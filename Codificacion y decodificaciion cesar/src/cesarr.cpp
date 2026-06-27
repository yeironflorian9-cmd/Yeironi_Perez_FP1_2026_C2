#include <stdio.h>
#include <ctype.h>
#include <string.h>

void codificar(char *frase, int clave, char *resultado);
void decodificar(char *frase, int clave, char *resultado);

int main(void) {
    char frase[200], resultado[200];
    int clave, opcion;

    printf("\n=== CIFRADO DE CESAR ===\n");
    printf("Ingrese la frase: ");
    gets(frase);
    printf("Ingrese el numero de codigo (clave): ");
    scanf("%d", &clave);
    printf("\n1. Codificar\n2. Decodificar\nOpcion: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        codificar(frase, clave, resultado);
        printf("\nFrase codificada: %s\n", resultado);
    } else if (opcion == 2) {
        decodificar(frase, clave, resultado);
        printf("\nFrase decodificada: %s\n", resultado);
    } else {
        printf("\nOpcion invalida.\n");
    }
}

void codificar(char *frase, int clave, char *resultado) {
    int i = 0;
    while (frase[i] != '\0') {
        if (isalpha(frase[i])) {
            if (isupper(frase[i]))
                resultado[i] = (char)(((frase[i] - 'A' + clave) % 26) + 'A');
            else
                resultado[i] = (char)(((frase[i] - 'a' + clave) % 26) + 'a');
        } else {
            resultado[i] = frase[i];
        }
        i++;
    }
    resultado[i] = '\0';
}

void decodificar(char *frase, int clave, char *resultado) {
    int i = 0;
    while (frase[i] != '\0') {
        if (isalpha(frase[i])) {
            if (isupper(frase[i]))
                resultado[i] = (char)(((frase[i] - 'A' - clave + 26) % 26) + 'A');
            else
                resultado[i] = (char)(((frase[i] - 'a' - clave + 26) % 26) + 'a');
        } else {
            resultado[i] = frase[i];
        }
        i++;
    }
    resultado[i] = '\0';
}
