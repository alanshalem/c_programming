// Informatica 1 - Guia de Clase - pag 44
// 9. Realice un programa que le pida al usuario un número tipo float y lo imprima en pantalla con solo dos
// dígitos luego del punto decimal.

#include <stdio.h>

int main(void)
{
    float number;

    printf("Ingrese un número: ");
    scanf("%f", &number);

    printf("El número ingresado es: %.2f\n", number);

    return 0;
}