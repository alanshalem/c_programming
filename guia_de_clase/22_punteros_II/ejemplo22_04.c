/*4. Programa que genera dos vectores de punteros a char
○ El primero lo inicializa con la dirección de 3 string en tiempo de compilación.
○ El segundo lo inicializa con la dirección de 3 string en tiempo de ejecución.*/
#include <stdio.h>
int main(void)
{
    char *p[3];
    char *q[] = {
        "Hola",
        "Adios",
        "Info1"};
    char a[] = "Hola";
    char b[] = "Adios";
    char c[] = "Info1";
    p[0] = &a[0];
    p[1] = &b[0];
    p[2] = &c[0];
    printf("Imprimo los strings\r\n");
    printf("a = %s\tb = %s\tc = %s\r\n", a, b, c);
    printf("p[0] = %s\tp[1] = %s\tp[2] = %s\r\n", p[0], p[1], p[2]);
    printf("q[0] = %s\tq[1] = %s\tq[2] = %s\r\n", q[0], q[1], q[2]);
    printf("Imprimo las direcciones de los strings\r\n");
    printf("a = %p\tb = %p\tc = %p\r\n", &a[0], &b[0], &c[0]);
    printf("p[0] = %p\tp[1] = %p\tp[2] = %p\r\n", p[0], p[1], p[2]);
    printf("q[0] = %p\tq[1] = %p\tq[2] = %p\r\n", q[0], q[1], q[2]);
    return (0);
}
