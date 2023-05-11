// 1. Programa que imprime la leyenda Hola Mundo 10 veces. Coloque este umbral en un define.
#include <stdio.h>
#define CANT ((int)10)
int main(void)
{
    int i;
    for (i = 0; i < CANT; i++)
    {
        printf("Hola Mundo\r\n");
    }
    return (0);
}
