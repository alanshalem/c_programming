// Informatica 1 - Guia de Clase - pag 44
// 8. Realice un programa que le pida al usuario que ingrese una letra e imprima su correspondiente código ASCII en decimal y hexadecimal
#include <stdio.h>

int main(void)
{
    char letter;

    printf("Ingrese una letra: ");
    scanf("%c", &letter);

    printf("El código ASCII de la letra %c es %d (decimal) o 0x%X (hexadecimal)\n",
           letter, letter, letter);

    return 0;
}
