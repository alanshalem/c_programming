// 3. Implemente un programa utilizando la sentencia for que calcule el promedio de 10 números
// enteros ingresados por teclado.

#include <stdio.h>

int main()
{
    int num, sum = 0, i;
    float promedio;

    printf("Ingrese 10 numeros enteros:\n");

    for (i = 0; i < 10; i++)
    {
        scanf("%d", &num);
        sum += num;
    }

    promedio = (float)sum / 10;

    printf("El promedio es: %.2f\n", promedio);

    return 0;
}
