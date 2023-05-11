/*
3. Se realiza una función que suma dos números enteros que son pasado como parámetro y retorna el
resultado usando el return de la función.
*/
#include <stdio.h>
int suma(int *a, int *b)
{
    int r;
    r = *a + *b;
    return (r);
}
int main(void)
{
    int x, y, r;
    //-- Ingreso de los dos numeros a sumar --
    printf("Ingrese numero\r\n");
    scanf("%d", &x);
    printf("Ingrese numero\r\n");
    scanf("%d", &y);
    r = suma(&x, &y);
    printf("El resultado %d\r\n", r);
    return (0);
}
