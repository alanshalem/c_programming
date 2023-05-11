/*3. Programa que genera dinámicamente un array de punteros a entero*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int **p;
    int a = 11, b = 22, c = 33;
    p = (int **)malloc(sizeof(*p) * 3);
    if (p == NULL)
    {
        printf("Error malloc \r\n");
        return (-1);
    }
    *(p + 0) = &a;
    *(p + 1) = &b;
    *(p + 2) = &c;
    printf("Valores de las variables\r\n");
    printf("a = %d\tb = %d\tc = %d\r\n", a, b, c);
    printf("*p[0] = %d\t*p[1] = %d\t*p[2] = %d\r\n", *p[0], *p[1], *p[2]);
    printf("Direcciones\r\n");
    printf("&a = %p\t&b = %p\t&c = %p\r\n", &a, &b, &c);
    printf("*p[0] = %p\t*p[1] = %p\t*p[2] = %p\r\n", p[0], p[1], p[2]);
    return (0);
}
