/*3. Programa que crea de forma estática una matriz de enteros bidimensional de 3 x 3 y la rellena con los
números del 0 al 9 utilizando punteros.*/
#include <stdio.h>
#define FILAS ((int)3)
#define COLUMNAS ((int)3)
int main(void)
{
    int m[FILAS][COLUMNAS];
    int i, j;
    int *p;
    p = &m[0][0];
    //-- Inicializo la matriz --
    for (i = 0; i < FILAS * COLUMNAS; i++)
    {
        *(p + i) = i;
    }
    //-- Imprimo la matriz --
    for (i = 0; i < FILAS; i++)
    {
        for (j = 0; j < COLUMNAS; j++)
        {
            printf("%d\t", *(p + (i * COLUMNAS) + j));
        }
        printf("\r\n");
    }
    return (0);
}
