/*
4. Implemente un programa que le pida al usuario números enteros y los almacene en 4 vectores
diferentes según su tipos.
● Positivos y cero.
● Negativos.
● Pares.
● Impares.
El usuario ingresara diez valores y luego el programa deberá imprimir por pantalla la cantidad de
números almacenados en cada vector y posteriormente los datos almacenados en cada uno de ellos
*/

#include <stdio.h>

#define MAX_NUMEROS 10

int main()
{
    int numeros[MAX_NUMEROS];
    int pos_cero[MAX_NUMEROS], negativos[MAX_NUMEROS], pares[MAX_NUMEROS], impares[MAX_NUMEROS];
    int cant_pos_cero = 0, cant_negativos = 0, cant_pares = 0, cant_impares = 0;

    // Pedir al usuario 10 números enteros y almacenarlos en el arreglo "numeros"
    for (int i = 0; i < MAX_NUMEROS; i++)
    {
        printf("Ingrese un número entero: ");
        scanf("%d", &numeros[i]);

        // Clasificar cada número según su tipo y almacenarlo en el arreglo correspondiente
        if (numeros[i] >= 0)
        {
            pos_cero[cant_pos_cero] = numeros[i];
            cant_pos_cero++;
        }
        else
        {
            negativos[cant_negativos] = numeros[i];
            cant_negativos++;
        }

        if (numeros[i] % 2 == 0)
        {
            pares[cant_pares] = numeros[i];
            cant_pares++;
        }
        else
        {
            impares[cant_impares] = numeros[i];
            cant_impares++;
        }
    }

    // Imprimir la cantidad de números almacenados en cada vector
    printf("Cantidad de números positivos y cero: %d\n", cant_pos_cero);
    printf("Cantidad de números negativos: %d\n", cant_negativos);
    printf("Cantidad de números pares: %d\n", cant_pares);
    printf("Cantidad de números impares: %d\n", cant_impares);

    // Imprimir los datos almacenados en cada vector
    printf("Números positivos y cero: ");
    for (int i = 0; i < cant_pos_cero; i++)
    {
        printf("%d ", pos_cero[i]);
    }
    printf("\n");

    printf("Números negativos: ");
    for (int i = 0; i < cant_negativos; i++)
    {
        printf("%d ", negativos[i]);
    }
    printf("\n");

    printf("Números pares: ");
    for (int i = 0; i < cant_pares; i++)
    {
        printf("%d ", pares[i]);
    }
    printf("\n");

    printf("Números impares: ");
    for (int i = 0; i < cant_impares; i++)
    {
        printf("%d ", impares[i]);
    }
    printf("\n");

    return 0;
}
