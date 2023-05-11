/* Ejercicio 1: Desarrolle una función que pida al usuario valores de temperatura en Kelvin
(T>=0) y las almacene en un array. El ingreso de datos finaliza cuando se ingresa un valor
negativo ó cuando se llega al máximo de valores. El prototipo es el siguiente:

void ingreso_temps(float temps[ ], int len);

Donde:
● temps[ ]: array donde se guardarán las temperaturas ingresadas.
● len: largo máximo del array.

Nota:
● El valor posterior al último ingresado será un número negativo.*/

#include <stdio.h>
// Function Declarations
void ingreso_temps(float temps[], int len);

int main()
{
    float temps[100];
    int len = 100;

    ingreso_temps(temps, len);

    // Aquí puedes hacer lo que necesites con el array temps[].

    return 0;
}

// Function Definitions
void ingreso_temps(float temps[], int len)
{
    int i;
    float temp;

    for (i = 0; i < len; i++)
    {
        printf("Ingrese la temperatura en Kelvin (T>=0) o un número negativo para finalizar: ");
        scanf("%f", &temp);
        if (temp < 0)
        {
            break;
        }
        temps[i] = temp;
    }
}
