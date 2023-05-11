/*
3. Implementar una función que imprima los datos almacenados en el vector de estructuras pasado como
parámetro.
void imprimir (struct persona *p, int dataCant);
Donde:
p: Puntero al vector de estructuras.
dataCant: Es la cantidad de estructuras apuntadas por p.
*/

#include <stdio.h>
#include <stdlib.h>

struct persona
{
    char *nombre;
    int edad;
    char sexo;
};

struct persona *ingreso(int dataCant)
{
    struct persona *personas = malloc(dataCant * sizeof(struct persona));
    for (int i = 0; i < dataCant; i++)
    {
        printf("Ingrese el nombre de la persona %d: ", i + 1);
        char buffer[17]; // 16 characters plus null terminator
        scanf("%s", buffer);
        personas[i].nombre = malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(personas[i].nombre, buffer);
        printf("Ingrese la edad de la persona %d: ", i + 1);
        scanf("%d", &(personas[i].edad));
        printf("Ingrese el sexo de la persona %d (M o F): ", i + 1);
        scanf(" %c", &(personas[i].sexo));
    }
    return personas;
}

void imprimir(struct persona *p, int dataCant)
{
    for (int i = 0; i < dataCant; i++)
    {
        printf("Persona %d:\n", i + 1);
        printf("Nombre: %s\n", p[i].nombre);
        printf("Edad: %d\n", p[i].edad);
        printf("Sexo: %c\n", p[i].sexo);
    }
}

int main()
{
    int n;
    printf("Ingrese la cantidad de personas: ");
    scanf("%d", &n);
    struct persona *personas = ingreso(n);
    imprimir(personas, n);
    for (int i = 0; i < n; i++)
    {
        free(personas[i].nombre);
    }
    free(personas);
