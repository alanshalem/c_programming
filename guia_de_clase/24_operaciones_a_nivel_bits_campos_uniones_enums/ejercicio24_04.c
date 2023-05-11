/*4. Implemente una función que devuelva el valor del nibble indicado como parámetro
int leerNibble (int palabra, int nibble);
Donde:
● palabra: Es el valor al cual debe procesarse.
● nibble: es el número de nibble a leer de palabra.
*/
#include <stdio.h>

int leerNibble(int palabra, int nibble);

int main()
{
    int palabra = 0x12345678; // ejemplo de palabra de 32 bits
    int nibble = 2;           // ejemplo de nibble a leer (el tercer nibble, contando desde 0)

    int valor = leerNibble(palabra, nibble); // llamada a la función

    printf("El valor del nibble %d es: 0x%X\n", nibble, valor); // salida por consola

    return 0;
}

int leerNibble(int palabra, int nibble)
{
    int desplazamiento = nibble * 4;     // desplazamiento necesario para acceder al nibble deseado
    int mascara = 0xF << desplazamiento; // máscara para seleccionar los 4 bits del nibble

    int valor = (palabra & mascara) >> desplazamiento; // operación de lectura del nibble

    return valor;
}
