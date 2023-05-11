/*6. Programa que escribe diez números enteros en un archivo llamado pruebaNum.txt*/
#include <stdio.h>
#include <stdlib.h>
#define CANT 10
int main(void)
{
    FILE *f;
    int aux;
    int i;
    //-- Abro el archivo --
    f = fopen("./pruebaNum.txt", "w");
    if (f == NULL)
    {
        printf("Error al abrir el archivo\r\n");
        return (-1);
    }
    //-- Escribo --
    for (i = 0; i < CANT; i++)
    {
        aux = fprintf(f, "%d\r\n", i);
        if (aux < 0)
        {
            printf("Error al escribir en el archivo\r\n");
            return (-1);
        }
    }
    //-- Cierro --
    aux = fclose(f);
    if (aux != 0)
    {
        printf("Error al cerrar el archivo\r\n");
    }
    return (0);
}
