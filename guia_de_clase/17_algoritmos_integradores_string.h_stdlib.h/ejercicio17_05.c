/*
5. Implemente una función que cuente la ocurrencia de cada carácter (histograma) de un string pasado
como parámetro.
int* contarCaracteres (char *dataPtr);
Donde:
dataPtr: Es el puntero al string en el que hay que contar la ocurrencia de cada carácter.
83
Devuelve un puntero vector de 256 enteros en el que se lleva la cuenta de los caracteres del string, el
cual es generado dinámicamente dentro de la función.
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
● El resto de los elementos del vector deberán estar en cero.
*/

#include <stdio.h>
#include <stdlib.h>

int *contarCaracteres(char *dataPtr)
{
    int *histograma = (int *)calloc(256, sizeof(int));
    if (histograma == NULL)
    {
        printf("Error: no se pudo asignar memoria.\n");
        return NULL;
    }
    for (int i = 0; dataPtr[i] != '\0'; i++)
    {
        histograma[(int)dataPtr[i]]++;
    }
    return histograma;
}

int main()
{
    char cadena[] = "11AB1B1ZZZZ1";
    int *histograma = contarCaracteres(cadena);
    if (histograma != NULL)
    {
        for (int i = 0; i < 256; i++)
        {
            if (histograma[i] > 0)
            {
                printf("Caracter %c: %d\n", i, histograma[i]);
            }
        }
        free(histograma);
    }
    return 0;
}
