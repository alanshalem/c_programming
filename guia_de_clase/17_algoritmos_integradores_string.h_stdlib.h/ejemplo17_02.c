/* 2. Programa en el que se instancia dinámicamente un vector de 10 elementos de tipo int. Estos se
inicializan con los números del 0 al 9. Se utiliza la función qsort para ordenar el vector de mayor a
menor. Se imprime el vector antes y después de llamar a la función qsort. Finalmente se libera
memoria. */

#include <stdio.h>
#include <stdlib.h>
#define CANT ((int)10)
int comparaInt(const void *a, const void *b)
{
    int *a_, *b_;
    a_ = (int *)a;
    b_ = (int *)b;
    return (*b_ - *a_);
}
int main(void)
{
    int *p;
    int i;

    //-- Pido memoria para CANT elementos --
    p = (int *)malloc(sizeof(*p) * CANT);
    if (p == NULL)
    {
        printf("Error\r\n");
        return (-1);
    }
    //-- Inicializo la zona de memoria asignada con cero--
    for (i = 0; i < CANT; i++)
    {
        *(p + i) = i;
    }
    //-- Imprimo el vector --
    printf("Antes de qsort\r\n");
    for (i = 0; i < CANT; i++)
    {
        printf("%d\r\n", *(p + i));
    }
    //-- Ordeno --
    qsort(p, CANT, sizeof(*p), comparaInt);
    //-- Imprimo el vector --
    printf("\r\nDespues de qsort\r\n");
    for (i = 0; i < CANT; i++)
    {
        printf("%d\r\n", *(p + i));
    }
    //-- Libero memoria --
    free(p);
    return (0);
}
