// 2. Programa que le solicita al usuario un número y nos indica si es mayor o igual a 6 o es menor.
#include <stdio.h>
int main(void)
{
    int a;
    /* Ingreso de datos */
    printf("Ingrese un numero:\r\n");
    scanf("%d", &a);
    //-- Verifico si es mayor o igual a seis --
    if (a >= 6)
    {
        printf("El numero ingresado es mayor o igual a 6\r\n");
    }
    else
    {
        printf("El numero ingresado es menor a 6\r\n");
    }
    return (0);
}
