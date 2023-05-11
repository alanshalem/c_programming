/*
7. Implemente una función que se le pase como parámetro un puntero a un string e indique si este
contiene solo los dígitos del ‘0’ al ‘9’. El prototipo de la función es el siguiente.
int esNumero (char *dataPtr);
Donde:
dataPtr: Es el puntero al string
Devuelve: Cero si algún caracter del string no corresponde a un dígito del ‘0’ al ‘9’, devuelve uno
*/

#include <stdio.h>

int esNumero(char *dataPtr)
{
    while (*dataPtr != '\0')
    {
        if (*dataPtr < '0' || *dataPtr > '9')
        {
            return 0; // no es un número
        }
        dataPtr++;
    }
    return 1; // es un número
}

int main()
{
    char *str1 = "1234";
    char *str2 = "Hola123";
    int resultado1 = esNumero(str1);
    int resultado2 = esNumero(str2);
    printf("%s es un número: %d\n", str1, resultado1);
    printf("%s es un número: %d\n", str2, resultado2);
    return 0;
}
