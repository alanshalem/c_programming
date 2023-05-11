// 6. Programa que le solicita al usuario un número e indica si el mismo es mayor a 10 o menor que 1
#include <stdio.h>
int main(void)
{
    int a;
    /* Ingreso de datos */
    printf("Ingrese un numero:\r\n");
    scanf("%d", &a);
    //-- Verifico si el numero es mayor a 10 o menor a 1 --
    if ((a < 1) || (a > 10))
    {
        printf("El numero ingresado es mayor que 10 o menor a 1 \r\n");
    }
    return (0);
}
