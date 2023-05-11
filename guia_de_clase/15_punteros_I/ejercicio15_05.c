/*
5. Implemente una función que devuelva un puntero al elemento que contiene el valor mínimo de un
vector.
int * myMin (int *dataPtr, int dataCant);
Donde:
dataPtr: Es el puntero a los datos
dataCant: Es la cantidad de elementos del vector apuntado
Devuelve: El puntero al elemento que contiene el mínimo
*/

#include <stdio.h>

int *myMin(int *dataPtr, int dataCant)
{
    int minVal = *dataPtr;
    int *minPtr = dataPtr;
    for (int i = 1; i < dataCant; i++)
    {
        if (*(dataPtr + i) < minVal)
        {
            minVal = *(dataPtr + i);
            minPtr = dataPtr + i;
        }
    }
    return minPtr;
}

int main()
{
    int data[] = {3, 7, 1, 9, 4};
    int *minPtr = myMin(data, 5);
    printf("El valor mínimo es %d y se encuentra en la posición %ld del vector.\n", *minPtr, minPtr - data);
    return 0;
}
