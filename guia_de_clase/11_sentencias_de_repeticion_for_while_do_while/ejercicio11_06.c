// 6. Implemente un programa que acumule los números ingresados por teclado mientras esta
// acumulacion no supere el valor 100. Informe este número en pantalla. Si el usuario ingresa: 10, 80, 20
// el programa debe imprimir: 90

#include <stdio.h>
int main(void)
{
    int num = 0, sum = 0;
    printf("Ingresa un numero: \r\n");
    do
    {
        scanf("%d", &num);
        sum += num;
    } while (sum < 100);
    printf("%d\r\n", sum);

    return 0;
}