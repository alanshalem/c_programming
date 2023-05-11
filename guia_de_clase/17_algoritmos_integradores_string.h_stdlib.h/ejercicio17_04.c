/*
4. Implemente una función que cuente la ocurrencia de cada carácter (histograma) de un string pasado
como parámetro.
void contarCaracteres (char *dataPtr, int *dataCntPtr);
Donde:
dataPtr: Es el puntero al string en el que hay que contar la ocurrencia de cada carácter.
dataCntPtr: Es el puntero un vector de 256 enteros en el que se lleva la cuenta de los caracteres
del string
Ejemplo:
El string apuntado por dataPtr es "11AB1B1ZZZZ1"
● La posición 65 (65 es el ASCII de la ‘A’) del vector apuntado por dataCntPtr debe tener el número 1
(Cantidad de ‘A’ en el string)
● La posición 66 (66 es el ASCII de la ‘B’) del vector apuntado por dataCntPtr debe tener el número
2 (Cantidad de ‘B’ en el string)
● La posición 90 (90 es el ASCII de la ‘Z’) del vector apuntado por dataCntPtr debe tener el número
4 (Cantidad de ‘Z’ en el string)
● La posición 49 (49 es el ASCII de la ‘1’) del vector apuntado por dataCntPtr debe tener el número 5
(Cantidad de ‘1’ en el string)
● El resto de los elementos del vector deberán estar en cero
*/

#include <stdio.h>

void contarCaracteres(char *dataPtr, int *dataCntPtr)
{
    while (*dataPtr)
    {
        int indice = *dataPtr - '0';
        dataCntPtr[indice]++;
        dataPtr++;
    }
}

int main()
{
    char data[] = "11AB1B1ZZZZ1";
    int dataCnt[256] = {0};

    contarCaracteres(data, dataCnt);

    for (int i = 0; i < 256; i++)
    {
        if (dataCnt[i] > 0)
        {
            printf("El caracter %c aparece %d veces\n", i, dataCnt[i]);
        }
    }

    return 0;
}
