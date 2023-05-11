/*1. Implemente una función que imprima en hexadecimal por pantalla los datos apuntados por un puntero
El prototipo de la función es el siguiente
void printHex (void *dataPtr, int dataSize)
Donde:
○ dataPtr: Puntero a los datos a imprimir en hexadecimal.
○ dataSize: Cantidad de datos a escribir*/

#include <stdio.h>

void printHex(void *dataPtr, int dataSize)
{
    unsigned char *bytePtr = (unsigned char *)dataPtr; // Convertir el puntero a un puntero a bytes
    int i;
    for (i = 0; i < dataSize; i++)
    {
        printf("%02x ", bytePtr[i]); // Imprimir cada byte en hexadecimal
    }
    printf("\n"); // Imprimir un salto de línea al final
}

int main()
{
    int x = 12345;
    float y = 3.14159;
    char z = 'A';

    printf("x en hexadecimal: ");
    printHex(&x, sizeof(x)); // Pasar el puntero a x y su tamaño a la función

    printf("y en hexadecimal: ");
    printHex(&y, sizeof(y)); // Pasar el puntero a y y su tamaño a la función

    printf("z en hexadecimal: ");
    printHex(&z, sizeof(z)); // Pasar el puntero a z y su tamaño a la función

    return 0;
}
