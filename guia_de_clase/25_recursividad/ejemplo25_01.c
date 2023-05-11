/*1. Programa que cuenta de forma recursiva.*/
#include <stdio.h>
void contar(int n)
{
    printf("Numero %d\r\n", n);
    if (n > 0)
    {
        contar(n - 1);
    }
}
int main(void)
{
    int n;
    printf("Ingrese un numero:\r\n");
    scanf("%d", &n);
    contar(n);
    return (0);
}
