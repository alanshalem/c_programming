// 2. Programa que calcula el promedio de dos números enteros ingresados por teclado.
#include <stdio.h>
#include <math.h>
int main(void)
{
    int a, b;
    float promedio;
    /* Ingreso de datos */
    printf("Ingrese un numero:\r\n");
    scanf("%d", &a);
    printf("Ingrese un numero:\r\n");
    scanf("%d", &b);
    //-- Imprimo una leyenda y el valor almacenado en la variable --
    promedio = (float)(a + b) / (float)2.0;
    printf("El resultado es: %f\r\n", promedio);
    return 0;
}
