/*
Ejercicio 3: Desarrolle una función que calcule y devuelva el promedio de las
temperaturas  incluidas  en  un  array,  tomando  como  válidos  solo  los  valores  entre  un
mínimo  y  un  máximo.  Los  valores  fuera  del  rango  deben  copiarse  a  otro  array.  El
prototipo es el siguiente:

float calcula_promedio (float temps [], int min, int max, float out_temps[]);

Donde:
● temps[ ]: array con las temperaturas en Kelvin (T>=0).
● min: valor mínimo a incluir en el promedio.
● max: valor máximo a incluir en el promedio.
● out_temps[ ]: array donde se copiaran las temperaturas fuera de rango.


Devuelve:
● Un valor negativo si el array empieza con un número negativo (array vacío), si todos
los valores están fuera del rango ó si min > max.
● Caso contrario, el promedio.

Nota:
● Se desconoce el largo del array temps, pero se sabe que termina con un valor negativo.
● out_temps debe terminar en un valor negativo.
● Si min ó max son negativos, se tomarán para el promedio todas las temperaturas del
array.
● El tamaño real del array out_temps es igual al de temps. */
#include <stdio.h>
float calcula_promedio(float temps[], int min, int max, float out_temps[]);

int main()
{
    float temps[] = {10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, -1.0};
    float out_temps[8] = {-1.0}; // Inicializar con -1.0
    int min = 25, max = 55;
    float promedio = calcula_promedio(temps, min, max, out_temps);
    if (promedio < 0)
    {
        printf("Error: el array es vacio o min > max\n");
    }
    else
    {
        printf("Promedio: %f\n", promedio);
    }
    printf("Temperaturas fuera de rango:\n");
    int i = 0;
    while (out_temps[i] >= 0)
    {
        printf("%f\n", out_temps[i]);
        i++;
    }
    return 0;
}

float calcula_promedio(float temps[], int min, int max, float out_temps[])
{
    int i = 0;
    float suma = 0.0, promedio;
    while (temps[i] >= 0)
    {
        if (temps[i] >= min && temps[i] <= max)
        {
            suma += temps[i];
        }
        else
        {
            out_temps[i] = temps[i];
        }
        i++;
    }
    if (i == 0 || min > max)
    {
        return -1.0; // Caso de error
    }
    else
    {
        promedio = suma / i;
        return promedio;
    }
}
