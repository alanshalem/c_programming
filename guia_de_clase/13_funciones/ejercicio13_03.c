/*
3. Implemente una función a la cual le pase un carácter como parámetro y me devuelva
○ 0: si el carácter es una letra mayúscula.
○ 1: si el carácter es una letra minúscula.
○ 2: si el carácter es un número.
○ 3: en caso que no sea ninguno de los anteriores.
Utilice define para las constantes. El prototipo es int filtroASCII (char caracter);
 */

#include <stdio.h>

#define MAYUSCULA 0
#define MINUSCULA 1
#define NUMERO 2
#define OTRO 3

int filtroASCII(char caracter);

int main()
{
    char caracter;
    printf("Ingrese un caracter: ");
    scanf("%c", &caracter);
    int resultado = filtroASCII(caracter);
    printf("El caracter ingresado es ");
    switch (resultado)
    {
    case MAYUSCULA:
        printf("una letra mayuscula.\n");
        break;
    case MINUSCULA:
        printf("una letra minuscula.\n");
        break;
    case NUMERO:
        printf("un numero.\n");
        break;
    case OTRO:
        printf("otro tipo de caracter.\n");
        break;
    }
    return 0;
}

int filtroASCII(char caracter)
{
    if (caracter >= 'A' && caracter <= 'Z')
    {
        return MAYUSCULA;
    }
    else if (caracter >= 'a' && caracter <= 'z')
    {
        return MINUSCULA;
    }
    else if (caracter >= '0' && caracter <= '9')
    {
        return NUMERO;
    }
    else
    {
        return OTRO;
    }
}
