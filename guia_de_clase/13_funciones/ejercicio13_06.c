/*
6. Implemente una función que calcule el factorial de un número pasado como parámetro. Si el factorial
no puede ser calculado la función debe devolver cero.
int factorial (int n);
*/

#include <stdio.h>

int factorial(int n);

int main()
{
    int num;
    printf("Ingrese un número entero: ");
    scanf("%d", &num);
    int fact = factorial(num);
    if (fact == 0)
    {
        printf("El factorial no puede ser calculado\n");
    }
    else
    {
        printf("El factorial de %d es %d\n", num, fact);
    }
    return 0;
}

int factorial(int n)
{
    if (n < 0)
    { // Factorial no definido para números negativos
        return 0;
    }
    else if (n == 0 || n == 1)
    { // Casos base
        return 1;
    }
    else
    {
        int fact = 1;
        for (int i = 2; i <= n; i++)
        {
            fact *= i;
            if (fact < 0)
            { // Desbordamiento de entero
                return 0;
            }
        }
        return fact;
    }
}
