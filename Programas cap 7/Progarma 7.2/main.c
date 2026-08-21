#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char p1;

    printf("\nIngrese un caracter para analizar si este es un digito: ");
    scanf(" %c", &p1);

    if (isdigit(p1))
        printf("%c es un digito\n", p1);
    else
        printf("%c no es un digito\n", p1);

    printf("\nIngrese un caracter para examinar si este es una letra: ");
    scanf(" %c", &p1);

    if (isalpha(p1))
        printf("%c es una letra\n", p1);
    else
        printf("%c no es una letra\n", p1);

    printf("\nIngrese un caracter para examinar si este es una letra minuscula: ");
    scanf(" %c", &p1);

    if (isalpha(p1))
    {
        if (islower(p1))
            printf("%c es una letra minuscula\n", p1);
        else
            printf("%c no es una letra minuscula\n", p1);
    }
    else
        printf("%c no es una letra\n", p1);

    printf("\nIngrese una letra para convertirla de mayuscula a minuscula: ");
    scanf(" %c", &p1);

    if (isalpha(p1))
    {
        if (isupper(p1))
            printf("%c fue convertida de mayuscula a minuscula\n", tolower(p1));
        else
            printf("%c es una letra minuscula\n", p1);
    }
    else
        printf("%c no es una letra\n", p1);

    printf("\nPresione Enter para salir...");
    getchar();
    getchar();

    return 0;
}
