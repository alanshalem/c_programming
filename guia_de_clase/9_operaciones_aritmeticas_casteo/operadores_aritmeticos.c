#include <stdio.h>

int main(void)
{
    int num1 = 10, num2 = 5;

    // Suma
    int suma = num1 + num2;
    printf("La suma de %d y %d es %d\n", num1, num2, suma);

    // Resta
    int resta = num1 - num2;
    printf("La resta de %d y %d es %d\n", num1, num2, resta);

    // Multiplicación
    int multiplicacion = num1 * num2;
    printf("La multiplicación de %d y %d es %d\n", num1, num2, multiplicacion);

    // División
    float division = (float)num1 / num2;
    printf("La división de %d y %d es %.2f\n", num1, num2, division);

    // Módulo
    int modulo = num1 % num2;
    printf("El módulo de %d y %d es %d\n", num1, num2, modulo);

    // Operadores unarios
    int num3 = 15;
    printf("El valor inicial de num3 es %d\n", num3);
    num3++; // Incremento
    printf("El valor de num3 después del incremento es %d\n", num3);
    num3--; // Decremento
    printf("El valor de num3 después del decremento es %d\n", num3);

    return 0;
}
