/*5. Programa que escribe en un archivo llamado prueba.bin un vector de estructuras de tipo struct
persona*/
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
    int aux, i, cantWrite;
    struct persona v[CANT];
    //-- Abro el archivo --
    f = fopen("./prueba.bin", "w");
    if (f == NULL)
    {
        printf("Error al abrir el archivo\r\n");
        return (-1);
    }
    //-- Ingreso de datos --
    for (i = 0; i < CANT; i++)
    {
        printf("Ingrese nombre\r\n");
        scanf("%s", v[i].nombre);
        printf("Ingrese edad\r\n");
        scanf("%d", &v[i].edad);
    }
    //-- Escribo --
    cantWrite = fwrite(&v[0], sizeof(v[0]), CANT, f);
    if (cantWrite < 0)
    {
        printf("Error al escribir en el archivo\r\n");
        return (-1);
    }
    else
    {
        printf("Cantidad de estructuras escritas: %d\r\n", cantWrite);
    }
    //-- Cierro --
    aux = fclose(f);
    if (aux != 0)
    {
        printf("Error al cerrar el archivo\r\n");
    }
    return (0);
}
