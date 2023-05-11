// 5. Programa que le solicita al usuario un número e indica si el mismo está entre 1 y 10 (incluyendo
// ambos)
#include <stdio.h>
int main(void)
{
    int a;
    /* Ingreso de datos */
    printf("Ingrese un numero:\r\n");
    scanf("%d", &a);
    //-- Verifico si el numero esta entre 1 y 10 --
    if ((a >= 1) && (a <= 10))
    {
        printf("El numero ingresado esta entre 1 y 10\r\n");
    }
    return (0);
}