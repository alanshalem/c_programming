/*
5. Implemente una función que realice el ordenamiento de un vector de estructuras de tipo struct
persona por nombre. El prototipo de la función es el siguiente.
void ordenar(struct persona *p, int dataCant);
Donde:
p: Puntero al vector de estructuras.
dataCant: Es la cantidad de estructuras apuntadas por p
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
void imprimir(struct persona *p, int dataCant);
void liberar(struct persona *p, int dataCant);
void ordenar(struct persona *p, int dataCant);

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

void liberar(struct persona *p, int dataCant)
{
    for (int i = 0; i < dataCant; i++)
    {
        free(p[i].nombre);
    }
    free(p);
}

void ordenar(struct persona *p, int dataCant)
{
    int i, j;
    struct persona temp;

    for (i = 0; i < dataCant - 1; i++)
    {
        for (j = 0; j < dataCant - i - 1; j++)
        {
            if (strcmp(p[j].nombre, p[j + 1].nombre) > 0)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
