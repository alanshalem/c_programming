/*1. Tome todas las funciones para operar sobre una lista simple enlazada y coloquelas en un archivo
llamado lsd.c y cree su archivo de cabecera correspondiente lse.h Luego cree un makefile que compile
lse.c como una librería estática. Finalmente agregue una regla en el makefile para compilar una función
main que demuestre el uso de las funciones de la lista simple enlazada linkeando la librería antes
creada.
*/

struct nodo_S *lseInsertarInicio(struct nodo_S *h, int data);
void lseImprimir(struct nodo_S *h);
struct nodo_S *lseLiberar(struct nodo_S *h);
int lseContar(struct nodo_S *h);
struct nodo_S *lseInsertarFinal(struct nodo_S *h, int data);
struct nodo_S *lseBuscar(struct nodo_S *h, int data);
struct nodo_S *lseRemover(struct nodo_S *h, int data);
struct nodo_S *lseInsertarOrdenado(struct nodo_S *h, int data);