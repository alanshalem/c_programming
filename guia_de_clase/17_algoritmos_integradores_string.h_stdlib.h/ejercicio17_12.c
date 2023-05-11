/*
12. Implemente una función que calcule el promedio de las notas pasadas por un string separadas por
espacios. La última nota tiene un espacio también. El prototipo de la función es el siguiente
float calcularPromedio (char *dataPtr)
Si el string pasado como parámetro está mal formado devuelva NAN
Ejemplos:
calcularPromedio("Hola"); // Devuelve NAN
calcularPromedio(""); // Devuelve NAN
calcularPromedio("1 2 3 12"); // Devuelve NAN
calcularPromedio("0 1 2 3 4 5 6 7 8 9 "); // Devuelve 4.5
Notas de implementación:
● Esta función solamente calcula el promedio de números de un dígito separados por espacio.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

float calcularPromedio(char *dataPtr)
{
    int notas = 0;
    float suma = 0.0;
    int len = strlen(dataPtr);

    // Verificar que el string no está vacío
    if (len == 0)
    {
        return NAN;
    }

    // Recorrer el string y contar notas válidas
    for (int i = 0; i < len; i++)
    {
        char c = *(dataPtr + i);

        // Verificar que el carácter es válido (número de un dígito o espacio)
        if (c == ' ')
        {
            notas++;
        }
        else if (c >= '0' && c <= '9')
        {
            suma += (float)(c - '0');
        }
        else
        {
            return NAN;
        }
    }

    // Verificar que hay al menos una nota
    if (notas == 0)
    {
        return NAN;
    }

    // Calcular el promedio
    float promedio = suma / notas;

    return promedio;
}

int main()
{
    char data[] = "0 1 2 3 4 5 6 7 8 9 ";
    float promedio = calcularPromedio(data);

    if (isnan(promedio))
    {
        printf("El string está mal formado\n");
    }
    else
    {
        printf("El promedio es: %.2f\n", promedio);
    }

    return 0;
}
