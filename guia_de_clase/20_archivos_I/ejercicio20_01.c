/*1. Implemente un programa que imprima todo el contenido del archivo ejercicio20_01.c por pantalla*/

#include <stdio.h>

int main()
{
    FILE *archivo;
    char caracter;
    archivo = fopen("ejercicio20_01.c", "r"); // Abrir el archivo en modo lectura
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