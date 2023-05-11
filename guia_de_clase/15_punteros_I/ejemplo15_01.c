/*1. Programa en el que se instancia una variable tipo int y un puntero del mismo tipo. Se apunta el
puntero a esta variable y la inicializa usando el puntero con el valor 0x55. Luego imprime el valor
almacenado en la variable utilizando el puntero.*/

#include <stdio.h>
int main(void)
{
    int a;
    int *p;               //-- Declaro el puntero --
    p = &a;               //-- Inicializo el puntero --
    *p = 0x55;            //-- Inicializo la variable a usando el puntero --
    printf("%d\r\n", *p); //-- Imprimo usando el puntero --
    return (0);
}