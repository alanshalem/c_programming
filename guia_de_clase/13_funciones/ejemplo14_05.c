/* 5. Función que devuelve la suma de dos números enteros pasados como parámetros
Advertencia:
Recuerde definir la función o colocar el prototipo antes de la llamada a la función. */

#include <stdio.h>
int sumaDosNumeros(int a, int b)
{
    int r;
    r = a + b;
    return (r);
}
int main(void)
{
    int x, y, r;
    printf("Ingrese numero\r\n");
    scanf("%d", &x);
    printf("Ingrese numero\r\n");
    scanf("%d", &y);
    r = sumaDosNumeros(x, y);
    printf("Resultado = %d\r\n", r);
    return (0);
}