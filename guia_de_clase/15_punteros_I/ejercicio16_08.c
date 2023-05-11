/*
8. Implemente una función que recibe un puntero a un string que contiene un número y devuelve ese
número en un int. El prototipo de la función es el siguiente.
int convertirA_Int(char *dataPtr)
Donde:
dataPtr: Es el puntero al string a pasar a convertir.
Devuelve: El número entero si pudo convertirlo, si el string contiene un carácter distinto a los dígitos
del ‘0’ al ‘9’ y menos uno en caso de error.
*/

#include <stdio.h>

int convertirA_Int(char *dataPtr)
{
    int num = 0;
    while (*dataPtr != '\0')
    {
        if (*dataPtr >= '0' && *dataPtr <= '9')
        {
            num = num * 10 + (*dataPtr - '0');
        }
        else
        {
            return -1; // error: no es un número
        }
        dataPtr++;
    }
    return num;
}

int main()
{
    char *str1 = "1234";
    char *str2 = "Hola123";
    int resultado1 = convertirA_Int(str1);
    int resultado2 = convertirA_Int(str2);
    printf("El número de %s es: %d\n", str1, resultado1);
    printf("El número de %s es: %d\n", str2, resultado2);
    return 0;
}
