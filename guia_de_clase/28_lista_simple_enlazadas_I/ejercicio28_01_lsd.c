/*1. Tome todas las funciones para operar sobre una lista simple enlazada y coloquelas en un archivo
llamado lsd.c y cree su archivo de cabecera correspondiente lse.h Luego cree un makefile que compile
lse.c como una librería estática. Finalmente agregue una regla en el makefile para compilar una función
main que demuestre el uso de las funciones de la lista simple enlazada linkeando la librería antes
creada.
*/
#include <stdio.h>
#include "ejercicio28_01_lse.h"

// nodo ejemplo
struct nodo_S
{
    int data;
    struct nodo_S *sig;
};

/*Insertar un nodo al inicio (pila)
Inserta un nuevo nodo al inicio de la lista simple enlazada, el primer parámetro de la función es un
puntero a la cabeza de la lista, en el caso de que la lista está vacía este puntero debe ser NULL. El
segundo parámetro es el dato a insertar en la lista. La función retorna un puntero a la cabeza de la lista.
*/
struct nodo_S *lseInsertarInicio(struct nodo_S *h, int data)
{
    struct nodo_S *p;
    // *err = 0;
    //-- Pido memoria --
    p = (struct nodo_S *)malloc(sizeof(struct nodo_S));
    if (p == NULL)
    {
        //-- No hay memoria --
        return (NULL);
    }
    else
    {
        //-- Relleno la estructura --
        p->data = data;
        //-- Pongo el nodo al principio --
        p->sig = h; //-- Si es el primer nodo de la lista h es NULL --
        //-- Apunto el puntero a la cabeza de la lista al nuevo nodo
        h = p;
        return (h);
    }
}

/*Imprime todos los nodos
Imprime los datos de la lista simple enlazada, incluyendo la dirección del nodo y la dirección del siguiente
nodo. El parámetro de la función es el puntero a la cabeza de la lista.
*/
void lseImprimir(struct nodo_S *h)
{
    struct nodo_S *p;
    int i = 0;
    //-- Voy recorriendo la lista e imprimiendo nodos --
    puts("");
    printf("Index\tData\t\tDirNodo\t\tDirNodoSig\r\n");
    for (p = h; p != NULL; p = p->sig)
    {
        printf("%02d\t%08d\t%p\t%p\r\n", i++, p->data, p, p->sig);
    }
    puts("");
}

/*Libera todos los nodos
Libera la memoria que fue asignada dinámicamente de todos los nodos de la lista. El parámetro de la
función es el puntero a la cabeza de la lista.*/
struct nodo_S *lseLiberar(struct nodo_S *h)
{
    struct nodo_S *p, *aux;
    if (h == NULL)
    {
        //-- Lista vacia --
        return (h);
    }
    else
    {
        //-- Voy recorriendo la lista y eliminando nodos --
        for (p = h; p != NULL;)
        {
            //** Debug **
            // printf ("%p\r\n", p);
            //** Debug **
            aux = p;    //-- Salvo el puntero al nodo a eliminar --
            p = p->sig; //-- Me muevo al siguiente nodo --
            free(aux);  //-- libero el nodo actual --
        }
        h = p; //-- Pongo el puntero a la cabeza de la lista en NULL --
    }
    return (h);
}

/*Cuenta la cantidad de nodos de la lista simple enlazada
El parámetro de la función es el puntero a la cabeza de la lista y la misma retorna la cantidad de nodos
que tiene la lista.
*/
int lseContar(struct nodo_S *h)
{
    struct nodo_S *p;
    int i;
    for (p = h, i = 0; p != NULL; p = p->sig, i++)
        ;
    return (i);
}

/*Inserta un nodo al final
Inserta un nuevo nodo al final de la lista simple enlazada, el primer parámetro de la función es un puntero
a la cabeza de la lista, en el caso de que la lista está vacía este puntero debe ser NULL. El segundo
parámetro es el dato a insertar en la lista. La función retorna un puntero a la cabeza de la lista.
*/
struct nodo_S *lseInsertarFinal(struct nodo_S *h, int data)
{
    struct nodo_S *p, *aux;
    //-- Pido memoria --
    p = (struct nodo_S *)malloc(sizeof(struct nodo_S));
    if (p == NULL)
    {
        //-- No hay memoria --
        return (NULL);
    }
    else
    {
        //-- Relleno la estructura --
        p->data = data;
        p->sig = NULL; //-- Como es el ultimo nodo apunto el sig a NULL
        //-- Me fijo donde insertarlo --
        if (h == NULL)
        {
            //-- La lista esta vacia --
            h = p;
        }
        else
        {
            //-- Busco el último nodo --
            for (aux = h; aux->sig != NULL; aux = aux->sig)
                ;
            //-- Inserto el nodo al final --
            aux->sig = p;
        }
        return (h);
    }
}

/*Busca un nodo
El primer parámetro de la función es un puntero a la cabeza de la lista donde se buscará el dato que se
encuentra en el segundo parámetro de la función. La función retorna un puntero al nodo que contiene el
dato buscado o NULL en caso de que no se encuentre el dato buscado*/
struct nodo_S *lseBuscar(struct nodo_S *h, int data)
{
    struct nodo_S *p;
    //-- Recorro la lista --
    for (p = h; p != NULL; p = p->sig)
    {
        if (p->data == data)
        {
            //-- Encontre el dato --
            return (p);
        }
    }
    //-- Si sali del for es que no encontre nada --
    return (NULL);
}

/*Remueve un nodo
El primer parámetro de la función es un puntero a la cabeza de la lista donde se buscará el dato que se
encuentra en el segundo parámetro de la función, para posteriormente eliminar el nodo. La función
retorna un puntero a la cabeza de la lista o NULL en caso de que la lista este vacia.*/
struct nodo_S *lseRemover(struct nodo_S *h, int data)
{
    struct nodo_S *p, *aux;
    //-- Me fijo si hay algo en la lista --
    if (h != NULL)
    {
        //-- Busco el nodo a eliminar --
        for (p = h, aux = NULL; p != NULL; aux = p, p = p->sig)
        {
            if (p->data == data)
            {
                //-- Encontre el dato --
                if (aux == NULL)
                {
                    //-- Es el primer nodo --
                    h = p->sig;
                }
                else
                {
                    aux->sig = p->sig;
                }
                free(p);
                return (h);
            }
        }
    }
    else
    {
        //-- Lista vacia --
        return (h);
    }
    return (h);
}

/*Inserta un nodo de forma ordenada
La función inserta el dato pasado como parámetro en una lista simple enlazada ordenada de forma
ascendente. Si la lista está creada previamente y está desordenada, esta función no la ordenara lo único
que hace es ir insertando nuevos nodos de forma ordenada.*/
struct nodo_S *lseInsertarOrdenado(struct nodo_S *h, int data)
{
    struct nodo_S *p, *q, *r;
    //-- Me fijo donde va --
    for (p = h, q = NULL; p != NULL && (data < p->data); q = p, p = p->sig)
        ;
    r = (struct nodo_S *)malloc(sizeof(struct nodo_S));
    if (r == NULL)
    {
        //-- No hay memoria --
        return (NULL);
    }
    else
    {
        //-- Relleno la estructura --
        r->data = data;
        r->sig = NULL;
        //-- Inserto el nodo donde va --
        if (q == NULL)
        {
            //-- Es el primer nodo de la lista --
            r->sig = h;
            h = r;
        }
        else
        {
            //-- Va antes del primer nodo --
            r->sig = p;
            q->sig = r;
        }
    }
    return (h);
}
