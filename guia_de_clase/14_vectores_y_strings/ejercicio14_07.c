/*
7. Implemente un programa que le pida al usuario que ingrese dos palabras por teclado e indique si son
iguales o cual aparece primero en el diccionario.
*/

#include <stdio.h>
#include <string.h>

#define MAX_LONGITUD 100

int main()
{
    char palabra1[MAX_LONGITUD];
    char palabra2[MAX_LONGITUD];

    printf("Ingrese la primera palabra: ");
    scanf("%s", palabra1);

    printf("Ingrese la segunda palabra: ");
    scanf("%s", palabra2);

    int comparacion = strcmp(palabra1, palabra2);

    if (comparacion == 0)
    {
        printf("Las palabras ingresadas son iguales.\n");
    }
    else if (comparacion < 0)
    {
        printf("La primera palabra aparece primero en el diccionario.\n");
    }
    else
    {
        printf("La segunda palabra aparece primero en el diccionario.\n");
    }

    return 0;
}

/*
// SOLUCION: Sin utilizar <string.h>
#include <stdio.h>

#define MAX_LONGITUD 100

int main() {
    char palabra1[MAX_LONGITUD];
    char palabra2[MAX_LONGITUD];

    printf("Ingrese la primera palabra: ");
    scanf("%s", palabra1);

    printf("Ingrese la segunda palabra: ");
    scanf("%s", palabra2);

    int i = 0;
    while (palabra1[i] != '\0' || palabra2[i] != '\0') {
        if (palabra1[i] != palabra2[i]) {
            if (palabra1[i] < palabra2[i]) {
                printf("La primera palabra aparece primero en el diccionario.\n");
                return 0;
            } else {
                printf("La segunda palabra aparece primero en el diccionario.\n");
                return 0;
            }
        }
        i++;
    }

    printf("Las palabras ingresadas son iguales.\n");

    return 0;
}
*/