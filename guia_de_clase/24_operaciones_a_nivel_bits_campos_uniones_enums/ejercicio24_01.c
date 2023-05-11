/*1. Implemente una función que devuelva el valor de un bit indicado como parámetro
int leerBit (int palabra, int bit);
Donde:
● palabra: Es el valor al cual debe procesarse.
● bit: es el número de bit a leer de palabra
La función retorna un cero si el bit leído es cero o un uno en caso contrario.*/
#include <stdio.h>

int leerBit(int palabra, int bit);

int main()
{
    int numero = 0xABCD; // 1010 1011 1100 1101 en binario
    printf("Valor de algunos bits del número %X:\n", numero);
    printf("Bit 0: %d\n", leerBit(numero, 0));   // debe imprimir 1
    printf("Bit 4: %d\n", leerBit(numero, 4));   // debe imprimir 0
    printf("Bit 8: %d\n", leerBit(numero, 8));   // debe imprimir 1
    printf("Bit 12: %d\n", leerBit(numero, 12)); // debe imprimir 1
    return 0;
}

int leerBit(int palabra, int bit)
{
    // Desplazamos un 1 bit a la izquierda tantas posiciones como el número de bit deseado
    int mascara = 1 << bit;
    // Aplicamos la operación and bit a bit para obtener el valor del bit deseado
    int valor = palabra & mascara;
    // Si el valor es distinto de cero, el bit es uno, de lo contrario es cero
    return (valor != 0);
}
