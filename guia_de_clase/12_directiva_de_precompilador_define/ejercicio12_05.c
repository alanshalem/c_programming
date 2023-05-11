/*
5. Implemente un programa que le pida al usuario que ingrese 10 (use define) número enteros
positivo y cuente la cantidad de números pares e impares ingresados.
*/

#include <stdio.h>

#define CANTIDAD_NUMEROS 10

int main()
{
    int numero, pares = 0, impares = 0, i;

    printf("Ingrese %d numeros enteros positivos:\n", CANTIDAD_NUMEROS);

    for (i = 0; i < CANTIDAD_NUMEROS; i++)
    {
        scanf("%d", &numero);

        if (numero % 2 == 0)
        { // si el numero es par, incrementamos el contador de pares
            pares++;
        }
        else
        { // si el numero es impar, incrementamos el contador de impares
            impares++;
        }
    }

    printf("Cantidad de numeros pares: %d\n", pares);
    printf("Cantidad de numeros impares: %d\n", impares);

    return 0;
}
