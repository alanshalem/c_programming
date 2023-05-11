/*5. Implemente una función que devuelva el valor del byte indicado como parámetro
int leerByte (int palabra, int byte);
Donde:
● palabra: Es el valor al cual debe procesarse.
● byte: es el número de byte a setear de palabra.*/

#include <stdio.h>

int leerByte(int palabra, int byte);

int main()
{
    int palabra = 0x12345678;
    int byte = 2;
    int byte_leido = leerByte(palabra, byte);
    printf("Byte %d de la palabra 0x%X: 0x%X\n", byte, palabra, byte_leido);
    return 0;
}

int leerByte(int palabra, int byte)
{
    // Desplazar el byte deseado a la posición más baja
    int byte_desplazado = byte << 3;
    // Aplicar una máscara para obtener únicamente el byte deseado
    int byte_leido = (palabra >> byte_desplazado) & 0xFF;
    return byte_leido;
}
