/* 7. Programa que indica la cantidad de caracteres de un string ingresado por teclado.*/
#include <stdio.h>

int main(void)
{
    char str[100];
    int i, count = 0;

    printf("Ingrese un string: ");
    fgets(str, sizeof(str), stdin); // lee una línea de texto desde la entrada estándar (stdin) y la guarda en str

    // La condición de salida del bucle es cuando se encuentra el carácter nulo '\0', que indica el final de la cadena.
    for (i = 0; str[i] != '\0'; i++)
    {
        count++; // incrementa el contador de caracteres
    }

    printf("El string ingresado tiene %d caracteres.\n", count);

    return 0;
}

// SOLUCION: Utilizando string.h
/*
#include <stdio.h>
#include <string.h>

#define MAX_STR_LENGTH 100

int main() {
    char str[MAX_STR_LENGTH];
    int length;

    printf("Ingrese un string: ");
    // La función fgets() lee una línea completa de texto hasta que encuentra el carácter de nueva línea ('\n')
    // o hasta que se alcanza el tamaño máximo especificado en el segundo argumento.
    fgets(str, MAX_STR_LENGTH, stdin);

    // Elimina el caracter de salto de línea final de fgets()
    // Se utiliza la función strlen() para obtener la longitud del string, y se almacena en la variable length.
    if(str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }

    length = strlen(str);
    printf("La longitud del string ingresado es: %d\n", length);

    return 0;
}
*/