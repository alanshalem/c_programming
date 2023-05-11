/* 1. Implemente una función que cuente la cantidad de caracteres de un string sin contar el ‘\0’ El
prototipo de la función es int
    myStrLen(char *s);
Además implemente un main que verifique automáticamente el funcionamiento básico de la función
implementada*/
#include <stdio.h>
#include <stdlib.h>
int myStrLen(char *s)
{
    int c = 0;
    if (s != NULL)
    {
        while (*(s + c) != '\0')
        {
            c++;
        }
    }
    return (c);
}

int main(void)
{
    //-- Vectores de prueba --
    char v0[] = "Hola";
    char v1[] = "";
    char v2[] = "Hola como te va?";
    int r;
    //-- Prueba de las funciones --
    r = myStrLen(v0);
    printf("strlen > %s: %d\r\n", v0, r);
    r = myStrLen(v1);
    printf("strlen > %s: %d\r\n", v1, r);
    r = myStrLen(v2);
    printf("strlen > %s: %d\r\n", v2, r);
    r = myStrLen(NULL);
    printf("strlen > NULL: %d\r\n", r);
    return (0);
}
