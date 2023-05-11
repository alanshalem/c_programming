#include <stdio.h>

#define NOMBRE_CANT ((int)16)  //!< Cant de elementos del vector nombre
#define CANT ((int)3)          //!< Cant de elementos del vector estudiante
#define FINALES_CANT ((int)16) //!< Cant de elementos del vector materia

struct finales
{
    char materia[FINALES_CANT];
    int nota;
};

struct persona
{
    char nombre[NOMBRE_CANT];
    struct finales final[FINALES_CANT];
};

int main(void)
{
    struct persona estudiante[CANT], *p;
    int i, j;

    //-- Inicializo la estructura --
    for (i = 0; i < CANT; i++)
    {
        printf("Ingrese nombre:\r\n");
        scanf("%s", &(estudiante[i].nombre[0]));

        for (j = 0; j < FINALES_CANT; j++)
        {
            printf("Ingrese materias:\r\n");
            scanf("%s", &(estudiante[i].final[j].materia[0]));

            printf("Ingrese nota:\r\n");
            scanf("%d", &(estudiante[i].final[j].nota));
        }
    }

    //-- Imprimo el vector de estructuras --
    for (i = 0; i < CANT; i++)
    {
        printf("Nombre: %s\r\n", estudiante[i].nombre);

        for (j = 0; j < FINALES_CANT; j++)
        {
            printf("Materia: %s\r\n", estudiante[i].final[j].materia);
            printf("Nota: %d\r\n", estudiante[i].final[j].nota);
        }
    }

    return 0;
}
