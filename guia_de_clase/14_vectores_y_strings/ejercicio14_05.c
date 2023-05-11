/* 5. Implemente un programa que le pida al usuario que ingrese una palabra por teclado y la imprima en
mayúscula por pantalla.*/

#include <stdio.h>
#include <ctype.h>

#define MAX_LONGITUD 100

int main()
{
    char palabra[MAX_LONGITUD];

    printf("Ingrese una palabra: ");
    scanf("%s", palabra);

    // Convertir cada caracter de la palabra en mayúscula utilizando la función "toupper"
    for (int i = 0; palabra[i] != '\0'; i++)
    {
        palabra[i] = toupper(palabra[i]);
    }

    printf("La palabra en mayúscula es: %s\n", palabra);

    return 0;
}
