/* 3. Programa en el que se instancia dinámicamente un vector de 10 elementos de tipo int.Estos se
inicializan con los números del 0 al 9. Se utiliza el algoritmo del burbujeo para ordenar el vector de
mayor a menor.Se imprime el vector antes y después de ordenar.Finalmente se libera memoria.
*/

#include <stdio.h>
#include <stdlib.h>
#define CANT ((int)10)
int main(void)
{
    int *p;
    int i, j;
    int aux;

    //-- Pido memoria para CANT elementos --
    p = (int *)malloc(sizeof(*p) * CANT);
    if (p == NULL)
    {
        printf("Error\r\n");
        return (-1);
    }
    //-- Inicializo la zona de memoria asignada con cero --
    for (i = 0; i < CANT; i++)
    {
        *(p + i) = i;
    }
    //-- Imprimo el vector --
    printf("Antes de ordenar\r\n");
    for (i = 0; i < CANT; i++)
    {
        printf("%d\r\n", *(p + i));
    }
    //-- Ordeno --
    for (i = 0; i < CANT - 1; i++)
    {
        for (j = i + 1; j < CANT; j++)
        {
            if (*(p + i) < *(p + j))
            {
                aux = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = aux;
            }
        }
    }
    //-- Imprimo el vector --
    printf("\r\nDespues de ordenar\r\n");
    for (i = 0; i < CANT; i++)
    {
        printf("%d\r\n", *(p + i));
    }
    //-- Libero memoria --
    free(p);
    return (0);
}
