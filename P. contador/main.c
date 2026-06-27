#include <stdio.h>
#include <ctype.h>

int contarPalabras(char *frase);

void main(void) {
    char frase[200];
    int total;

    printf("\n=== CONTADOR DE PALABRAS ===\n");
    printf("Ingrese la frase: ");
    gets(frase);

    total = contarPalabras(frase);
    printf("\nTotal de palabras: %d\n", total);
}

int contarPalabras(char *frase) {
    int i = 0, palabras = 0, enPalabra = 0;

    while (frase[i] != '\0') {
        if (!isspace(frase[i])) {
            if (!enPalabra) {
                palabras++;
                enPalabra = 1;
            }
        } else {
            enPalabra = 0;
        }
        i++;
    }
    return palabras;
}
