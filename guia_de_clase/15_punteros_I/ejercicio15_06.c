/*
6. Implemente una función que imprima en hexadecimal todos los caracteres de un string. El prototipo
de la función es el siguiente.
int myHexa (char *dataPtr)
Donde:
dataPtr: Es el puntero al string a pasar a hexadecimal.
Devuelve la cantidad de caracteres sin contar el '\0'
*/

#include <stdio.h>

int myHexa(char *dataPtr)
{
    int count = 0;
    while (*dataPtr != '\0')
    {
        printf("%02x ", *dataPtr);
        dataPtr++;
        count++;
    }
    printf("\n");
    return count;
}

int main()
{
    char *str = "Hola mundo!";
    int count = myHexa(str);
    printf("El string tiene %d caracteres.\n", count);
    return 0;
}
