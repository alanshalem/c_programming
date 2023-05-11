/*10. Desarrolle un programa que imprima por pantalla el contenido del archivo creado en el punto anterior.
Tenga en cuenta que desconoce la cantidad de estructuras almacenadas*/

#include <stdio.h>
#include <stdlib.h>

#define NOMBRE_SIZE (32)
#define ARCHIVO "bDatos.bin"

struct data_S
{
    char nombre[NOMBRE_SIZE];
    int edad;
};

int main()
{
    FILE *archivo;
    struct data_S registro;

    archivo = fopen(ARCHIVO, "rb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }

    while (fread(&registro, sizeof(struct data_S), 1, archivo) == 1)
    {
        printf("Nombre: %s\n", registro.nombre);
        printf("Edad: %d\n\n", registro.edad);
    }

    fclose(archivo);
    return 0;
}
