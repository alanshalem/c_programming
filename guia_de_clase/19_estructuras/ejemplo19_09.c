/* 9. Programa que crea una estructura que almacena edad, sexo y un puntero a un vector creado
dinámicamente para almacenar el nombre. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOMBRE_CANT ((int)16) //!< Cantidad maxima de elementos del nombre.
struct persona
{
    char *nombre;
    int edad;
    char sexo;
};
int main(void)
{
    struct persona estudiante;
    char nombre[NOMBRE_CANT];
    //-- Inicializo la estructura --
    printf("Ingrese nombre:\r\n");
    scanf("%s", &nombre[0]);
    estudiante.nombre = (char *)malloc(strlen(nombre) + 1);
    if (estudiante.nombre == NULL)
    {
        return (-1);
    }
    else
    {
        strcpy(estudiante.nombre, nombre);
    }
    printf("Ingrese edad:\r\n");
    scanf("%d", &estudiante.edad);
    printf("Ingrese sexo:\r\n");
    scanf("%c", &estudiante.sexo);
    //-- Imprimo la estructura --
    printf("Nombre: %s\r\n", estudiante.nombre);
    printf("Edad: %d\r\n", estudiante.edad);
    printf("Sexo: %c\r\n", estudiante.sexo);
    return (0);
}
