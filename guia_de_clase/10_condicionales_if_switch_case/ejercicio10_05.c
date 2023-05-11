// 5. Implemente un programa que pida el ingreso de las notas de dos parciales para determinar si el
// estudiante de informática I:
// ○ Firmó la materia.
// ○ Promociono
// ○ Debe recuperar algún parcial.
// La nota válida estará en el rango de 1 a 10, en caso de error sale del programa.

#include <stdio.h>

int main()
{
    float nota1, nota2;

    printf("Ingrese la nota del primer parcial: ");
    if (scanf("%f", &nota1) != 1 || nota1 < 1 || nota1 > 10)
    {
        printf("Nota inválida\n");
        return 1;
    }

    printf("Ingrese la nota del segundo parcial: ");
    if (scanf("%f", &nota2) != 1 || nota2 < 1 || nota2 > 10)
    {
        printf("Nota inválida\n");
        return 1;
    }

    float promedio = (nota1 + nota2) / 2.0;
    printf("Promedio: %.2f\n", promedio);

    if (promedio >= 7.0)
    {
        printf("El estudiante ha promocionado la materia.\n");
    }
    else if (promedio >= 4.0)
    {
        printf("El estudiante ha firmado la materia.\n");
    }
    else
    {
        printf("El estudiante debe recuperar algún parcial.\n");
    }

    return 0;
}