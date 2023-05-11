/*2. Implemente un programa con una funcion que cree una matriz de filas por columnas y la inicializa en cero, el prototipo
de la función es:
int * matrizCrear (int filas, int columnas);*/

#include <stdio.h>
#include <stdlib.h>

int *matrizCrear(int filas, int columnas);

int main()
{
    int filas = 3;
    int columnas = 4;
    int *matriz = matrizCrear(filas, columnas);

    // Acceder y modificar elementos de la matriz
    matriz[1 * columnas + 2] = 5; // Fila 1, columna 2
    matriz[2 * columnas + 3] = 8; // Fila 2, columna 3

    // Imprimir la matriz
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%d ", matriz[i * columnas + j]);
        }
        printf("\n");
    }

    free(matriz); // Liberar la memoria asignada
    return 0;
}

int *matrizCrear(int filas, int columnas)
{
    int *matriz = malloc(filas * columnas * sizeof(int));
    if (matriz == NULL)
    {
        printf("Error al asignar memoria para la matriz\n");
        exit(1);
    }
    for (int i = 0; i < filas * columnas; i++)
    {
        matriz[i] = 0;
    }
    return matriz;
}
