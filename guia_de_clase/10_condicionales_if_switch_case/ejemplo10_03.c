// 3. Programa que le solicita al usuario un número y nos indica si es positivo, negativo o cero.
#include <stdio.h>
int main(void)
{
    int a;
    /* Ingreso de datos */
    printf("Ingrese un numero:\r\n");
    scanf("%d", &a);
    //-- Verifica si es cero, positivo o negativo --
    if (a == 0)
    {
        printf("El usuario ingreso cero\r\n");
    }
    else
    {
        if (a > 0)
        {
            printf("El usuario ingreso un numero positivo\r\n");
        }
        else
        {
            printf("El usuario ingreso un numero negativo\r\n");
        }
    }
    return (0);
}
