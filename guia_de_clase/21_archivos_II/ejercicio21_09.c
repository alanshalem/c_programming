/*9. Implemente un programa que le pida al usuario que ingrese nombres junto con edades y los almacene
en un archivo (Use la estructura que se encuentra debajo para almacenar los datos). El final del ingreso
de datos ocurre cuando el usuario ingresa como edad -1.
#define NOMBRE_SIZE (32)
struct data_S {
char nombre[NOMBRE_SIZE];
int edad;
};
El nombre del archivo es "bDatos.bin" colóquelo en un define.
*/
#include <stdio.h>
#include <string.h>

#define NOMBRE_SIZE (32)
#define FILENAME "bDatos.bin"

struct data_S
{
    char nombre[NOMBRE_SIZE];
    int edad;
};

int main()
{
    struct data_S datos;
    int continua = 1;

    FILE *archivo = fopen(FILENAME, "wb");

    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    while (continua)
    {
        printf("Ingrese un nombre: ");
        fgets(datos.nombre, NOMBRE_SIZE, stdin);
        datos.nombre[strcspn(datos.nombre, "\n")] = 0; // Remueve el salto de línea de la entrada
        printf("Ingrese la edad de %s: ", datos.nombre);
        scanf("%d", &datos.edad);
        getchar(); // Limpia el buffer de entrada
        if (datos.edad == -1)
        {
            continua = 0;
        }
        else
        {
            fwrite(&datos, sizeof(datos), 1, archivo);
        }
    }

    fclose(archivo);

    return 0;
}
