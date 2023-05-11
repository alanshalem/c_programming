/*2. Programa que define un vector de 10 elementos de tipo char, luego lo inicializa con los números del
‘0’ al ‘9’ utilizando un puntero. Finalmente imprime dicho vector usando un puntero.*/
#include <stdio.h>
#define CANT ((int)10)
int main(void)
{
    char c[CANT];
    char *p;
    p = &c[0]; //-- Inicializo el puntero --
    //-- Inicializo el vector usando el puntero --
    for (int i = 0; i < CANT; i++)
    {
        *(p + i) = '0' + i;
    }
    //-- Imprimo el vector usando el puntero --
    for (int i = 0; i < CANT; i++)
    {
        printf("%d\r\n", *(p + i));
    }
    return (0);
}
