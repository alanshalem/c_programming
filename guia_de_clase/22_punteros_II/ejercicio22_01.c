/*1. Implemente un programa que reciba por línea de comandos el nombre de un archivo e imprima en
pantalla el tamaño en bytes del mismo.*/
#include <stdio.h>

int main(int argc, char *argv[])
{
    // Verificamos que se haya pasado el nombre del archivo como argumento
    if (argc != 2)
    {
        printf("Uso: %s <archivo>\n", argv[0]);
        return 1;
    }

    // Abrimos el archivo en modo lectura
    FILE *archivo = fopen(argv[1], "rb");
    if (!archivo)
    {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Nos posicionamos al final del archivo y obtenemos su tamaño en bytes
    fseek(archivo, 0L, SEEK_END);
    long int tamano = ftell(archivo);

    printf("El archivo %s tiene un tamaño de %ld bytes.\n", argv[1], tamano);

    // Cerramos el archivo
    fclose(archivo);

    return 0;
}
