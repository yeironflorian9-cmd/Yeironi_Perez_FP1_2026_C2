#include <stdio.h>
#include <time.h>

int main()
{
    int opcion;
    int cantidadJugadas = 0;
    int numeroJugado, numeroGanador;
    float cantidadApostada, cantidadGanada;
    int i, valido;

    do
    {
        printf("\n===== LOTERIA =====\n");
        printf("1. Jugar\n");
        printf("2. Elegir cantidad de jugadas\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");

        if(scanf("%d", &opcion) != 1)
        {
            printf("Entrada invalida. Debe ingresar un numero.\n");
            while(getchar() != '\n');
            opcion = 0;
            continue;
        }
        while(getchar() != '\n');

        switch(opcion)
        {
            case 1:

                if(cantidadJugadas <= 0)
                {
                    printf("Primero debe elegir la cantidad de jugadas.\n");
                    break;
                }

                for(i = 1; i <= cantidadJugadas; i++)
                {
                    printf("\n--- Jugada %d de %d ---\n", i, cantidadJugadas);

                    do
                    {
                        printf("Ingrese un numero del 1 al 40: ");

                        if(scanf("%d", &numeroJugado) != 1)
                        {
                            printf("Entrada invalida. Debe ingresar un numero.\n");
                            while(getchar() != '\n');
                            numeroJugado = -1;
                            continue;
                        }
                        while(getchar() != '\n');

                        if(numeroJugado < 1 || numeroJugado > 40)
                        {
                            printf("El numero debe estar entre 1 y 40.\n");
                        }

                    } while(numeroJugado < 1 || numeroJugado > 40);

                    do
                    {
                        printf("Ingrese la cantidad apostada: ");

                        if(scanf("%f", &cantidadApostada) != 1)
                        {
                            printf("Entrada invalida. Debe ingresar un numero.\n");
                            while(getchar() != '\n');
                            cantidadApostada = -1;
                            continue;
                        }
                        while(getchar() != '\n');

                        if(cantidadApostada <= 0)
                        {
                            printf("La cantidad debe ser mayor que cero.\n");
                        }

                    } while(cantidadApostada <= 0);

                    /* Numero ganador con time - basico y sin rand */
                    numeroGanador = (int)(time(NULL) + i) % 40 + 1;

                    if(numeroJugado == numeroGanador)
                    {
                        cantidadGanada = cantidadApostada * 1000;
                    }
                    else
                    {
                        cantidadGanada = 0;
                    }

                    printf("\n===== RESULTADO JUGADA %d =====\n", i);
                    printf("Numero jugado:     %d\n", numeroJugado);
                    printf("Numero ganador:    %d\n", numeroGanador);
                    printf("Cantidad apostada: %.2f\n", cantidadApostada);
                    printf("Cantidad ganada:   %.2f\n", cantidadGanada);

                    if(numeroJugado == numeroGanador)
                    {
                        printf("*** FELICIDADES, GANASTE! ***\n");
                    }
                    else
                    {
                        printf("No ganaste esta vez. Suerte la proxima!\n");
                    }
                }

                break;

            case 2:

                do
                {
                    printf("Ingrese la cantidad de jugadas: ");

                    if(scanf("%d", &cantidadJugadas) != 1)
                    {
                        printf("Entrada invalida. Debe ingresar un numero.\n");
                        while(getchar() != '\n');
                        cantidadJugadas = 0;
                        continue;
                    }
                    while(getchar() != '\n');

                    if(cantidadJugadas <= 0)
                    {
                        printf("La cantidad debe ser mayor que cero.\n");
                    }

                } while(cantidadJugadas <= 0);

                printf("Cantidad de jugadas establecida: %d\n", cantidadJugadas);
                break;

            case 3:

                printf("Gracias por utilizar el programa.\n");
                break;

            default:

                printf("Opcion no valida.\n");
        }

    } while(opcion != 3);

    return 0;
}
