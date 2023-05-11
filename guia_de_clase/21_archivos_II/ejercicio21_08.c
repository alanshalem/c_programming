/*8. Desarrolle un programa que imprima por pantalla en hexadecimal la segunda mitad de un archivo
indicado por el usuario. Para ello deberá usar la función fseek para posicionarse en la mitad del
archivo y luego con la función fread leerlo.*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error: Uso incorrecto del programa\n");
        printf("Sintaxis: %s nombre_archivo\n", argv[0]);
        return 1;
    }

    char *nombre_archivo = argv[1];
    FILE *archivo = fopen(nombre_archivo, "rb");

    if (archivo == NULL)
    {
        printf("Error: No se pudo abrir el archivo\n");
        return 1;
    }

    fseek(archivo, 0, SEEK_END);
    long tamano_archivo = ftell(archivo);
    long mitad_archivo = tamano_archivo / 2;

    fseek(archivo, mitad_archivo, SEEK_SET);

    char buffer[16];
    size_t bytes_leidos = 0;

    while ((bytes_leidos = fread(buffer, sizeof(char), sizeof(buffer), archivo)) > 0)
    {
        for (size_t i = 0; i < bytes_leidos; i++)
        {
            printf("%02X ", buffer[i]);
        }
    }

    printf("\n");

    fclose(archivo);
    return 0;
}
