/*
3.   Implemente una función que verifique si un vector de int está ordenado de manera creciente o
 decreciente. El prototipo es
 int orden (int *dataPtr, int dataCant);
 Donde:
 dataPtr: Es el puntero a los datos
 dataCant: Es la cantidad de elementos del vector apuntado
 Devuelve: 1 si el orden es creciente;  0 si no está ordenado;  -1 si el orden es decreciente.
*/

#include <stdio.h>

int orden(int *dataPtr, int dataCant);

int main(void)
{
    int datos[] = {1, 2, 3, 4, 5};

    int resultado = orden(datos, 5);

    if (resultado == 1)
    {
        printf("Los datos están ordenados de manera creciente\n");
    }
    else if (resultado == -1)
    {
        printf("Los datos están ordenados de manera decreciente\n");
    }
    else
    {
        printf("Los datos no están ordenados\n");
    }
}

int orden(int *dataPtr, int dataCant)
{
    int i;
    int ordenCreciente = 1;
    int ordenDecreciente = 1;

    for (i = 0; i < dataCant - 1; i++)
    {
        if (dataPtr[i] > dataPtr[i + 1])
        {
            ordenCreciente = 0;
        }
        else if (dataPtr[i] < dataPtr[i + 1])
        {
            ordenDecreciente = 0;
        }
    }

    if (ordenCreciente)
    {
        return 1;
    }
    else if (ordenDecreciente)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
