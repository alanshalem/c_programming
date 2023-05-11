/*
4. Implemente un programa que le pida al usuario diez nombres junto con diez edades y los almacene en
un archivo con el siguiente formato. Use la función fprintf.
Nombre,edad\r\n
Jose,33\r\n
Observe el contenido del archivo con un visualizador hexadecimal y con un editor de texto. Obtenga
conclusiones. El nombre del archivo es "bDatos.txt" colóquelo en un define.
*/

#include <stdio.h>

#define ARCHIVO "bDatos.txt"

int main()
{
    FILE *archivo;
    char nombre[20];
    int edad, i;
    archivo = fopen(ARCHIVO, "w"); // Crear el archivo en modo escritura (si ya existe, se sobrescribirá)
    if (archivo == NULL)
    {
        printf("Error al crear el archivo.");
        return 1;
    }
    for (i = 0; i < 10; i++)
    { // Pedir los nombres y edades al usuario y escribirlos en el archivo
        printf("Ingrese el nombre %d: ", i + 1);
        scanf("%s", nombre);
        printf("Ingrese la edad %d: ", i + 1);
        scanf("%d", &edad);
        fprintf(archivo, "%s,%d\r\n", nombre, edad);
    }
    fclose(archivo); // Cerrar el archivo
    printf("Se han escrito los datos en el archivo '%s'.\n", ARCHIVO);
    return 0;
}
