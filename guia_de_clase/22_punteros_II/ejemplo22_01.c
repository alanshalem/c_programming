/*1. Programa que crea un vector de 3 punteros a enteros, los apunta a tres enteros para luego operar
sobre las variables usando los punteros.*/
#include <stdio.h>
int main(void)
{
    int *p[3];
    int a = 11, b = 22, c = 33;
    p[0] = &a;
    p[1] = &b;
    p[2] = &c;
    //-- Accedo a las variables a,b y c utilizando el vector de punteros --
    printf("a = %d\tb = %d\tc = %d\r\n", a, b, c);
    printf("*p[0] = %d\t*p[1] = %d\t*p[2] = %d\r\n", *p[0], *p[1], *p[2]);
    //-- Muestro la direccion de las variables a, b y c y los punteros --
    printf("&a = %p\t&b = %p\t&c = %p\r\n", &a, &b, &c);
    printf("p[0] = %p\tp[1] = %p\tp[2] = %p\r\n", p[0], p[1], p[2]);
    //-- Modifico el valor de las variables a. b, c usando los punteros --
    *p[0] = 100;
    *p[1] = 200;
    *p[2] = 300;
    printf("a = %d\tb = %d\tc = %d\r\n", a, b, c);
    printf("*p[0] = %d\t*p[1] = %d\t*p[2] = %d\r\n", *p[0], *p[1], *p[2]);
    return (0);
}
