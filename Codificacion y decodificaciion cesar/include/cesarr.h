#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Prototipos de funciones */
void codificar(char *frase, int numero);
void decodificar(char *frase, int numero);

int main() {
    char frase[200];
    int opcion, numero;

    printf("=== CIFRADO Y DESCIFRADO CÉSAR ===\n");
    printf("1. Codificar\n");
    printf("2. Decodificar\n");
    printf("Elija una opción: ");
    scanf("%d", &opcion);
    getchar(); // Limpiar el buffer de entrada

    printf("Ingrese la frase: ");
    fgets(frase, sizeof(frase), stdin);
    // Eliminar el salto de línea al final de la frase
    frase[strcspn(frase, "\n")] = 0;

    printf("Ingrese el número de código (desplazamiento): ");
    scanf("%d", &numero);

    switch (opcion) {
        case 1:
            codificar(frase, numero);
            printf("\nFrase codificada: %s\n", frase);
            break;
        case 2:
            decodificar(frase, numero);
            printf("\nFrase decodificada: %s\n", frase);
            break;
        default:
            printf("Opción no válida.\n");
    }

    return 0;
}

/**
 * Función para codificar una frase usando el cifrado César.
 *
 * @param frase   La frase a codificar (se modifica in situ).
 * @param numero  El número de posiciones a desplazar.
 */
void codificar(char *frase, int numero) {
    int i;
    char letra;

    for (i = 0; frase[i] != '\0'; i++) {
        letra = frase[i];

        // Verificar si es una letra mayúscula
        if (isupper(letra)) {
            // Aplicar el desplazamiento y asegurar que se mantenga en el rango 'A'-'Z'
            frase[i] = ((letra - 'A' + numero) % 26) + 'A';
        }
        // Verificar si es una letra minúscula
        else if (islower(letra)) {
            // Aplicar el desplazamiento y asegurar que se mantenga en el rango 'a'-'z'
            frase[i] = ((letra - 'a' + numero) % 26) + 'a';
        }
        // Si no es una letra, se deja igual (espacios, números, etc.)
    }
}

/**
 * Función para decodificar una frase usando el cifrado César.
 *
 * @param frase   La frase a decodificar (se modifica in situ).
 * @param numero  El número de posiciones a desplazar (el mismo usado para codificar).
 */
void decodificar(char *frase, int numero) {
    int i;
    char letra;

    for (i = 0; frase[i] != '\0'; i++) {
        letra = frase[i];

        if (isupper(letra)) {
            // Restar el desplazamiento. Se suma 26 para evitar números negativos en el módulo.
            frase[i] = ((letra - 'A' - numero + 26) % 26) + 'A';
        }
        else if (islower(letra)) {
            // Restar el desplazamiento. Se suma 26 para evitar números negativos en el módulo.
            frase[i] = ((letra - 'a' - numero + 26) % 26) + 'a';
        }
    }
}
