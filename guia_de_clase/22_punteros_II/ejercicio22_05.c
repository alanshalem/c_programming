/*5. Implemente una función que lea de un archivo cuatro textos separados por "\r\n" y los coloque en
cuatro string generados dinámicamente. Luego asigne estos cuatro punteros al vector de punteros
pasado como parámetro en la función.
int leerTexto (char *nombre, char **textoPtr);
Donde:
nombre: Es el puntero al nombre del archivo
textoPtr: Es la cantidad de elementos del vector apuntado
Devuelve: La cantidad de líneas de texto leídas o un número negativo indicando el error.
*/

#include <stdio.h>
#include <stdlib.h>

int leerTexto(char *nombre, char **textoPtr)
{
    FILE *archivo = fopen(nombre, "r");
    if (archivo == NULL)
    {
        perror("Error al abrir archivo");
        return -1;
    }
    int numLineas = 0;
    char linea[256]; // asumimos que cada línea tiene como máximo 255 caracteres
    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        // eliminar el salto de línea al final de la línea leída
        linea[strcspn(linea, "\r\n")] = '\0';
        // asignar memoria para el texto
        textoPtr[numLineas] = malloc(strlen(linea) + 1);
        if (textoPtr[numLineas] == NULL)
        {
            perror("Error al asignar memoria");
            fclose(archivo);
            // liberar la memoria asignada para los textos anteriores
            for (int i = 0; i < numLineas; i++)
            {
                free(textoPtr[i]);
            }
            return -2;
        }
        // copiar el texto a la memoria asignada
        strcpy(textoPtr[numLineas], linea);
        numLineas++;
    }
    fclose(archivo);
    return numLineas;
}
