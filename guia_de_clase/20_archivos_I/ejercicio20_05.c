/*5. Desarrolle un programa que lea el contenido de un archivo llamado "bDatos.txt" que contiene datos
con el formato descrito en el punto anterior y los coloque en un vector de las siguientes estructuras.
(use fscanf(f, "%[^,],%d\r\n", nombre, &edad); donde nombre es un string y edad es un int.)
#define NOMBRE_SIZE (32)
struct data_S {
char nombre[NOMBRE_SIZE];
unsigned int edad;
};
La cantidad máxima de registros es diez. Finalmente imprima el vector de estructuras en pantalla.
*/

#include <stdio.h>

#define ARCHIVO "bDatos.txt"
#define MAX_REGISTROS 10
#define NOMBRE_SIZE 32

struct data_S
{
    char nombre[NOMBRE_SIZE];
    unsigned int edad;
};

int main()
{
    FILE *archivo;
    struct data_S datos[MAX_REGISTROS];
    int i = 0;
    archivo = fopen(ARCHIVO, "r"); // Abrir el archivo en modo lectura
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return 1;
    }
    while (i < MAX_REGISTROS && fscanf(archivo, "%[^,],%d\r\n", datos[i].nombre, &datos[i].edad) == 2)
    {
        i++; // Leer una línea y guardarla en una estructura del vector
    }
    fclose(archivo); // Cerrar el archivo
    printf("Datos leidos del archivo '%s':\n", ARCHIVO);
    for (i = 0; i < MAX_REGISTROS && datos[i].edad > 0; i++)
    { // Imprimir el vector de estructuras en pantalla
        printf("%d - Nombre: %s, Edad: %d\n", i + 1, datos[i].nombre, datos[i].edad);
    }
    return 0;
}
