/*
2. Implemente una función con el siguiente prototipo que realice el ingreso de datos como el ejercicio
anterior.
struct persona* ingreso (int dataCant);
Donde:
dataCant: Es la cantidad de estructuras a reservar.
La función devuelve un puntero al vector de estructuras creado dinamicamente
*/

#include <stdio.h>
#include <stdlib.h>

struct persona
{
    char *nombre;
    int edad;
    char sexo;
};

struct persona *ingreso(int dataCant);

int main(void)
{
    struct persona *vecPersonas;
    int dataCant, i;

    printf("Ingrese la cantidad de personas: ");
    scanf("%d", &dataCant);

    vecPersonas = ingreso(dataCant);

    for (i = 0; i < dataCant; i++)
    {
        printf("Nombre: %s\n", vecPersonas[i].nombre);
        printf("Edad: %d\n", vecPersonas[i].edad);
        printf("Sexo: %c\n", vecPersonas[i].sexo);
        printf("-----------------\n");
    }

    for (i = 0; i < dataCant; i++)
    {
        free(vecPersonas[i].nombre);
    }
    free(vecPersonas);

    return 0;
}

struct persona *ingreso(int dataCant)
{
    struct persona *vec = malloc(dataCant * sizeof(struct persona));
    int i;

    for (i = 0; i < dataCant; i++)
    {
        char nombre[17];
        printf("Ingrese el nombre de la persona %d: ", i + 1);
        scanf("%s", nombre);

        vec[i].nombre = malloc((strlen(nombre) + 1) * sizeof(char));
        strcpy(vec[i].nombre, nombre);

        printf("Ingrese la edad de la persona %d: ", i + 1);
        scanf("%d", &vec[i].edad);

        printf("Ingrese el sexo de la persona %d (M o F): ", i + 1);
        scanf(" %c", &vec[i].sexo);
    }

    return vec;
}
