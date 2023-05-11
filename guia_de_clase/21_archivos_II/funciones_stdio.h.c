#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
    // Abrir un archivo para escritura y lectura
    FILE *archivo = fopen("archivo.txt", "w+");

    // Escribir en el archivo
    char texto[] = "Hola, mundo!";
    fwrite(texto, sizeof(char), sizeof(texto), archivo);

    // Obtener la posición actual dentro del archivo
    long posicion = ftell(archivo);
    printf("Posicion actual: %ld\n", posicion);

    // Moverse a la posición indicada del archivo
    fseek(archivo, 0, SEEK_SET);

    // Leer el archivo
    char buffer[50];
    fread(buffer, sizeof(char), sizeof(buffer), archivo);
    printf("Contenido del archivo: %s\n", buffer);

    // Volver al inicio del archivo
    rewind(archivo);

    // Obtener información acerca del archivo
    struct stat informacion;
    fstat(fileno(archivo), &informacion);
    printf("Tamaño del archivo: %ld bytes\n", informacion.st_size);

    // Cerrar el archivo
    fclose(archivo);

    return 0;
}
