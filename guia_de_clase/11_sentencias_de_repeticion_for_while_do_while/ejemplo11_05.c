// 5. Programa que acumula los números ingresados por teclado mientras esta acumulacion no supere el
// valor 100. Al superar el valor de 100 informa la suma total en pantalla.
#include <stdio.h>
int main(void)
{
    int a;
    int suma = 0;
    while (suma <= 100)
    {
        printf("Ingrese un numero:\r\n");
        scanf("%d", &a);
        suma += a;
    }
    printf("La suma es %d\r\n", suma);
    return (0);
}
