/*4. Programa que crea de forma dinámica una matriz de enteros bidimensional de 3 x 3 y la rellena con los
números del 0 al 9 utilizando punteros.*/
#include <stdio.h>
#include <stdlib.h>
#define FILAS ((int)3)
#define COLUMNAS ((int)3)
int main(void)
{
    int *m;
    int i, j;
    int c = 0;
    m = (int *)malloc(FILAS * COLUMNAS * sizeof(*m));
    if (m == NULL)
    {
        printf("Error malloc \r\n");
        return (-1);
    }
    //-- Inicializo la matriz --
    for (i = 0; i < FILAS; i++)
    {
        for (j = 0; j < COLUMNAS; j++)
        {
            *(m + (i * COLUMNAS) + j) = c;
            c++;
        }
    }
    //-- Imprimo la matriz --
    for (i = 0; i < FILAS; i++)
    {
        for (j = 0; j < COLUMNAS; j++)
        {
            printf("%d\t", *(m + (i * COLUMNAS) + j));
        }
        printf("\r\n");
    }
    free(m);
    return (0);
}