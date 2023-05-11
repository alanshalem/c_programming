/*2. Implemente una función que niegue el valor de un bit indicado como parámetro
int negarBit (int palabra, int bit);
Donde:
● palabra: Es el valor al cual debe procesarse.
● bit: es el número de bit a negar de palabra.
La función retorna el valor del bit negado.*/

#include <stdio.h>

int negarBit(int palabra, int bit);

int main()
{
    int valor = 0b01100110; // El valor binario 01100110 en decimal es 102
    int bit_a_negar = 4;    // Se va a negar el bit número 4 (empezando desde 0)

    printf("Valor original: %d\n", valor);
    printf("Bit a negar: %d\n", bit_a_negar);

    int valor_nuevo = negarBit(valor, bit_a_negar);

    printf("Valor con bit negado: %d\n", valor_nuevo);

    return 0;
}

int negarBit(int palabra, int bit)
{
    int mascara = 1 << bit;
    return palabra ^ mascara;
}