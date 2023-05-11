/*
4. Implemente un programa que le pida al usuario que ingrese 10 (use define) números enteros e
informe el mayor y el menor de todos los ingresados
*/

#include <stdio.h>

#define CANTIDAD_NUMEROS 10

int main()
{
    int numero, maximo, minimo, i;

    printf("Ingrese %d numeros enteros:\n", CANTIDAD_NUMEROS);
    scanf("%d", &numero);

    maximo = numero; // inicializamos maximo y minimo con el primer numero ingresado
    minimo = numero;

    for (i = 1; i < CANTIDAD_NUMEROS; i++)
    { // le pedimos al usuario que ingrese el resto de los numeros
        scanf("%d", &numero);

        if (numero > maximo)
        { // si encontramos un numero mayor que el maximo, actualizamos el maximo
            maximo = numero;
        }
        if (numero < minimo)
        { // si encontramos un numero menor que el minimo, actualizamos el minimo
            minimo = numero;
        }
    }

    printf("El numero mas grande es: %d\n", maximo);
    printf("El numero mas chico es: %d\n", minimo);

    return 0;
}
