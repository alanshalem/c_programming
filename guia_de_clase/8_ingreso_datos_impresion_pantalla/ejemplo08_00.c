// Informatica 1 - Guia de Clase - pag 42
// 1. Programa que imprime en pantalla una leyenda solicitando un número entero y después lo imprime

#include <stdio.h>

int main(void)
{
    int var; //-- Declaracion de variable entera --
    /* Imprimo en pantalla una leyenda */
    printf("Ingrese un numero:\r\n");
    /* Espero al que el usuario ingrese un numero entero */
    scanf("%d", &var);
    //-- Imprimo una leyenda y el valor almacenado en la variable --
    printf("El numero ingresado es: %d\r\n", var);
    //-- Imprimo el número en hexa --
    printf("El numero ingresado es(en hexa): %x\r\n", var);
    return (0);
}
