/*
8. Implemente una función que elimine de un string el carácter pasado como parámetro. Tenga en cuenta
que al eliminar caracteres deberá ajustar la posición del '\0' El prototipo de la función es el siguiente.
int eliminarCaracter (char *dataPtr, char c);
Donde:
dataPtr: Es el puntero al string a modificar.
c: Carácter a eliminar.
Devuelve:
● La cantidad de caracteres eliminados.
*/
#include <stdio.h>
#include <string.h>

int eliminarCaracter(char *dataPtr, char c)
{
    int i, j, eliminados = 0;
    for (i = 0, j = 0; dataPtr[i] != '\0'; i++)
    {
        if (dataPtr[i] != c)
        {
            dataPtr[j++] = dataPtr[i];
        }
        else
        {
            eliminados++;
        }
    }
    dataPtr[j] = '\0';
    return eliminados;
}

int main()
{
    char s[] = "hello world";
    int eliminados = eliminarCaracter(s, 'l');
    printf("Eliminados: %d\n", eliminados); // 3
    printf("Nuevo string: %s\n", s);        // "heo word"
    return 0;
}
