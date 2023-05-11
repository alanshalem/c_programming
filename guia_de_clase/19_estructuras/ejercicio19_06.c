/*
6. Implemente una función con el siguiente prototipo que realice el ingreso de datos para las estructuras
del los siguientes tipos.
struct finales {
char materia[16];
int nota;
};
struct estudiante {
char nombre[16]
int cantFinales;
struct finales *final;
};
struct estudiante* ingreso (int dataCant);
Donde:
dataCant: Es la cantidad de estructuras a reservar.
El usuario ingresara el nombre del estudiante y luego para cada uno ingresara el nombre de la materia
y la nota del final. La carga de los finales termina cuando se ingresa una materia con nota igual a -1.
El elemento cantFinales indica la cantidad de elementos del vector apuntado por el puntero final.
Utilice realloc para la realización de este ejercicio.
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

struct estudiante *ingreso(int dataCant)
{
    struct estudiante *estudiantes = malloc(dataCant * sizeof(struct estudiante));
    if (estudiantes == NULL)
    {
        printf("No se pudo asignar memoria\n");
        return NULL;
    }

    for (int i = 0; i < dataCant; i++)
    {
        printf("Ingrese nombre del estudiante %d: ", i + 1);
        scanf("%s", estudiantes[i].nombre);

        estudiantes[i].cantFinales = 0;
        estudiantes[i].final = NULL;

        int cantFinales = 0;
        printf("Ingrese las materias y notas del estudiante %d. Para terminar ingrese una materia con nota igual a -1.\n", i + 1);

        while (1)
        {
            estudiantes[i].final = realloc(estudiantes[i].final, (cantFinales + 1) * sizeof(struct finales));
            if (estudiantes[i].final == NULL)
            {
                printf("No se pudo asignar memoria\n");
                return estudiantes;
            }

            printf("Ingrese materia %d: ", cantFinales + 1);
            scanf("%s", estudiantes[i].final[cantFinales].materia);

            if (strcmp(estudiantes[i].final[cantFinales].materia, "-1") == 0)
            {
                break;
            }

            printf("Ingrese nota %d: ", cantFinales + 1);
            scanf("%d", &(estudiantes[i].final[cantFinales].nota));

            cantFinales++;
        }

        estudiantes[i].cantFinales = cantFinales;
    }

    return estudiantes;
}

int main()
{
    int dataCant;
    printf("Ingrese la cantidad de estudiantes a cargar: ");
    scanf("%d", &dataCant);

    struct estudiante *p = ingreso(dataCant);

    for (int i = 0; i < dataCant; i++)
    {
        printf("Estudiante %d:\n", i + 1);
        printf("Nombre: %s\n", p[i].nombre);
        printf("Cantidad de finales: %d\n", p[i].cantFinales);
        for (int j = 0; j < p[i].cantFinales; j++)
        {
            printf("Final %d:\n", j + 1);
            printf("Materia: %s\n", p[i].final[j].materia);
            printf("Nota: %d\n", p[i].final[j].nota);
        }
    }

    for (int i = 0; i < dataCant; i++)
    {
        for (int j = 0; j < p[i].cantFinales; j++)
        {
            free(p[i].final[j].materia);
        }
        free(p[i].final);
    }
    free(p);

    return 0;
}
