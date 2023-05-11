// Informatica 1 - Guia de Clase - pag 44
// 5. Repita el programa anterior utilizando los siguientes tipos de datos.
// a. char (para este tipo de dato el usuario ingresará una letra)
// b. float

#include <stdio.h>

int main(void)
{
    float varFloat;
    char varChar;
    printf("Ingrese número: \r\n");
    scanf("%f", &varFloat);
    printf("Ingrese letra: \r\n");
    // The issue you are experiencing is related to the behavior of scanf() function in C when reading input from the standard input stream (stdin).
    // When you use the %f format specifier to read a float value from stdin, the function reads the float value but leaves the newline character (\n) in the input buffer.
    // When you subsequently call scanf() to read the character value using the %c format specifier, the function reads the newline character from the buffer instead of waiting for your input.
    // To fix this issue, you can add a space before the %c format specifier in the second call to scanf().
    // This space character will consume any remaining whitespace characters, including the newline character, in the input buffer before reading the character value. Here's the modified code:

    // flush input buffer to avoid issues with scanf() later
    // while(getchar() != '\n');
    // scanf("%c", &varChar);
    scanf(" %c", &varChar);
    printf("El número ingresado es: %f\r\n", varFloat);
    printf("La letra ingresada es: %c\r\n", varChar);

    return 0;
}
