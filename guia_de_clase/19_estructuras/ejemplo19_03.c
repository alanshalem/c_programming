/*
3. Programa que crea un vector de estructuras del tipo struct persona. Luego el vector es inicializado por
el usuario y lo imprime por pantalla.
*/
#include <stdio.h>
#define NOMBRE_CANT ((int)16) //!< Cantidad de elementos del vector nombre
#define CANT ((int)3)         //!< Cantidad de elemento del vector estudiante

struct persona
{
    char nombre[NOMBRE_CANT];
    int edad;
    char sexo;
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
        scanf("%d", &(estudiante[i].edad));
        printf("Ingrese sexo:\r\n");
        scanf("%*c%c", &(estudiante[i].sexo));
    }
    //-- Imprimo el vector de estructuras --
    for (i = 0; i < CANT; i++)
    {
        printf("Nombre: %s\r\n", estudiante[i].nombre);
        printf("Edad: %d\r\n", estudiante[i].edad);
        printf("Sexo: %c\r\n", estudiante[i].sexo);
    }
    return (0);
}
