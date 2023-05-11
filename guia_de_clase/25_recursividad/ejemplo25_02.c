/*2. Programa que calcula de forma recursiva el factorial.*/
#include <stdio.h>
int factorial(int n)
{
    if (n == 0)
    {
        return (1);
    }
    else
    {
        return (n * factorial(n - 1));
    }
}
int main(void)
{
    int n, r;
    printf("Ingrese numero\r\n");
    scanf("%d", &n);
    r = factorial(n);
    printf("El factorial de %d es %d\r\n", n, r);
    return (0);
}