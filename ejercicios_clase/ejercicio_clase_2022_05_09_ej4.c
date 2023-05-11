/*
Ejercicio 4: Desarrolle un programa que, utilizando las funciones creadas anteriormente,
pida  al  usuario  una  serie  de  temperaturas  en  Kelvin,  extraiga  las  que  estén  fuera  del
rango  [MIN,MAX],  calcule  el  promedio de  los  valores  válidos  y  luego  imprima  el  array
original, el promedio calculado y el array con los valores fuera de rango.

Nota:
● LEN (largo de los arrays), MIN y MAX serán constantes simbólicas.
● Si el array original comienza con un número negativo se imprime “No hay datos”.
● Si todos los valores están fuera de rango se imprime “Todos los datos son inválidos”.
*/
#include <stdio.h>

#define LEN 10  // longitud del array
#define MIN 273 // temperatura mínima válida (en Kelvin)
#define MAX 373 // temperatura máxima válida (en Kelvin)

float promedio(float arr[], int n);
int extraerValores(float arr[], int n, float arrInvalidos[], int nInvalidos);

int main()
{
    float temperaturas[LEN];
    float invalidos[LEN];
    int nInvalidos = LEN;

    printf("Ingrese las temperaturas en Kelvin:\n");
    for (int i = 0; i < LEN; i++)
    {
        scanf("%f", &temperaturas[i]);
    }

    // verificar si el array está vacío
    if (temperaturas[0] < 0)
    {
        printf("No hay datos\n");
        return 0;
    }

    // calcular el promedio de los valores válidos
    float prom = promedio(temperaturas, LEN);

    // extraer los valores fuera del rango y contarlos
    int n = extraerValores(temperaturas, LEN, invalidos, LEN);

    // verificar si todos los valores están fuera de rango
    if (n == LEN)
    {
        printf("Todos los datos son inválidos\n");
        return 0;
    }

    // imprimir el array original
    printf("Array original:\n");
    for (int i = 0; i < LEN; i++)
    {
        printf("%.2f ", temperaturas[i]);
    }
    printf("\n");

    // imprimir el promedio
    printf("Promedio de los valores válidos: %.2f\n", prom);

    // imprimir el array con los valores fuera del rango
    printf("Valores fuera de rango:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", invalidos[i]);
    }
    printf("\n");

    return 0;
}

// función para calcular el promedio de los valores en el array
float promedio(float arr[], int n)
{
    float sum = 0.0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= MIN && arr[i] <= MAX)
        {
            sum += arr[i];
            count++;
        }
    }
    if (count == 0)
    {
        return 0.0;
    }
    return sum / count;
}

// función para extraer los valores fuera del rango
int extraerValores(float arr[], int n, float arrInvalidos[], int nInvalidos)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < MIN || arr[i] > MAX)
        {
            if (count < nInvalidos)
            {
                arrInvalidos[count] = arr[i];
            }
            count++;
        }
    }
    return count;
}
