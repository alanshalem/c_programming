/*2. Implemente una función que lea un archivo de texto y lo inserte de forma ordenada por nombre en una
lista simple enlazada.
El formato del archivo es el siguiente:
Nombre,edad\r\n
Jose,33\r\n
El prototipo de la función es:
struct nodo_S * leerArchivo (struct nodo_S *h, char *nombreArchivo)
Donde:
● h: Es el puntero a la cabeza de la lista.
● nombreArchivo: Nombre del archivo origen.
La función retorna un número negativo indicando error o la cantidad de nodos de la lista que se
pudieron crear.
El nodo de la lista simple enlazada es:
#define NOMBRE_SIZE (32)
struct nodo_S {
    char nombre[NOMBRE_SIZE];
    int edad;
    struct nodo_S *sig;
};
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOMBRE_SIZE (32)

struct nodo_S
{
    char nombre[NOMBRE_SIZE];
    int edad;
    struct nodo_S *sig;
};

struct nodo_S *leerArchivo(struct nodo_S *h, char *nombreArchivo);

int main()
{
    struct nodo_S *head = NULL;
    char *nombreArchivo = "personas.txt";

    head = leerArchivo(head, nombreArchivo);

    if (head == NULL)
    {
        printf("Error al leer el archivo\n");
        return 1;
    }

    // Imprimir la lista
    printf("Lista ordenada por nombre:\n");
    struct nodo_S *actual = head;
    while (actual != NULL)
    {
        printf("%s, %d\n", actual->nombre, actual->edad);
        actual = actual->sig;
    }

    // Liberar la memoria de la lista
    actual = head;
    while (actual != NULL)
    {
        struct nodo_S *temp = actual;
        actual = actual->sig;
        free(temp);
    }

    return 0;
}

struct nodo_S *leerArchivo(struct nodo_S *h, char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL)
    {
        fprintf(stderr, "Error al abrir el archivo %s\n", nombreArchivo);
        return NULL;
    }

    char linea[100];
    char *token;

    while (fgets(linea, 100, archivo))
    {
        // Separar la línea en nombre y edad
        token = strtok(linea, ",");
        if (token == NULL)
        {
            fprintf(stderr, "Error en el formato del archivo\n");
            fclose(archivo);
            return NULL;
        }
        char nombre[NOMBRE_SIZE];
        strncpy(nombre, token, NOMBRE_SIZE);

        token = strtok(NULL, "\r\n");
        if (token == NULL)
        {
            fprintf(stderr, "Error en el formato del archivo\n");
            fclose(archivo);
            return NULL;
        }
        int edad = atoi(token);

        // Crear un nuevo nodo con el nombre y la edad
        struct nodo_S *nuevoNodo = malloc(sizeof(struct nodo_S));
        strncpy(nuevoNodo->nombre, nombre, NOMBRE_SIZE);
        nuevoNodo->edad = edad;

        // Agregar el nuevo nodo a la lista en orden alfabético
        struct nodo_S *anterior = NULL;
        struct nodo_S *actual = h;
        while (actual != NULL && strcmp(actual->nombre, nombre) < 0)
        {
            anterior = actual;
            actual = actual->sig;
        }

        if (anterior == NULL)
        {
            nuevoNodo->sig = h;
            h = nuevoNodo;
        }
        else
        {
            nuevoNodo->sig = anterior->sig;
            anterior->sig = nuevoNodo;
        }
    }

    fclose(archivo);
    return h;
}
