/*
2. Programa que crea una estructura que contiene los datos nombre, edad y sexo. Luego es inicializada
por el usuario y la imprime por pantalla.
*/
#include <stdio.h>
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
    printf("Ingrese nombre:\r\n");
    scanf("%s", &estudiante.nombre[0]);
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
