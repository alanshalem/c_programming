/*
1. Implemente un programa le pida al usuario datos para rellenar un vector de 10 estructuras del tipo
struct persona. Este vector de estructuras debe ser creado dinamicamente usando malloc. Se sabe
que el nombre ingresado por el usuario no tiene más de 16 caracteres incluyendo el ‘\0’ Para
almacenar el nombre ingresado por el usuario deberá utilizar malloc reservando exactamente la
cantidad de caracteres del nombre ingresado más el espacio para el ‘\0’. Al finalizar el ingreso
imprima todo el vector y libere la memoria reservada antes de finalizar el programa.
struct persona {
char *nombre;
int edad;
char sexo;
};
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10
#define MAX_NAME_LENGTH 16

struct persona
{
    char *nombre;
    int edad;
    char sexo;
};

int main()
{
    struct persona *personas = malloc(N * sizeof(struct persona));

    if (personas == NULL)
    {
        printf("Error: no se pudo reservar memoria.\n");
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        printf("Ingrese nombre: ");
        char nombre[MAX_NAME_LENGTH];
        scanf("%s", nombre);

        personas[i].nombre = malloc((strlen(nombre) + 1) * sizeof(char));
        if (personas[i].nombre == NULL)
        {
            printf("Error: no se pudo reservar memoria para el nombre.\n");
            return 1;
        }
        strcpy(personas[i].nombre, nombre);

        printf("Ingrese edad: ");
        scanf("%d", &(personas[i].edad));

        printf("Ingrese sexo (M o F): ");
        scanf(" %c", &(personas[i].sexo));
    }

    printf("\n");
    for (int i = 0; i < N; i++)
    {
        printf("Nombre: %s\n", personas[i].nombre);
        printf("Edad: %d\n", personas[i].edad);
        printf("Sexo: %c\n", personas[i].sexo);
        printf("\n");
    }

    for (int i = 0; i < N; i++)
    {
        free(personas[i].nombre);
    }
    free(personas);

    return 0;
}
