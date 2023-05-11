/*
1. Implemente un programa que le pida al usuario que ingrese letras y las almacene en memoria, el fin
del ingreso de datos ocurre cuando el usuario ingresa el signo de admiración. Luego se deberán
imprimir todas las letras ingresadas por el usuario en orden alfabético. Utilice la función qsort.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LETTERS 100

// Función de comparación para qsort
int cmpfunc(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}

int main()
{
    char *letters = malloc(MAX_LETTERS * sizeof(char));
    char input;
    int index = 0;
    // primero se pide al usuario que ingrese las letras y se almacenan en un arreglo dinámico llamado letters.
    printf("Ingrese letras y finalice con un signo de admiración (!):\n");
    // El ciclo while se ejecuta hasta que se ingrese el signo de admiración, y verifica si el carácter ingresado es una letra (utilizando la función isalpha()).
    // Si es así, se almacena en el arreglo.
    while ((input = getchar()) != '!')
    {
        if (isalpha(input))
        {
            letters[index++] = input;
            if (index == MAX_LETTERS)
            {
                printf("Ha alcanzado el límite máximo de letras permitidas.\n");
                break;
            }
        }
    }
    // Ordenar las letras ingresadas utilizando qsort
    qsort(letters, index, sizeof(char), cmpfunc);

    printf("Las letras ingresadas en orden alfabético son:\n");
    for (int i = 0; i < index; i++)
    {
        printf("%c ", letters[i]);
    }
    printf("\n");
    free(letters);
    return 0;
}
