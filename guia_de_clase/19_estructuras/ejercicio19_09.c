/*
9. Implemente una función que realice el ordenamiento de un vector de estructuras de tipo struct
estudiante por cantidad de finales. El prototipo de la función es el siguiente.
void ordenar(struct estudiante *p, int dataCant);
Donde:
p: Puntero al vector de estructuras.
dataCant: Es la cantidad de estructuras apuntadas por p
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct finales
{
    char materia[16];
    int nota;
};

struct estudiante
{
    char nombre[16];
    int cantFinales;
    struct finales *final;
};

void ordenar(struct estudiante *p, int dataCant);

int main()
{
    int n;
    printf("Ingrese la cantidad de estudiantes: ");
    scanf("%d", &n);

    // Reserva de memoria para el vector de estudiantes
    struct estudiante *estudiantes = (struct estudiante *)malloc(n * sizeof(struct estudiante));
    if (estudiantes == NULL)
    {
        printf("Error al reservar memoria.\n");
        return -1;
    }

    // Ingreso de datos para cada estudiante
    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        scanf("%s", estudiantes[i].nombre);

        // Reserva de memoria para el vector de finales de cada estudiante
        estudiantes[i].final = (struct finales *)malloc(sizeof(struct finales));
        if (estudiantes[i].final == NULL)
        {
            printf("Error al reservar memoria.\n");
            return -1;
        }

        printf("Ingrese la materia del final del estudiante %d: ", i + 1);
        scanf("%s", estudiantes[i].final[0].materia);

        int cantFinales = 0;
        while (estudiantes[i].final[cantFinales].nota != -1)
        {
            printf("Ingrese la nota de la materia %s del estudiante %d: ", estudiantes[i].final[cantFinales].materia, i + 1);
            scanf("%d", &estudiantes[i].final[cantFinales].nota);

            // Si el usuario ingresa una materia con nota -1, se detiene el ingreso de finales
            if (estudiantes[i].final[cantFinales].nota == -1)
            {
                break;
            }

            // Si se ingresaron todos los finales para el vector actual, se reserva más memoria
            if (cantFinales > 0)
            {
                estudiantes[i].final = (struct finales *)realloc(estudiantes[i].final, (cantFinales + 1) * sizeof(struct finales));
                if (estudiantes[i].final == NULL)
                {
                    printf("Error al reservar memoria.\n");
                    return -1;
                }
            }

            // Ingreso de la siguiente materia
            printf("Ingrese la materia del final del estudiante %d: ", i + 1);
            scanf("%s", estudiantes[i].final[cantFinales + 1].materia);

            cantFinales++;
        }

        // Actualización de la cantidad de finales para el estudiante actual
        estudiantes[i].cantFinales = cantFinales;
    }

    // Ordenamiento de los estudiantes por cantidad de finales
    ordenar(estudiantes, n);

    // Impresión de los estudiantes ordenados
    printf("\nEstudiantes ordenados por cantidad de finales:\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nNombre del estudiante %d: %s\n", i + 1, estudiantes[i].nombre);
        printf("Cantidad de finales: %d\n", estudiantes[i].cantFinales);
        printf("Finales:\n");
        for (int j = 0; j < estudiantes[i].cantFinales; j++)
        {
            printf("- Materia: %s, Nota: %d\n", estudiantes[i].final[j].materia, estudiantes[i].final[j].nota);
        }
    }
    // Liberación de memoria
    for (int i = 0; i < n; i++)
    {
        free(estudiantes[i].final);
    }
    free(estudiantes);

    return 0;
}

void ordenar(struct estudiante *p, int dataCant)
{
    for (int i = 0; i < dataCant; i++)
    {
        for (int j = i + 1; j < dataCant; j++)
        {
            if (p[i].cantFinales > p[j].cantFinales)
            {
                struct estudiante temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}