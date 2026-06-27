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

    // Ejecutar la operación seleccionada
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
 */
void codificar(char *frase, int numero) {
    int i;
    char letra;

    for (i = 0; frase[i] != '\0'; i++) {
        letra = frase[i];

        if (isupper(letra)) {
            // Desplazamiento para mayúsculas
            frase[i] = ((letra - 'A' + numero) % 26) + 'A';
        }
        else if (islower(letra)) {
            // Desplazamiento para minúsculas
            frase[i] = ((letra - 'a' + numero) % 26) + 'a';
        }
        // Los caracteres que no son letras (espacios, números, signos) no se modifican
    }
}

/**
 * Función para decodificar una frase usando el cifrado César.
 */
void decodificar(char *frase, int numero) {
    int i;
    char letra;

    for (i = 0; frase[i] != '\0'; i++) {
        letra = frase[i];

        if (isupper(letra)) {
            // Desplazamiento inverso para mayúsculas
            // Se suma 26 para manejar correctamente los números negativos
            frase[i] = ((letra - 'A' - numero + 26) % 26) + 'A';
        }
        else if (islower(letra)) {
            // Desplazamiento inverso para minúsculas
            frase[i] = ((letra - 'a' - numero + 26) % 26) + 'a';
        }
    }
}
