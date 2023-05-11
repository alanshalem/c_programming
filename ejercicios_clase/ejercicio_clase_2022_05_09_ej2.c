/*Ejercicio 2: Desarrolle una función que imprima un array de temperaturas, sabiendo que
el mismo termina en un número negativo.

El prototipo es el siguiente:

void print_temps(float temps[ ]);

Donde:
● temps[ ]: array de temperaturas.

Nota:
● Esta función NO conoce el largo del array, sólo sabe que termina  en  un  número
negativo. */

#include <stdio.h>

void print_temps(float temps[]);

int main()
{
    float temps[] = {24.5, 25.6, 26.8, 27.4, -1.0};
    print_temps(temps);
    return 0;
}

void print_temps(float temps[])
{
    int i = 0;
    while (temps[i] >= 0)
    {
        printf("%.2f ", temps[i]);
        i++;
    }
}