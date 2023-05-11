// 4. Programa que imprime le pide números al usuario sucesivamente hasta que este ingrese uno mayor
// que 10
#include <stdio.h>
int main(void)
{
    int a;
    do
    {
        printf("Ingrese un numero:\r\n");
        scanf("%d", &a);
    } while (a < 10);
    printf("El numero ingresado fue mayor que 10\r\n");
    return (0);
}
