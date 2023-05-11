/* 2. Función que imprime la leyenda "Hola Mundo", la cantidad de veces que se paso como parametro. */

#include <stdio.h>

void imprimir(int cant)
{
    int i;
    for (i = 0; i < cant; i++)
    {
        printf("Hola Mundo\r\n");
    }
}

int main(void)
{
    int c;
    printf("Ingrese cantidad\r\n");
    scanf("%d", &c);
    imprimir(c);
    return (0);
}
