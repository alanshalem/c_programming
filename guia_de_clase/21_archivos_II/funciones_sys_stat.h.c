#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define O_RDONLY 'r'

int main()
{
    int fd;
    struct stat file_stat;

    fd = open("archivo.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    if (fstat(fd, &file_stat) == -1)
    {
        perror("Error al obtener la información del archivo");
        exit(EXIT_FAILURE);
    }

    printf("Tamaño del archivo: %ld bytes\n", file_stat.st_size);
    printf("Fecha de modificación: %ld\n", file_stat.st_mtime);
    printf("Permisos del archivo: %o\n", file_stat.st_mode);

    close(fd);

    return 0;
}
