/*
6. Implemente un programa que le pida al usuario que ingrese una palabra por teclado e informe la
cantidad de caracteres que esta posee sin contar el ‘\0’.
*/

#include <stdio.h>

#define MAX_LONGITUD 100

int main()
{
    char palabra[MAX_LONGITUD];

    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    int cantidad_caracteres = 0;

    // Contar la cantidad de caracteres de la palabra ingresada
    for (int i = 0; palabra[i] != '\0'; i++)
    {
        cantidad_caracteres++;
    }

    printf("La palabra ingresada tiene %d caracteres.\n", cantidad_caracteres);

    return 0;
}
