// 3. Realice un programa que indique si la letra ingresada es mayúscula, minúscula, un número u otro
// carácter. Verifique el funcionamiento con los siguientes casos
// Valores de entrada          stdout (pantalla)
// desde ‘a’ hasta ‘z’         Es una letra minúscula.
// desde ‘A’ hasta ‘Z’         Es una letra mayúscula.
// desde ‘0’ hasta ‘9’         Es un número
// Otro carácter               Es otro carácter

#include <stdio.h>

int main()
{
    char ch;

    printf("Ingrese una letra o un carácter: ");
    scanf("%c", &ch);

    if (ch >= 'a' && ch <= 'z')
    {
        printf("Es una letra minúscula.\n");
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
        printf("Es una letra mayúscula.\n");
    }
    else if (ch >= '0' && ch <= '9')
    {
        printf("Es un número.\n");
    }
    else
    {
        printf("Es otro carácter.\n");
    }

    return 0;
}
