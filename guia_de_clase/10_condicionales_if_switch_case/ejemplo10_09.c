// 9. Programa que pide el ingreso de un número entero de 1 dígito e imprime con letras el valor.En caso
//    de que el dígito ingresado sea negativo o tenga más de un dígito escribe una leyenda indicándolo
#include <stdio.h>
int main(void)
{
    int a;
    /* Ingreso de datos */
    printf("Ingrese un numero:\r\n");
    scanf("%d", &a);
    //-- Verifico si es vocal --
    switch (a)
    {
    case 0:
        printf("cero\r\n");
        break;
    case 1:
        printf("uno\r\n");
        break;
    case 2:
        printf("dos\r\n");
        break;
    case 3:
        printf("tres\r\n");
        break;
    case 4:
        printf("cuatro\r\n");
        break;
    case 5:
        printf("cinco\r\n");
        break;
    case 6:
        printf("seis\r\n");
        break;
    case 7:
        printf("siete\r\n");
        break;
    case 8:
        printf("ocho\r\n");
        break;
    case 9:
        printf("nueve\r\n");
        break;
    default:
        printf("Ingreso invalido\r\n");
        break;
    }
    return (0);
}
