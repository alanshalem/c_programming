// 4. Programa que le solicita al usuario dos números y nos indica cual es mayor o si son iguales
#include <stdio.h>
int main(void)
{
    int a, b;
    /* Ingreso de datos */
    printf("Ingrese un numero:\r\n");
    scanf("%d", &a);
    printf("Ingrese un numero:\r\n");
    scanf("%d", &b);
    //-- Compara dos numeros ingresados --
    if (a == b)
    {
        printf("Son iguales\r\n");
    }
    else
    {
        if (a > b)
        {
            printf("El primero es mayor que el segundo\r\n");
        }
        else
        {
            printf("El segundo es mayor que el primero\r\n");
        }
    }
    return (0);
}
