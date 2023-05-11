// Informatica 1 - Guia de Clase - pag 44
// 7. Modifique el programa anterior para que le permita al usuario ingresar un numero en hexadecimal y
// el programa lo convierta a octal y decimal. Utilice para ello scanf con los especificadores de
// formato %o y %x

#include <stdio.h>

int main(void)
{
    int hexadecimalNumber;

    printf("Ingrese número en hexadecimal: ");
    scanf("%x", &hexadecimalNumber);

    printf("El número ingresado fue: %d (decimal); 0%o (octal)\n",
           hexadecimalNumber, hexadecimalNumber);

    return 0;
}