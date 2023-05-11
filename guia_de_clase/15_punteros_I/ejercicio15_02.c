/* 2.   Implemente una función que invierta el contenido de dos variables cuyo prototipo es:
 void swap (int *a, int *b);
Donde: a y b son los punteros a las variables que se les debe invertir el contenido.*/

#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 5;
    int y = 10;

    printf("Antes del intercambio: x = %d, y = %d\n", x, y);

    swap(&x, &y);

    printf("Después del intercambio: x = %d, y = %d\n", x, y);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}