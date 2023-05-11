/*
8. Implementar una función que libere la memoria reservada.
void liberar (struct estudiante *p, int dataCant);
Donde:
p: Puntero al vector de estructuras a liberar.
dataCant: Es la cantidad de estructuras apuntadas por p.
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
    struct estudiante *p = malloc(dataCant * sizeof(struct estudiante));
    if (p == NULL)
    {
        printf("No se pudo reservar memoria.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < dataCant; i++)
    {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        scanf("%s", p[i].nombre);

        int cantFinales = 0;
        printf("Ingrese los datos de los finales del estudiante %s (materia, nota): ", p[i].nombre);
        p[i].final = NULL;

        while (1)
        {
            char materia[16];
            int nota;
            scanf("%s %d", materia, &nota);

            if (nota == -1)
            {
                break;
            }

            p[i].cantFinales = ++cantFinales;
            p[i].final = realloc(p[i].final, cantFinales * sizeof(struct finales));
            if (p[i].final == NULL)
            {
                printf("No se pudo reservar memoria.\n");
                exit(EXIT_FAILURE);
            }

            strcpy(p[i].final[cantFinales - 1].materia, materia);
            p[i].final[cantFinales - 1].nota = nota;
        }
    }

    return p;
}

void imprimir(struct estudiante *p, int dataCant)
{
    for (int i = 0; i < dataCant; i++)
    {
        printf("Estudiante %d: %s\n", i + 1, p[i].nombre);
        for (int j = 0; j < p[i].cantFinales; j++)
        {
            printf("\tMateria: %s, Nota: %d\n", p[i].final[j].materia, p[i].final[j].nota);
        }
    }
}

void liberar(struct estudiante *p, int dataCant)
{
    for (int i = 0; i < dataCant; i++)
    {
        free(p[i].final);
    }

    free(p);
}

int main()
{
    int dataCant;
    printf("Ingrese la cantidad de estudiantes: ");
    scanf("%d", &dataCant);

    struct estudiante *p = ingreso(dataCant);
    imprimir(p, dataCant);
    liberar(p, dataCant);

    return 0;
}
