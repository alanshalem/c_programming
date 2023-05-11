/*
7. Implemente una función que determine si una palabra pasada como parámetro es palindromo
Prototipo de la función
int detectorPalindromo(char *palabraPtr)
Donde:
● palabraPtr: es el puntero a la palabra a analizar
Devuelve:
● 0 si la palabra es palindromo
● -1 si la palabra no es palindromo
● -2 si la palabra tiene menos de 2 caracteres
*/

#include <stdio.h>
#include <string.h>

int detectorPalindromo(char *palabraPtr)
{
    int longitud = strlen(palabraPtr);
    if (longitud < 2)
    {
        return -2; // palabra con menos de 2 caracteres
    }
    for (int i = 0; i < longitud / 2; i++)
    {
        if (palabraPtr[i] != palabraPtr[longitud - 1 - i])
        {
            return -1; // no es palindromo
        }
    }
    return 0; // es palindromo
}

int main()
{
    char palabra[] = "reconocer";
    int resultado = detectorPalindromo(palabra);
    if (resultado == 0)
    {
        printf("%s es palindromo\n", palabra);
    }
    else if (resultado == -1)
    {
        printf("%s no es palindromo\n", palabra);
    }
    else
    {
        printf("%s tiene menos de 2 caracteres\n", palabra);
    }
    return 0;
}
