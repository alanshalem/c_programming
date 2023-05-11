/*
2. Implemente un programa que le pida al usuario que ingrese la ruta completa (path) y el nombre de un
archivo (se ingresa todo junto) y luego imprima todo el contenido del archivo. Tenga en cuenta que si
usa la función fgets la misma agrega el carácter \x0A al final de lo ingresado y deberá ser eliminado,
para ello puede usar la función strchr que busca un caracter en un string y reemplácelo por ‘\0’
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char ruta[100];
    char caracter;
    FILE *archivo;
    printf("Ingrese la ruta completa y el nombre del archivo: ");
    fgets(ruta, 100, stdin); // Leer la entrada del usuario
    if (strchr(ruta, '\n') != NULL)
    { // Eliminar el carácter '\x0A' si está presente
        *strchr(ruta, '\n') = '\0';
    }
    archivo = fopen(ruta, "r"); // Abrir el archivo en modo lectura
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo.");
        return 1;
    }
    while ((caracter = fgetc(archivo)) != EOF) // Leer el archivo y mostrarlo en la pantalla
        printf("%c", caracter);
    fclose(archivo); // Cerrar el archivo
    return 0;
}
