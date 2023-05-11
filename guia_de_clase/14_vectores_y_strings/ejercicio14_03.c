/*
3. Realice un programa que permita al usuario ingresar las alturas de un grupo de como máximo cien
personas. El fin del ingreso de datos ocurre cuando la altura ingresada sea menor que cero.Luego se
le pedirá al usuario que ingrese dos valores de altura y el programa debe indicar la cantidad de
personas con alturas en ese rango. Si el intervalo ingresado por el usuario es inválido indíquelo por
pantalla.
*/

#include <stdio.h>

#define MAX_PERSONAS 100

int main()
{
    float alturas[MAX_PERSONAS];
    int num_personas = 0;
    float altura_min, altura_max;

    // Pedir alturas y almacenarlas en un arreglo hasta que se ingrese una altura negativa o se alcance el límite de 100 personas
    while (num_personas < MAX_PERSONAS)
    {
        printf("Ingrese la altura de la persona %d (en metros): ", num_personas + 1);
        scanf("%f", &alturas[num_personas]);

        if (alturas[num_personas] < 0)
        {
            break;
        }

        num_personas++;
    }

    // Pedir dos valores de altura al usuario
    printf("Ingrese dos valores de altura (en metros) para encontrar cuántas personas están dentro de ese rango.\n");
    printf("Valor mínimo: ");
    scanf("%f", &altura_min);
    printf("Valor máximo: ");
    scanf("%f", &altura_max);

    // Verificar si los valores de altura ingresados por el usuario son válidos
    if (altura_min > altura_max)
    {
        printf("El rango de alturas ingresado es inválido.\n");
        return 1;
    }

    // Contar la cantidad de personas con alturas en el rango especificado
    int cantidad_personas_en_rango = 0;
    for (int i = 0; i < num_personas; i++)
    {
        if (alturas[i] >= altura_min && alturas[i] <= altura_max)
        {
            cantidad_personas_en_rango++;
        }
    }

    // Imprimir la cantidad de personas con alturas en el rango especificado
    printf("Hay %d personas con alturas entre %.2f y %.2f metros.\n", cantidad_personas_en_rango, altura_min, altura_max);

    return 0;
}
