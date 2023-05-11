// 6. Programa que inicializa un string en tiempo de compilación y lo muestra en pantalla.//
#include <stdio.h>
#define CANT ((int)32)
#define CANT_VOCALES ((int)10)
int main(void)
{
    char str0[] = "Hola";
    char str1[] = {'h', 'o', 'l', 'a', '\0'};
    //-- Ingreso palabra --
    printf("Palabra %s\r\n", str0);
    printf("Palabra %s\r\n", str1);
    return (0);
}