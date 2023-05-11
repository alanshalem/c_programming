/* Escribir un programa que pida el número de legajo (entero de 8 cifras) y la nota de un
examen de los alumnos de un curso.
El fin de ingreso se indica con legajo igual a cero.
El programa debe informar:
a) Cantidad de alumnos del curso
b) Promedio de las notas
c) Cantidad de alumnos aprobados (aprueban con nota igual o mayor que 6)
d) Mayor nota.
e) la cantidad de alumnos con cada calificación conceptual,  según la siguiente tabla:
Calificación Conceptual según nota numérica:
Sobresaliente 10 - Muy bueno 8 ó 9 - Bueno 6 ó 7 - Regular 4 ó 5 - Insuficiente 1 a 3 */

#include <stdio.h>
#define LEG_MIN 10000000
#define LEG_MAX 99999999
int main()
{
    int legajo, aprobados = 0, sobresaliente = 0, muy_bueno = 0, bueno = 0, regular = 0, insuficiente = 0, total_alumnos = 0;
    float nota, promedio = 0.0, mayor_nota = 0.0;

    printf("Ingrese el número de legajo y la nota del alumno (ingrese 0 para finalizar):\n");
    scanf("%d %f", &legajo, &nota);

    while (legajo != 0 && legajo >= LEG_MIN && legajo <= LEG_MAX)
    {
        if (legajo < LEG_MIN || legajo > LEG_MAX)
        {
            printf("Error, legajo invalido");
        }
        else
        {
            total_alumnos++;
            promedio += nota;
            if (nota > 0 && nota <= 10)
            {
                if (nota >= 6)
                {
                    aprobados++;
                }

                if (nota > mayor_nota)
                {
                    mayor_nota = nota;
                }

                if (nota == 10)
                {
                    sobresaliente++;
                }
                else if (nota == 8 || nota == 9)
                {
                    muy_bueno++;
                }
                else if (nota == 6 || nota == 7)
                {
                    bueno++;
                }
                else if (nota == 4 || nota == 5)
                {
                    regular++;
                }
                else
                {
                    insuficiente++;
                }
            }
            else
            {
                printf("Error, nota invalida.");
            }
        }

        printf("Ingrese el número de legajo y la nota del alumno (ingrese 0 para finalizar):\n");
        scanf("%d %f", &legajo, &nota);
    }

    if (total_alumnos == 0)
    {
        printf("No se ingresaron alumnos.\n");
    }
    else
    {
        promedio /= total_alumnos;

        printf("Cantidad de alumnos del curso: %d\n", total_alumnos);
        printf("Promedio de las notas: %.2f\n", promedio);
        printf("Cantidad de alumnos aprobados: %d\n", aprobados);
        printf("Mayor nota: %.2f\n", mayor_nota);
        printf("Cantidad de alumnos con cada calificación conceptual:\n");
        printf("Sobresaliente: %d\n", sobresaliente);
        printf("Muy bueno: %d\n", muy_bueno);
        printf("Bueno: %d\n", bueno);
        printf("Regular: %d\n", regular);
        printf("Insuficiente: %d\n", insuficiente);
    }

    return 0;
}
