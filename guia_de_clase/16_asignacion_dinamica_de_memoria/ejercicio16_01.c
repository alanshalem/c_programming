/*
1. Implemente un programa que utilizando malloc reserve memoria para almacenar las letras
mayúsculas del alfabeto (salvo la Ñ). Luego imprima la zona reservada y la libere antes de finalizar el
programa.
*/

#include <stdio.h>
#include <stdlib.h>

#define CANT ((int)25)

int main(void)
{
    char *p;
    int cantTotal, i;
    // -- Pido memoria para CANT de elementos del ALFABETO
    cantTotal = CANT;
    p = (char *)malloc(sizeof(*p) * cantTotal);
    if (p == NULL)
    {
        return (-1);
    }
    //-- Inicializo la zona de memoria asignada con cero--
    for (int i = 0; i < cantTotal; i++)
    {
        *(p + i) = i + 65;
    }
    //-- Imprimo el vector utilizado, en este caso es todo --
    for (i = 0; i < cantTotal; i++)
    {
        printf("%c\r\n", *(p + i));
    }
    // -- Libero Memoria --
    free(p);
    return (0);
}