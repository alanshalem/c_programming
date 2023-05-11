// 1. Escriba un programa que permita el ingreso de un número entero e indique si el mismo es par o
// impar. (use if y el operador %)
#include <stdio.h>

int main()
{
    int num;

    printf("Ingrese un número entero: ");
    scanf("%d", &num);

    if (num % 2 == 0)
    {
        printf("%d es un número par.\n", num);
    }
    else
    {
        printf("%d es un número impar.\n", num);
    }

    return 0;
}
