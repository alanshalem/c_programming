/*3. Implemente un programa con una función que almacena una matriz pasada como parámetro en un archivo, el prototipo
de la función es el siguiente
int matrizEscribir (char *nombre, int *p, int filas, int columnas);
*/
#include <stdio.h>

int main(void)
{
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int filas = 3, columnas = 3;
    char nombre_archivo[] = "matriz.txt";

    int resultado = matrizEscribir(nombre_archivo, matriz, filas, columnas);
    if (resultado == -1)
    {
        printf("Error al escribir el archivo\n");
    }
    else
    {
        printf("Matriz escrita correctamente en el archivo %s\n", nombre_archivo);
    }

    return 0;
}

int matrizEscribir(char *nombre, int *p, int filas, int columnas)
{
    FILE *archivo;
    int i, j;

    archivo = fopen(nombre, "wb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        return -1;
    }

    fwrite(&filas, sizeof(int), 1, archivo);
    fwrite(&columnas, sizeof(int), 1, archivo);

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            fwrite(p + i * columnas + j, sizeof(int), 1, archivo);
        }
    }

    fclose(archivo);
    return 0;
}
