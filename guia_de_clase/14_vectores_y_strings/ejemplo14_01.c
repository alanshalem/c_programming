/*
1. Programa en el cual se define un vector de diez números enteros y se inicializa en tiempo de
ejecución con los números del 0 al 9. Luego lo imprime en orden ascendente y descendente.
*/

#include <stdio.h>
#define CANT ((int)10)
int main(void)
{
    int v[CANT], i;
    //-- Inicializo el vector --
    for (i = 0; i < CANT; i++)
    {
        v[i] = i;
    }
    //-- Imprimo en orden ascendente --
    for (i = 0; i < CANT; i++)
    {
        printf("%d\r\n", v[i]);
    }
    //-- Imprimo en orden descendente --
    for (i = CANT - 1; i >= 0; i--)
    {
        printf("%d\r\n", v[i]);
    }
    return (0);
}
