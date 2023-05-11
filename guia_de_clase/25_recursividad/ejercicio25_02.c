/*2. Implemente una función que calcule la serie de Fibonacci de forma recursiva.*/
#include <stdio.h>

int fibonacci(int n);

int main()
{
    int n;
    printf("Ingrese el número de términos de la serie de Fibonacci a mostrar: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    return 0;
}

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
