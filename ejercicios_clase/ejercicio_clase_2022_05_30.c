/*
 Realizar una función que elimine de un string las ocurrencias de un carácter dado.
int delete_char(char *str, char buscado);

La función devuelve la cantidad de caracteres eliminados.


 Realizar una función que reemplace todas las ocurrencias de un carácter dado
dentro de un string por otro carácter.
int replace_char(char *str, char buscado, char reemplazo);

La función devuelve la cantidad de caracteres reemplazados. */

#include <stdio.h>
#include <string.h>

int delete_char(char *str, char buscado);
int replace_char(char *str, char buscado, char reemplazo);

int main()
{
    char str[100], buscado, reemplazo;
    int eliminados, reemplazados;

    printf("Ingrese una cadena: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0; // Elimina el salto de línea final de fgets

    printf("Ingrese un caracter a eliminar: ");
    scanf("%c", &buscado);

    printf("Ingrese un caracter para reemplazar: ");
    getchar(); // Consumir el salto de línea anterior
    scanf("%c", &reemplazo);

    eliminados = delete_char(str, buscado);
    reemplazados = replace_char(str, reemplazo, '_');

    printf("El string resultante es: %s\n", str);
    printf("Se eliminaron %d caracteres y se reemplazaron %d caracteres.\n", eliminados, reemplazados);

    return 0;
}

int delete_char(char *str, char buscado)
{
    int i, j, eliminados = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == buscado)
        {
            eliminados++;
        }
        else
        {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
    return eliminados;
}

int replace_char(char *str, char buscado, char reemplazo)
{
    int i, reemplazados = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == buscado)
        {
            str[i] = reemplazo;
            reemplazados++;
        }
    }
    return reemplazados;
}
