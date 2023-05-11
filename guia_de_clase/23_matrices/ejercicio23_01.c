/*1. Implemente una función que imprima en pantalla una matriz de filas por columnas, el prototipo de la
función es
void matrizImprimir(int *p, int filas, int columnas);
*/

#include <stdio.h>

void matrizImprimir(int *p, int filas, int columnas);

int main()
{
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int *p = &matriz[0][0];

    matrizImprimir(p, 3, 3);

    return 0;
}

void matrizImprimir(int *p, int filas, int columnas)
{
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%d ", *(p + i * columnas + j));
        }
        printf("\n");
    }
}
