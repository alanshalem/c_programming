/*
10. Implemente una función que convierta un número positivo hexadecimal de 4 dígitos almacenado en un
string y devuelva el correspondiente número decimal. Las letras del número hexadecimal están en
mayúscula.
El prototipo de la función es:
int hexaToDec (char *dataPtr);
Devuelve:
● El valor hexadecimal en decimal
● -1 Si hay un símbolo que no corresponda a un número hexadecimal.
● -2 Si la cantidad de dígitos es distinta a 4
Ejemplos
hexaToDec ("0001"); // Devuelve 1
hexaToDec ("CAFE"); // Devuelve 51966
hexaToDec ("JJJJ"); // Devuelve -1
hexaToDec ("1"); // Devuelve -2
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int hexaToDec(char *dataPtr)
{
    int i, len, value = 0, digit;
    len = strlen(dataPtr);
    if (len != 4)
    {
        return -2;
    }
    for (i = 0; i < len; i++)
    {
        if (!isxdigit(dataPtr[i]))
        {
            return -1;
        }
        if (isdigit(dataPtr[i]))
        {
            digit = dataPtr[i] - '0';
        }
        else
        {
            digit = toupper(dataPtr[i]) - 'A' + 10;
        }
        value += digit * pow(16, len - i - 1);
    }
    return value;
}

int main()
{
    char data[5];
    int result;
    printf("Ingrese un número hexadecimal de 4 dígitos: ");
    scanf("%s", data);
    result = hexaToDec(data);
    if (result == -1)
    {
        printf("El número ingresado no es válido.\n");
    }
    else if (result == -2)
    {
        printf("El número debe tener 4 dígitos.\n");
    }
    else
    {
        printf("El valor decimal correspondiente es: %d\n", result);
    }
    return 0;
}
