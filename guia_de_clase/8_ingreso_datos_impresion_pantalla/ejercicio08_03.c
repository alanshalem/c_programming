// Informatica 1 - Guia de Clase - pag 44
// 3. Repita el programa anterior con los siguientes tipos de datos y valores de inicialización
// a. char: varChar = ‘c’;
// b. int: varInt = 0x55AA;
// c. int: varInt = 017;
// d. float: varFloat = 1.27;
// e. double: varDouble = 2.7172;
// Advertencia : Se utiliza el punto y no la coma para separar la parte entera de la parte decimal de un número decimal.
// Advertencia : Los números enteros que comienzan con 0x representan números en hexadecimal.Los números enteros que comienzan con 0 representan números en octal

#include <stdio.h>

int main(void)
{
    char varChar = 'c';
    printf("La variable varChar contiene el valor: %c\r\n", varChar);

    int varIntX = 0x55AA; // Hexadecimal
    printf("La variable varIntX contiene el valor (hexadecimal): %x\r\n", varIntX);

    int varIntO = 017; // Octal
    printf("La variable varIntO contiene el valor (octal): %o\r\n", varIntO);

    float varFloat = 1.27;
    printf("La variable varFloat contiene el valor: %f\r\n", varFloat);

    double varDouble = 2.7172;
    printf("La variable varDouble contiene el valor: %lf\r\n", varDouble);

    return 0;
}
