/*
7. Programa que crea un vector de estructuras del tipo struct persona cuyos elementos son un vector
para almacenar el nombre y un vector de estructuras de tipo struct finales.
*/
#include <stdio.h>
#define NOMBRE_CANT ((int)16) //!< Cant de elementos del vector nombre
#define MATERIA_CANT ((int)16)
#define CANT ((int)3)          //!< Cant de elementos del vector estudiante
#define FINALES_CANT ((int)16) //!< Cant de elementos del vector materia
struct finales
{
    char materia[MATERIA_CANT];
    int nota;
};
struct persona
{
    char nombre[NOMBRE_CANT];
    struct finales final[FINALES_CANT];
};
int main(void)
{
    struct persona estudiante[CANT];
    struct persona *p; // declare p
    int i, j;
    p = &estudiante[0]; //-- Inicializo el puntero --
    //-- Inicializo la estructura --
    for (i = 0; i < CANT; i++)
    {
        printf("Ingrese nombre:\r\n");
        scanf("%s", &(estudiante[i].nombre[0]));
        for (j = 0; j < FINALES_CANT; j++)
        {                                   // loop up to FINALES_CANT
            printf("Ingrese materia:\r\n"); // fix parenthesis
            scanf("%s", &((p + i)->final[j].materia[0]));
            printf("Ingrese nota:\r\n");
            scanf("%d", &((p + i)->final[j].nota));
        }
    }
    //-- Imprimo el vector de estructuras --
    for (i = 0; i < CANT; i++)
    {
        printf("Nombre: %s\r\n", (p + i)->nombre);
        for (j = 0; j < FINALES_CANT; j++)
        {
            printf("Materia: %s\r\n", (p + i)->final[j].materia); // fix parenthesis
            printf("Nota: %d\r\n", (p + i)->final[j].nota);
        }
    }
    return (0);
}