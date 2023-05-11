/*6. Programa que lee de un archivo llamado prueba.bin el vector de estructuras struct persona
almacenado.*/
#include <stdio.h>
#include <stdlib.h>
#define CANT ((int)3)
struct persona
{
    char nombre[16];
    int edad;
};
int main(void)
{
    FILE *f;
    int aux, i, cantRead;
    struct persona v[CANT];
    //-- Abro el archivo --
    f = fopen("./prueba.bin", "r");
    if (f == NULL)
    {
        printf("Error al abrir el archivo\r\n");
        return (-1);
    }
    //-- Leo el archivo --
    cantRead = fread(&v[0], sizeof(v[0]), CANT, f);
    if (cantRead < 0)
    {
        printf("Error al escribir en el archivo\r\n");
        return (-1);
    }
    else
    {
        printf("Cantidad de estructuras leidas: %d\r\n", cantRead);
        for (i = 0; i < CANT; i++)
        {
            printf("%d.%s,%d\r\n", i, v[i].nombre, v[i].edad);
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
