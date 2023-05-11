// Informatica 1 - Guia de Clase - pag 44
// 6. Realice un programa que convierta un número entero ingresado por teclado a hexadecimal y octal.
// ~$ ./ejercicio08_04.out
// Ingrese número: 16
// El número ingresado fue: 16 (decimal); 0x10 (hexadecimal); 020 (octal)

#include <stdio.h>

int main(void)
{
    int decimalNumber;

    printf("Ingrese número: ");
    scanf("%d", &decimalNumber);

    printf("El número ingresado fue: %d (decimal); 0x%X (hexadecimal); 0%o (octal)\n",
           decimalNumber, decimalNumber, decimalNumber);

    return 0;
}
