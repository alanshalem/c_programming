/*3. Implemente las siguientes funciones que escriben un bit, nibble o byte de una palabra.
int escribirBit (int palabra, int bit, int datoBit);
int escribirNibble (int palabra, int nibble, int datoNibble);
int escribirByte (int palabra, int byte, int datoByte);
Donde:
● palabra: Es el valor al cual debe procesarse.
● bit: es el número de bit a setear de palabra
● datoBit: Es el valor a colocar en el bit indicado. Puede tomar el valor cero o uno.
● datoNibble: Es el valor a colocar en el nibble indicado. Puede tomar los valores desde 0x0 hasta
0xF
● datoByte: Es el valor a colocar en el byte indicado. Puede tomar los valores desde 0x00 hasta
0xFF
La función retorna la palabra modificada.
*/
int escribirBit(int palabra, int bit, int datoBit);
int escribirNibble(int palabra, int nibble, int datoNibble);
int escribirByte(int palabra, int byte, int datoByte);

#include <stdio.h>

int main()
{
    int palabra = 0;

    // escribir el bit 3 con valor 1
    palabra = escribirBit(palabra, 3, 1);
    printf("palabra con bit 3 seteado en 1: %d\n", palabra);

    // escribir el nibble alto con valor 0xA
    palabra = escribirNibble(palabra, 1, 0xA);
    printf("palabra con nibble alto seteado en 0xA: %d\n", palabra);

    // escribir el byte bajo con valor 0xFF
    palabra = escribirByte(palabra, 0, 0xFF);
    printf("palabra con byte bajo seteado en 0xFF: %d\n", palabra);

    // negar el bit 5
    palabra = negarBit(palabra, 5);
    printf("palabra con bit 5 negado: %d\n", palabra);

    // leer el bit 3
    int bit = leerBit(palabra, 3);
    printf("valor del bit 3: %d\n", bit);

    return 0;
}

int escribirBit(int palabra, int bit, int datoBit)
{
    int mask = 1 << bit; // se crea una máscara para el bit a modificar
    if (datoBit == 0)
    {                    // si el dato a colocar es cero
        mask = ~mask;    // se niega la máscara para colocar un cero en el bit indicado
        palabra &= mask; // se realiza una operación and para colocar el cero en el bit indicado
    }
    else
    {                    // si el dato a colocar es uno
        palabra |= mask; // se realiza una operación or para colocar un uno en el bit indicado
    }
    return palabra;
}

int escribirNibble(int palabra, int nibble, int datoNibble)
{
    int shift = nibble * 4;  // se calcula el desplazamiento del nibble
    int mask = 0xF << shift; // se crea una máscara para el nibble a modificar
    datoNibble <<= shift;    // se desplaza el datoNibble a la posición correspondiente
    mask = ~mask;            // se niega la máscara para borrar los bits correspondientes al nibble
    palabra &= mask;         // se realiza una operación and para borrar los bits correspondientes al nibble
    palabra |= datoNibble;   // se realiza una operación or para colocar el nibble en su posición correspondiente
    return palabra;
}

int escribirByte(int palabra, int byte, int datoByte)
{
    int shift = byte * 8;     // se calcula el desplazamiento del byte
    int mask = 0xFF << shift; // se crea una máscara para el byte a modificar
    datoByte <<= shift;       // se desplaza el datoByte a la posición correspondiente
    mask = ~mask;             // se niega la máscara para borrar los bits correspondientes al byte
    palabra &= mask;          // se realiza una operación and para borrar los bits correspondientes al byte
    palabra |= datoByte;      // se realiza una operación or para colocar el byte en su posición correspondiente
    return palabra;
}
