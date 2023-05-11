/*
Explicación de la función:
qsort: Ordena los elementos de un arreglo en orden ascendente utilizando el algoritmo QuickSort.
Toma cuatro argumentos: un puntero al primer elemento del arreglo, el número de elementos en el arreglo, el tamaño en bytes de cada elemento
y una función de comparación que toma dos argumentos de tipo const void* y devuelve un valor entero.
La función de comparación debe devolver un valor negativo si el primer argumento es menor que el segundo, cero si son iguales,
o un valor positivo si el primer argumento es mayor que el segundo. El puntero al primer elemento del arreglo debe ser del tipo void*.
Si los elementos del arreglo no son del mismo tipo, se deben utilizar punteros a struct que contengan los elementos y definir una función de comparación
que los compare apropiadamente. La función qsort ordena el arreglo en su lugar, es decir, modifica el arreglo original en lugar de crear uno nuevo.
*/
#include <stdio.h>
#include <stdlib.h>

// Función de comparación para qsort
int comparar(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int arr[] = {4, 2, 8, 1, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Imprimir arreglo sin ordenar
    printf("Arreglo sin ordenar: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Ordenar arreglo con qsort
    qsort(arr, n, sizeof(int), comparar);

    // Imprimir arreglo ordenado
    printf("Arreglo ordenado: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}