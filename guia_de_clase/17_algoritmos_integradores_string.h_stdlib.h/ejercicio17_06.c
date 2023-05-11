/*
6. Implemente una función que analice un párrafo de texto y devuelva la cantidad de caracteres y
palabras que contiene. El prototipo de la función es el siguiente:
int analizaString (char *dataPtr, int *palabrasCant,
int *caracteresCant);
Donde:
● dataPtr es el puntero al string a analizar
● palabrasCant es un puntero a una variable donde se almacenará la cantidad de palabras del
texto
● caracteresCant es un puntero a una variable donde se almacenará la cantidad de caracteres del
texto
Devuelve
● 0 si el string contiene solo letras y signos de puntuación.
● -1 en caso contrario.
Notas de implementación:
● Los caracteres a contar son todas las letras del alfabeto, números, signos de puntuación y
espacios.
● Una palabra se separa de otra por un espacio o signo de puntuación.
● No cuente espacios para obtener la cantidad de palabras, ya que el texto puede contener dos
espacios seguidos y esto dará un conteo incorrecto.
*/

#include <ctype.h> // Para las funciones de clasificación de caracteres (isalpha, isdigit, ispunct, isspace)

#include <stdio.h>

int analizaString(char *dataPtr, int *palabrasCant, int *caracteresCant)
{
    int palabras = 0;
    int caracteres = 0;
    int flagPalabra = 0; // Indica si estamos dentro de una palabra

    while (*dataPtr != '\0')
    {
        // Contar caracteres
        if (isalpha(*dataPtr) || isdigit(*dataPtr) || ispunct(*dataPtr))
        {
            caracteres++;
            flagPalabra = 1; // Si encontramos un caracter, estamos dentro de una palabra
        }
        // Contar palabras
        else if (isspace(*dataPtr) && flagPalabra)
        {
            palabras++;
            flagPalabra = 0; // Si encontramos un espacio y estábamos dentro de una palabra, salimos de la palabra
        }
        // Si encontramos algún otro carácter que no contamos, devolvemos -1
        else
        {
            return -1;
        }
        dataPtr++; // Avanzamos al siguiente carácter
    }

    // Si llegamos al final del string y estábamos dentro de una palabra, contamos esa palabra
    if (flagPalabra)
    {
        palabras++;
    }

    *palabrasCant = palabras;
    *caracteresCant = caracteres;
    return 0;
}

int main()
{
    char *texto = "Este es un texto de prueba, que contiene palabras y signos de puntuación.";
    int palabras, caracteres;
    int resultado = analizaString(texto, &palabras, &caracteres);

    if (resultado == 0)
    {
        printf("El texto contiene %d palabras y %d caracteres.\n", palabras, caracteres);
    }
    else
    {
        printf("El texto contiene caracteres no válidos.\n");
    }

    return 0;
}