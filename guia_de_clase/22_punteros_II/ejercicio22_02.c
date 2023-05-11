/*2. Implemente un programa que realice la copia de un archivo. El nombre del archivo origen y destino la
reciba por línea de comandos. (Similar al comando cp)*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    FILE *src_file, *dst_file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read, bytes_written;

    // Verificar que se hayan ingresado correctamente los argumentos
    if (argc != 3)
    {
        printf("Uso: %s <archivo_origen> <archivo_destino>\n", argv[0]);
        return 1;
    }

    // Abrir archivo de origen en modo lectura
    src_file = fopen(argv[1], "rb");
    if (src_file == NULL)
    {
        printf("No se pudo abrir el archivo de origen '%s'\n", argv[1]);
        return 1;
    }

    // Abrir archivo de destino en modo escritura (crea el archivo si no existe)
    dst_file = fopen(argv[2], "wb");
    if (dst_file == NULL)
    {
        printf("No se pudo abrir el archivo de destino '%s'\n", argv[2]);
        fclose(src_file);
        return 1;
    }

    // Leer el archivo de origen y escribir en el archivo de destino
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src_file)) > 0)
    {
        bytes_written = fwrite(buffer, 1, bytes_read, dst_file);
        if (bytes_written != bytes_read)
        {
            printf("Error al escribir en el archivo de destino\n");
            fclose(src_file);
            fclose(dst_file);
            return 1;
        }
    }

    // Cerrar archivos y terminar programa
    fclose(src_file);
    fclose(dst_file);
    printf("Archivo copiado correctamente\n");
    return 0;
}
