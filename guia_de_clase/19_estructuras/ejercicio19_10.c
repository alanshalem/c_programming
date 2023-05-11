/*
10. Implemente un programa que realice una búsqueda por nombre y materia en un vector de estructuras de tipo struct estudiante. El prototipo de la función es el siguiente.
int buscar(struct estudiante *p, int dataCant, char *nombre, char *materia);
Donde:
p: Puntero al vector de estructuras.
dataCant: Es la cantidad de estructuras apuntadas por p
nombre: Puntero del nombre a buscar
materia: Puntero de la materia a buscar.
Devuelve:
-1: Si no encontró el nombre
-2: Si no encontró la materia
La nota si encontró el nombre y la materia.

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
int buscar(struct estudiante *p, int dataCant, char *nombre, char *materia);

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

    // Búsqueda de un estudiante por nombre y materia
    char nombre[16];
    char materia[16];
    printf("\nIngrese el nombre del estudiante a buscar: ");
    scanf("%s", nombre);
    printf("Ingrese la materia a buscar: ");
    scanf("%s", materia);

    int nota = buscar(estudiantes, n, nombre, materia);

    if (nota == -1)
    {
        printf("\nEl nombre ingresado no se encuentra en el vector de estudiantes.\n");
    }
    else if (nota == -2)
    {
        printf("\nLa materia ingresada no se encuentra en el vector de finales del estudiante buscado.\n");
    }
    else
    {
        printf("\nLa nota del estudiante %s en la materia %s es: %d\n", nombre, materia, nota);
    }

    // Liberación de memoria
    for (int i = 0; i < n; i++)
    {
        free(estudiantes[i].final);
    }
    free(estudiantes);

    return 0;
}
