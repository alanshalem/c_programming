// 7. Programa que le solicita al usuario un carácter e indica si el mismo es una letra mayúscula

#include <stdio.h>
int main(void)
{
    char a;
    /* Ingreso de datos */
    printf("Ingrese un caracter:\r\n");
    scanf("%c", &a);
    //-- Verifico si es una letra mayúscula --
    if ((a >= 'A') && (a <= 'Z'))
    {
        printf("El caracter ingresado es una letra mayuscula\r\n");
    }
    return (0);
}

// Consulte el man del ascii para ver el orden de los caracteres en la tabla.