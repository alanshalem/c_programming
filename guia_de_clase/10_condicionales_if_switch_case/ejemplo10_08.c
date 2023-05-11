// 8. Programa que le solicita al usuario un carácter e indica si el mismo es una vocal minúscula
#include <stdio.h>
int main(void)
{
    char a;
    /* Ingreso de datos */
    printf("Ingrese un caracter:\r\n");
    scanf("%c", &a);
    //-- Verifico si es vocal --
    switch (a)
    {
    case 'a':
        printf("Es vocal\r\n");
        break;
    case 'e':
        printf("Es vocal\r\n");
        break;
    case 'i':
        printf("Es vocal\r\n");
        break;
    case 'o':
        printf("Es vocal\r\n");
        break;
    case 'u':
        printf("Es vocal\r\n");
        break;
    default:
        printf("No es vocal\r\n");
        break;
    }
    return (0);
}