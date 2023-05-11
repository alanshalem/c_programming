/*4. Implemente una función que lea el archivo generado por la función matriz escribir y vuelva a
almacenar la matriz en memoria.
int matrizLeer (char *nombre, int *p,int filas, int columnas);*/

#include <stdio.h>
#include <stdlib.h>

int matrizLeer(char *nombre, int *p, int filas, int columnas);

int main()
{
    int filas = 3, columnas = 3;
    int *p = matrizCrear(filas, columnas);

    // Inicializar la matriz en cero
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            p[i * columnas + j] = 0;
        }
    }

    // Escribir la matriz en un archivo
    matrizEscribir("matriz.dat", p, filas, columnas);

    // Leer la matriz del archivo y almacenarla en memoria
    if (matrizLeer("matriz.dat", p, filas, columnas) == -1)
    {
        return -1;
    }

    // Imprimir la matriz
    matrizImprimir(p, filas, columnas);

    free(p); // Liberar la memoria de la matriz
    return 0;
}

int matrizLeer(char *nombre, int *p, int filas, int columnas)
{
    FILE *fp;
    int i, j;

    fp = fopen(nombre, "rb"); // Abrir el archivo en modo lectura binaria

    if (fp == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return -1;
    }

    // Leer la matriz del archivo y almacenarla en memoria
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            fread(&p[i * columnas + j], sizeof(int), 1, fp);
        }
    }

    fclose(fp); // Cerrar el archivo

    return 0;
}
