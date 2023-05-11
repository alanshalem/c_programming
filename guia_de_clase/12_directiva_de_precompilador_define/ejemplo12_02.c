// 2. Programa que calcula el promedio de CANT datos ingresados.
// Advertencia:
// No se puede modificar el valor de un define en ejecución, por ejemplo NO puede hacer CANT = 0
#include <stdio.h>
#define CANT ((int)10)
int main(void)
{
    int i;
    int acc = 0, n;
    float promedio;
    for (i = 0; i < CANT; i++)
    {
        printf("Ingrese numero\r\n");
        scanf("%d", &n);
        acc += n;
    }
    promedio = acc / (float)CANT;
    printf("Promedio %f\r\n", promedio);
    return (0);
}
