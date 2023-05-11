/*
3. Implemente un programa que le pida al usuario que ingrese letras y las almacene en memoria, el fin
del ingreso de datos ocurre cuando el usuario ingresa el signo de admiración. Luego se deberán
imprimir todas las letras ingresadas por el usuario. (Use realloc)
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *letters = NULL; // Declaramos el puntero a NULL para poder usar realloc posteriormente
    char c;
    int size = 0;

    printf("Ingrese letras (terminar con '!'): ");
    scanf(" %c", &c);

    while (c != '!')
    {
        size++;                                                  // Aumentamos el tamaño del vector en 1 por cada letra ingresada
        letters = (char *)realloc(letters, size * sizeof(char)); // Redimensionamos el vector
        if (letters == NULL)
        { // Verificamos que la reserva de memoria fue exitosa
            printf("Error: no se pudo reservar la memoria.");
            return 1;
        }
        letters[size - 1] = c; // Almacenamos la letra ingresada en la última posición del vector
        scanf(" %c", &c);
    }

    // Imprimimos todas las letras ingresadas por el usuario
    printf("Letras ingresadas: ");
    for (int i = 0; i < size; i++)
    {
        printf("%c", letters[i]);
    }
    printf("\n");

    free(letters); // Liberamos la memoria reservada

    return 0;
}