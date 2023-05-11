/*3. Implemente una función con el siguiente prototipo que almacene los datos de una lista simple
enlazada en un archivo formado por estructuras como la siguiente.
#define NOMBRE_SIZE (32)
struct dato_S {
char nombre[NOMBRE_SIZE];
int edad;
};
El prototipo de la función es:
int leerArchivo (struct nodo_S *h, char *nombreArchivo)
Donde:
● h: Es el puntero a la cabeza de la lista.
● nombreArchivo: Nombre del archivo destino
La función retorna un número negativo indicando error o la cantidad de nodos de la lista que se
pudieron escribir en el archivo.
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

struct dato_S
{
    char nombre[NOMBRE_SIZE];
    int edad;
};

int guardarLista(struct nodo_S *h, char *nombreArchivo);

int main()
{
    struct nodo_S *head = NULL;
    char *nombreArchivo = "personas.dat";

    // Agregar algunos nodos a la lista
    struct nodo_S *nodo1 = malloc(sizeof(struct nodo_S));
    strncpy(nodo1->nombre, "Juan", NOMBRE_SIZE);
    nodo1->edad = 25;
    nodo1->sig = NULL;
    head = nodo1;

    struct nodo_S *nodo2 = malloc(sizeof(struct nodo_S));
    strncpy(nodo2->nombre, "Maria", NOMBRE_SIZE);
    nodo2->edad = 30;
    nodo2->sig = NULL;
    nodo1->sig = nodo2;

    struct nodo_S *nodo3 = malloc(sizeof(struct nodo_S));
    strncpy(nodo3->nombre, "Pedro", NOMBRE_SIZE);
    nodo3->edad = 27;
    nodo3->sig = NULL;
    nodo2->sig = nodo3;

    // Guardar la lista en un archivo
    int num_nodos = guardarLista(head, nombreArchivo);

    if (num_nodos < 0)
    {
        printf("Error al guardar la lista en el archivo\n");
        return 1;
    }

    printf("Se guardaron %d nodos en el archivo\n", num_nodos);

    // Liberar la memoria de la lista
    struct nodo_S *actual = head;
    while (actual != NULL)
    {
        struct nodo_S *temp = actual;
        actual = actual->sig;
        free(temp);
    }

    return 0;
}

int guardarLista(struct nodo_S *h, char *nombreArchivo)
{
    // Abrir el archivo de salida
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        return -1;
    }

    // Recorrer la lista y escribir cada nodo en el archivo
    int num_nodos = 0;
    struct nodo_S *actual = h;
    while (actual != NULL)
    {
        struct dato_S dato;
        strncpy(dato.nombre, actual->nombre, NOMBRE_SIZE);
        dato.edad = actual->edad;
        fwrite(&dato, sizeof(struct dato_S), 1, archivo);
        num_nodos++;
        actual = actual->sig;
    }

    // Cerrar el archivo y retornar el número de nodos escritos
    fclose(archivo);
    return num_nodos;
}
