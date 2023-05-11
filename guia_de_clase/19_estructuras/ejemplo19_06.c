/*
6. Programa que crea un vector de estructuras del tipo struct persona y un elemento de esta es otra
estructura del tipo struct datos. Luego el vector es inicializado utilizando un puntero y lo imprime por
pantalla utilizando el mismo puntero.
*/

#include <stdio.h>
#define NOMBRE_CANT ((int)16) //!< Cant de elementos del vector nombre
#define CANT ((int)3)         //!< Cant de elementos del vector estudiante
struct datos
{
    int edad;
    char sexo;
};
struct persona
{
    char nombre[NOMBRE_CANT];
    struct datos eg;
};
int main(void)
{
    struct persona estudiante[CANT];
    struct persona *p;
    int i;
    p = &estudiante[0]; //-- Inicializo el puntero --
    //-- Inicializo la estructura --
    for (i = 0; i < CANT; i++)
    {
        printf("Ingrese nombre:\r\n");
        scanf("%s", &((p + i)->nombre[0]));
        printf("Ingrese edad:\r\n");
        scanf("%d", &((p + i)->eg.edad));
        printf("Ingrese sexo:\r\n");
        scanf("%*c%c", &((p + i)->eg.sexo));
    }
    //-- Imprimo el vector de estructuras --
    for (i = 0; i < CANT; i++)
    {
        printf("Nombre: %s\r\n", (p + i)->nombre);
        printf("Edad: %d\r\n", (p + i)->eg.edad);
        printf("Sexo: %c\r\n", (p + i)->eg.sexo);
    }
    return (0);
}