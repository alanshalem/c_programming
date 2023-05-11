/*
2. Implemente un programa que le pida al usuario que ingrese letras y las almacene en memoria, el fin
del ingreso de datos ocurre cuando el usuario ingresa el signo de admiración. Luego se deberán
imprimir todas las letras ingresadas por el usuario en orden alfabético. Para ordenar coloque el
algoritmo burbujeo en una función y utilicela para ordenar.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LETTERS 100

// Función de ordenamiento de burbuja
void bubble_sort(char arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    char *letters = malloc(MAX_LETTERS * sizeof(char));
    char input;
    int index = 0;
    printf("Ingrese letras y finalice con un signo de admiración (!):\n");
