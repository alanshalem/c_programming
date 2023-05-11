/* 3. Función que devuelve el número pasado como parámetro sumandole 1.*/

#include <stdio.h>

#define CANT ((int)10)

int suma1(int a)
{
    int r;
    r = a + 1;
    return (r);
}

int main(void)
{
    int c, r;
    printf("Ingrese cantidad\r\n");
    scanf("%d", &c);
    r = suma1(c);
    printf("Resultado = %d\r\n", r);
    return (0);
}