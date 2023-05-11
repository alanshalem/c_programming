/*3. Programa que escribe en un archivo llamado prueba.bin los números enteros del 0 al 9*/
#include <stdio.h>
#include <stdlib.h>
#define CANT ((int)10)
int main(void)
{
    FILE *f;
    int aux, i;
    int v[CANT];
    //-- Abro el archivo --
    f = fopen("./prueba.bin", "w");
    if (f == NULL)
    {
        printf("Error al abrir el archivo\r\n");
        return (-1);
    }
    //-- Creo un vector con los numeros del 0 al 9 --
    for (i = 0; i < CANT; i++)
    {
        v[i] = i;
    }
    //-- Escribo --
    aux = fwrite(&v[0], sizeof(v[0]), CANT, f);

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
