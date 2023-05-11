// 1. Realice un programa que sume dos números "reales"(use como tipo de dato float) y lo muestre el resultado en pantalla.

#include <stdio.h>

int main(void)
{
    float num1, num2, resultado;

    printf("Ingrese número: ");
    scanf("%f", &num1);

    printf("Ingrese número: ");
    scanf("%f", &num2);

    resultado = num1 + num2;

    printf("La suma de %.2f + %.2f es igual a %.2f\n", num1, num2, resultado);

    return 0;
}
