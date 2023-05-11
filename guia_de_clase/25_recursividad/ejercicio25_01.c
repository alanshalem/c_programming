/*1. Implemente una función que calcule de forma recursiva la potencia x
y El prototipo de la función es el
siguiente:
int potencia(int x, int y)*/
#include <stdio.h>

int potencia(int x, int y);

int main()
{
    int x, y;
    printf("Ingrese la base x: ");
    scanf("%d", &x);
    printf("Ingrese el exponente y: ");
    scanf("%d", &y);
    printf("%d elevado a %d es igual a %d\n", x, y, potencia(x, y));
    return 0;
}

int potencia(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }
    else if (y < 0)
    {
        return 1 / potencia(x, -y);
    }
    else
    {
        return x * potencia(x, y - 1);
    }
}
