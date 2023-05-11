/*6. Programa demuestra el uso de un punteros a función*/
#include <stdio.h>
int suma(int a, int b)
{
    return (a + b);
}
int main(void)
{
    int a, b, r;
    int (*func)(int, int);
    //-- Asignacion del puntero a funcion --
    func = suma;
    //-- Ingreso de datos --
    printf("Ingrese un numero:\r\n");
    scanf("%d", &a);
    printf("Ingrese un numero:\r\n");
    scanf("%d", &b);
    //-- Uso del puntero a funcion --
    r = func(a, b);
    printf("El resultado es: %d\r\n", r);
    return (0);
}
