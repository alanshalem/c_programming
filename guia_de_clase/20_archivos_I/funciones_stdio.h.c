#include <stdio.h>

int main()
{
    FILE *archivo;
    archivo = fopen("datos.txt", "w");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.");
        return -1;
    }

    fprintf(archivo, "Este es un ejemplo de texto que se escribe en un archivo.\n");

    fclose(archivo);

    archivo = fopen("datos.txt", "r");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.");
        return -1;
    }

    char texto[100];
    fgets(texto, 100, archivo);
    printf("El texto del archivo es: %s\n", texto);

    fclose(archivo);

    return 0;
}
