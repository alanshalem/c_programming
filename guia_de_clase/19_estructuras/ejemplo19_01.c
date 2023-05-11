/*
1. Programa que crea una estructura que contiene los datos nombre, edad y sexo. Luego es inicializada
en tiempo de ejecución y la imprime por pantalla.
*/

#include <stdio.h>
#include <string.h>
#define NOMBRE_CANT ((int)16) //!< Cantidad de elementos del vector nombre
struct persona
{
    char nombre[NOMBRE_CANT];
    int edad;
    char sexo;
};
int main(void)
{
    struct persona estudiante;
    //-- Inicializo la estructura --
    strcpy(&estudiante.nombre[0], "Juan");
    estudiante.edad = 18;
    estudiante.sexo = 'M';
    //-- Imprimo la estructura --
    printf("Nombre: %s\r\n", estudiante.nombre);
    printf("Edad: %d\r\n", estudiante.edad);
    printf("Sexo: %c\r\n", estudiante.sexo);
    return (0);
}
