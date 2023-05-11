// 1. Programa que le solicita al usuario un número y nos indique si vale cero
#include <stdio.h>

int main(void)
{
    int a;
    /* Ingreso de datos */
    printf("Ingrese un numero:\r\n");
    scanf("%d", &a);
    //-- Verifico si vale cero --
    if (a == 0)
    {
        printf("El usuario ingreso cero\r\n");
    }
    return (0);
}
