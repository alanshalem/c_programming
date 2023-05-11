/*4. Programa que lee un archivo llamado prueba.bin e imprime el contenido del mismo en pantalla.*/
#include <stdio.h>
#include <stdlib.h>
#define CANT ((int)20)
int main(void)
{
    FILE *f;
    int aux, i;
    int v[CANT], cantRead;
    //-- Abro el archivo --
    f = fopen("./prueba.bin", "r");
    if (f == NULL)
    {
        printf("Error al abrir el archivo\r\n");
        return (-1);
    }
    //-- Leo --
    cantRead = fread(&v[0], sizeof(v[0]), CANT, f);
    if (cantRead < 0)
    {
        printf("Error al escribir en el archivo\r\n");
        return (-1);
    }
    else
    {
        printf("Cantidad de enteros leidos: %d\r\n", cantRead);
        for (i = 0; i < cantRead; i++)
        {
            printf("%d\r\n", v[i]);
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
