// 2. Implemente un programa que le pida al usuario dos números enteros e imprima todos los números
// enteros entre ellos, incluyendo los límites. Si los dos números son iguales deberá imprimir ese
// número solamente. Ejemplos:
// ● El usuario ingresa -1 y 2. El programa debe imprimir: -1; 0; 1; 2
// ● El usuario ingresa 2 y -1. El programa debe imprimir: 2; 1; 0; -1
// ● El usuario ingresa 2 y 2. El programa debe imprimir: 2

#include <stdio.h>

int main(void)
{
    int num1, num2, i;

    printf("Ingrese el primer numero: \r\n");
    scanf("%d", &num1);
    printf("Ingrese el segundo numero: \r\n");
    scanf("%d", &num2);

    if (num1 == num2)
    {
        printf("%d\n", num1);
    }
    else if (num1 < num2)
    {
        for (i = num1; i <= num2; i++)
        {
            printf("%d\n", i);
        }
    }
    else
    {
        for (i = num1; i >= num2; i--)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}