/*3. Programa que agrega una línea de texto al final del archivo.*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *f;
    int aux;
    //-- Abro el archivo --
    f = fopen("./prueba.txt", "a");
    if (f == NULL)
    {
        printf("Error al abrir el archivo\r\n");
        return (-1);
    }
    //-- Escribo --
    aux = fprintf(f, "Nueva linea!!\r\n");
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
