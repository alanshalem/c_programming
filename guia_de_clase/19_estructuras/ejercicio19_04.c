/*
4. Implementar una función que libere la memoria reservada.
void liberar (struct persona *p, int dataCant);
Donde:
p: Puntero al vector de estructuras a liberar.
dataCant: Es la cantidad de estructuras apuntadas por p.
*/

#include <stdio.h>
#include <stdlib.h>

struct persona *ingreso(int dataCant);
void imprimir(struct persona *p, int dataCant);
void liberar(struct persona *p, int dataCant);

struct persona
{
    char *nombre;
    int edad;
    char sexo;
};

int main()
{
    int dataCant;
    printf("Ingrese la cantidad de estructuras a crear: ");
    scanf("%d", &dataCant);

    struct persona *p = ingreso(dataCant);

    imprimir(p, dataCant);

    liberar(p, dataCant);
    return 0;
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

void liberar(struct persona *p, int dataCant)
{
    for (int i = 0; i < dataCant; i++)
    {
        free(p[i].nombre);
    }
    free(p);
}