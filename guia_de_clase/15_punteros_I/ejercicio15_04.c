/*
4. Implemente una función que devuelva un puntero al elemento que contiene el valor máximo de un
vector.
int * myMax (int *dataPtr, int dataCant);
Donde:
dataPtr: Es el puntero a los datos
dataCant: Es la cantidad de elementos del vector apuntado
Devuelve: El puntero al elemento que contiene el máximo
*/
#include <stdio.h>

int *myMax(int *dataPtr, int dataCant);

int main(void)
{
    int datos[] = {1, 2, 3, 4, 5};
    int cantElementos = sizeof(datos) / sizeof(datos[0]);
    printf("cantElementos: %d\r\n", cantElementos);
    int *posicionMaxima = myMax(datos, cantElementos);

    printf("El mayor numero es %d y se encuentra en la posicion %p\r\n", *posicionMaxima, &posicionMaxima);
    return 0;
}

int *myMax(int *dataPtr, int dataCant)
{
    int valorMaximo, indicePosicionValorMaximo, *posicionValorMaximo;

    valorMaximo = dataPtr[0];
    printf("valorMaximo: %d\r\n", valorMaximo);

    for (int i = 0; i < dataCant - 1; i++)
    {
        if (*(dataPtr + i) > valorMaximo)
        {
            valorMaximo = *(dataPtr + i);
            posicionValorMaximo = dataPtr + i;
        }
    }
    return posicionValorMaximo;
}