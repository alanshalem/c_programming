/*
5. Programa que crea una estructura del tipo struct persona y un elemento de esta es otra estructura del
    tipo struct datos.Luego ambas son inicializadas por el usuario y lo imprime por pantalla.
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
    int i;
    //-- Inicializo la estructura --
    for (i = 0; i < CANT; i++)
    {
        printf("Ingrese nombre:\r\n");
        scanf("%s", &(estudiante[i].nombre[0]));
        printf("Ingrese edad:\r\n");
        scanf("%d", &(estudiante[i].eg.edad));
        printf("Ingrese sexo:\r\n");
        scanf("%*c%c", &(estudiante[i].eg.sexo));
    }
    //-- Imprimo el vector de estructuras --
    for (i = 0; i < CANT; i++)
    {
        printf("Nombre: %s\r\n", estudiante[i].nombre);
        printf("Edad: %d\r\n", estudiante[i].eg.edad);
        printf("Sexo: %c\r\n", estudiante[i].eg.sexo);
    }
    return (0);
}