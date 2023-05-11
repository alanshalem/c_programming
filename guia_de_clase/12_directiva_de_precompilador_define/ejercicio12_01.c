/*1. Implemente un programa que le pida un numero al usuario e indique si el número es mayor a 100.
Coloque este umbral en un define.*/

#include <stdio.h>

#define UMBRAL 100 // definimos la constante UMBRAL como 100

int main()
{
    int numero;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if (numero > UMBRAL)
    { // comprobamos si el numero ingresado es mayor al umbral definido
        printf("El numero ingresado es mayor a %d\n", UMBRAL);
    }
    else
    {
        printf("El numero ingresado es menor o igual a %d\n", UMBRAL);
    }

    return 0;
}
