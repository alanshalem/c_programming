/*
3. Implemente una función que me indique si el string ingresado contiene solo letras o solo números. El
prototipo de la función es el siguiente:
int validaString (char *dataPtr);
Devuelve
● 1 si el string contiene solo letras .
● 2 si el string contiene sólo números.
● 0 Si no es ninguna de las anteriores
*/

#include <stdio.h>
#include <ctype.h>

int validaString(char *dataPtr)
{
    int letras = 0;
    int numeros = 0;

    while (*dataPtr)
    {
        if (isdigit(*dataPtr))
        {
            numeros++;
        }
        else if (isalpha(*dataPtr))
        {
            letras++;
        }
        else
        {
            return 0;
        }
        dataPtr++;
    }

    if (letras > 0 && numeros == 0)
    {
        return 1; // Contiene solo letras
    }
    else if (letras == 0 && numeros > 0)
    {
        return 2; // Contiene solo números
    }
    else
    {
        return 0; // No es ninguna de las anteriores
    }
}

int main()
{
    char data[] = "H0la";
    int resultado = validaString(data);
    printf("El resultado es %d\n", resultado);
    return 0;
}
