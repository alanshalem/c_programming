// 1. Programa de ejemplo de operadores de pre y post incremento.
#include <stdio.h>
int main(void)
{
    int w, x, y, z;
    w = 0;
    x = 0;
    y = 0;
    z = 0;
    //-- Imprimo los valores originales --
    printf("w = %d\tx = %d\ty = %d\tz = %d\r\n", w, x, y, z);
    //-- Incremento en uno e imprimo --
    w = w + 1;
    x++;
    ++y;
    z += 1;
    printf("w = %d\tx = %d\ty = %d\tz = %d\r\n", w, x, y, z);
    //-- Incremento en uno e imprimo --
    printf("w = %d\tx = %d\ty = %d\tz = %d\r\n", w = w + 1, x++, ++y, z += 1);
    //-- Imprimo los valores --
    printf("w = %d\tx = %d\ty = %d\tz = %d\r\n", w, x, y, z);
    return (0);
}
