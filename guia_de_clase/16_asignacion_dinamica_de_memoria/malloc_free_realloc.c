#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p1, *p2, *p3;
    int n = 5;

    // Asignación de memoria dinámica utilizando malloc
    // La función malloc sirve para solicitar un bloque de memoria del tamaño suministrado como parámetro. Devuelve un puntero a la zona de memoria concedida:
    // malloc: Memory Allocation
    // La función malloc devuelve un puntero inespecífico, que no apunta a un tipo de datos determinado. En C, estos punteros sin tipo se declaran como void*
    // Muchas funciones que devuelven direcciones de memoria utilizan los punteros void*. Un puntero void* puede convertirse a cualquier otra clase de puntero

    p1 = (int *)malloc(n * sizeof(int));
    if (p1 == NULL)
    {
        printf("Error: no se pudo asignar memoria\n");
        return 1;
    }

    // Acceso a los elementos de la memoria asignada
    for (int i = 0; i < n; i++)
    {
        p1[i] = i;
    }
    printf("Valores en p1:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p1[i]);
    }
    printf("\n");

    // Liberación de la memoria asignada utilizando free
    // Cuando una zona de memoria reservada con malloc ya no se necesita, puede ser liberada mediante la función free.
    free(p1);

    // Reasignación de memoria dinámica utilizando realloc
    // reallocation of memory
    p2 = (int *)realloc(NULL, n * sizeof(int));
    if (p2 == NULL)
    {
        printf("Error: no se pudo asignar memoria\n");
        return 1;
    }

    // Acceso a los elementos de la memoria asignada
    for (int i = 0; i < n; i++)
    {
        p2[i] = i * i;
    }
    printf("Valores en p2:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p2[i]);
    }
    printf("\n");

    // Ampliación de la memoria asignada utilizando realloc
    n = 10;
    p3 = (int *)realloc(p2, n * sizeof(int));
    if (p3 == NULL)
    {
        printf("Error: no se pudo asignar memoria\n");
        return 1;
    }

    // Acceso a los elementos de la memoria asignada
    for (int i = 5; i < n; i++)
    {
        p3[i] = i * i;
    }
    printf("Valores en p3:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p3[i]);
    }
    printf("\n");

    // Liberación de la memoria asignada utilizando free
    free(p3);

    return 0;
}
