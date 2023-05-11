// 1. Programa que le solicita al usuario 2 números, los almacena en las variables a y b. Luego calcula a^b imprime el resultado.
#include <stdio.h>
#include <math.h>
int main(void)
{
    double a, b, r;
    /* Ingreso de datos */
    printf("Ingrese un numero:\r\n");
    scanf("%lf", &a);
    printf("Ingrese un numero:\r\n");
    scanf("%lf", &b);
    //-- Imprimo una leyenda y el valor almacenado en la variable --
    r = pow(a, b);
    printf("El resultado es: %lf\r\n", r);
    return 0;
}
