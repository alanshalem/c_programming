/*
2. Implemente un programa que le pregunte al usuario cuantas letras desea ingresar, reserve utilizando
malloc la memoria necesaria y luego le pida al usuario caracteres hasta llenar el vector reservado
dinámicamente. Finalmente debe imprimir el vector en orden inverso al ingresado y liberar la memoria
reservada.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char *letters;

    printf("Ingrese la cantidad de letras que desea ingresar: ");
    scanf("%d", &n);

    letters = (char *)malloc(n * sizeof(char)); // Reservamos memoria para n letras

    if (letters == NULL)
    { // Verificamos que la reserva de memoria fue exitosa
        printf("Error: no se pudo reservar la memoria.");
        return 1;
    }

    // Pedimos al usuario que ingrese n caracteres para llenar el vector reservado
    printf("Ingrese %d caracteres:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %c", &letters[i]);
    }

    // Imprimimos el vector en orden inverso al ingresado
    printf("Vector en orden inverso: ");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%c ", letters[i]);
    }
    printf("\n");

    free(letters); // Liberamos la memoria reservada

    return 0;
}