/*
3. Programa en el cual se le pide al usuario que ingrese 10 números, para luego imprimir de forma
separada los números pares e impares ingresados. El vector se inicializa en cero en tiempo de
compilación.
Advertencia:
Verifique siempre que el índice del vector esté dentro del rango definido
*/
#include <stdio.h>
#define CANT ((int)10)
int main(void)
{
    int v[CANT] = {0};
    int i;
    //-- Ingreso numero --
    for (i = 0; i < CANT; i++)
    {
        printf("Ingrese numero\r\n");
        scanf("%d", &v[i]);
    }
    printf("Los pares son: \r\n");
    for (i = 0; i < CANT; i++)
    {
        if ((v[i] % 2) == 0)
        {
            printf("%d.%d\r\n", i, v[i]);
        }
    }
    printf("Los impares son: \r\n");
    for (i = 0; i < CANT; i++)
    {
        if ((v[i] % 2) != 0)
        {
            printf("%d.%d\r\n", i, v[i]);
        }
    }
    return (0);
}