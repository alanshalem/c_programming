/*
13. Implemente una función que busque dentro de un string todas las ocurrencias de una palabra pasada
como parámetro y las reemplace por otra palabra. El prototipo de la función es el siguiente:
int reemplazaPalabra (char *dataPtr, char *palabraBuscar,
char *palabraNueva);
Donde:
dataPtr: Es un puntero al string donde se realizan los reemplazos
palabraBuscar: Es un puntero a la palabra a buscar.
palabraNueva: Es un puntero a la palabra a reeemplazar
Devuelve
● un número positivo indicando la cantidad de palabras reemplazadas..
● -1 en caso de que palabraBuscar y palabraNueva tengan distinto tamaño.
● -2 en caso de que palabraBuscar y palabraNueva sean ‘\0’.
*/

#include <stdio.h>
#include <string.h>

int reemplazaPalabra(char *dataPtr, char *palabraBuscar, char *palabraNueva)
{
    int count = 0;
    size_t buscarLen = strlen(palabraBuscar);
    size_t nuevaLen = strlen(palabraNueva);

    if (buscarLen == 0 || nuevaLen == 0)
    {
        return -2;
    }
    if (buscarLen != nuevaLen)
    {
        return -1;
    }

    char *p = strstr(dataPtr, palabraBuscar);
    while (p != NULL)
    {
        strncpy(p, palabraNueva, nuevaLen);
        p += nuevaLen;
        p = strstr(p, palabraBuscar);
        count++;
    }
    return count;
}

int main()
{
    char data[] = "La casa es roja y la puerta es roja tambien";
    char buscar[] = "roja";
    char nueva[] = "azul";

    int reemplazos = reemplazaPalabra(data, buscar, nueva);

    if (reemplazos > 0)
    {
        printf("Se reemplazaron %d ocurrencias.\n", reemplazos);
        printf("Nuevo string: %s\n", data);
    }
    else if (reemplazos == -1)
    {
        printf("Error: las palabras tienen diferentes longitudes.\n");
    }
    else if (reemplazos == -2)
    {
        printf("Error: alguna palabra es una cadena vacia.\n");
    }
    else
    {
        printf("No se encontraron ocurrencias de la palabra buscada.\n");
    }

    return 0;
}
