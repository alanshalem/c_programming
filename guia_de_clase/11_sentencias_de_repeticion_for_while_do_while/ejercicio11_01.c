// 1. Implemente un programa que imprima los números enteros pares entre el cero y el cien

#include <stdio.h>

int main(void)
{
    int i;
    for (i = 0; i <= 100; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d\r\n", i);
        }
    }
    return 0;
}