/*
1. Programa que crea un archivo con el nombre prueba.txt, escribe en él la leyenda "Hola mundo!!!" y
cierra el archivo.
*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *f;
    int aux;
    //-- Abro el archivo --
    f = fopen("./prueba.txt", "w");
    if (f == NULL)
    {
        printf("Error al abrir el archivo\r\n");
        return (-1);
    }
    //-- Escribo --
    aux = fprintf(f, "Hola mundo!!!");
    if (aux < 0)
    {
        printf("Error al escribir en el archivo\r\n");
        return (-1);
    }
    //-- Cierro --
    aux = fclose(f);
    if (aux != 0)
    {
        printf("Error al cerrar el archivo\r\n");
    }
    return (0);
}
