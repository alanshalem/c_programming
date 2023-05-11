/*4. Función que convierta de mayusculas a minusculas la letra pasada como parametro char pasaAminusculas(char a)*/

#include <stdio.h>

#define CANT ((int)10)

char pasaAminusculas(char a)
{
    char r;
    if ((a >= 'A') && (a <= 'Z'))
    {
        r = (a - 'A') + 'a';
    }
    else
    {
        r = a;
    }
    return r;
}

int main(void)
{
    char c, r;

    printf("Ingrese letra\r\n");
    scanf("%c", &c);

    r = pasaAminusculas(c);

    printf("Resultado = %c\r\n", r);
    return 0;
}
