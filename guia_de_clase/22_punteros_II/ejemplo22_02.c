/*2. Programa que crea un vector de punteros y se lo pasa a una función como parámetro.*/
#include <stdio.h>
void func(int **p)
{
    *p[0] = 100;
    *p[1] = 200;
    *p[2] = 300;
}
int main(void)
{
    int *p[3];
    int a = 11, b = 22, c = 33;
    p[0] = &a;
    p[1] = &b;
    p[2] = &c;
    printf("Valores de las variables\r\n");
    printf("a = %d\tb = %d\tc = %d\r\n", a, b, c);
    printf("*p[0] = %d\t*p[1] = %d\t*p[2] = %d\r\n", *p[0], *p[1], *p[2]);
    printf("Direcciones\r\n");
    printf("&a = %p\t&b = %p\t&c = %p\r\n", &a, &b, &c);
    printf("p[0] = %p\tp[1] = %p\tp[2] = %p\r\n", p[0], p[1], p[2]);
    printf("Modifico los valores en la funcion\r\n");
    func(&p[0]);
    printf("a = %d\tb = %d\tc = %d\r\n", a, b, c);
    printf("*p[0] = %d\t*p[1] = %d\t*p[2] = %d\r\n", *p[0], *p[1], *p[2]);
    return (0);
}
