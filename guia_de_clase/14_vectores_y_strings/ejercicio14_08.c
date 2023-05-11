/*8. Implemente un programa que le pida al usuario que ingrese una palabra y un carácter por teclado. A
continuación reemplace este carácter en la palabra por asterisco. Finalmente debe indicar la cantidad
de veces que reemplazó el carácter*/

#include <stdio.h>
#include <string.h>

#define MAX_LONGITUD 100

int main()
{
    char palabra[MAX_LONGITUD], caracter;
    int cantidad_reemplazos = 0;

    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    printf("Ingrese un caracter: ");
    scanf(" %c", &caracter);

    for (int i = 0; palabra[i] != '\0'; i++)
    {
        if (palabra[i] == caracter)
        {
            palabra[i] = '*';
            cantidad_reemplazos++;
        }
    }

    // Otra forma:
    /*
        while (palabra[i] != '\0') {
        if (palabra[i] == caracter) {
            palabra[i] = '*';
            cantidad_reemplazos++;
        }
        i++;
    }
    */

    printf("La palabra resultante es: %s\n", palabra);
    printf("Se reemplazaron %d caracteres '%c' por asteriscos.\n", cantidad_reemplazos, caracter);

    return 0;
}