#include <stdlib.h>

int main(void)
{
    int *ptr;  /* puntero a enteros */
    int *ptr2; /* otro puntero */

    /* reserva hueco para 300 enteros */
    ptr = (int *)malloc(300 * sizeof(int));
    ptr[33] = 15; /* trabaja con el área de memoria */

    rellena_de_ceros(10, ptr); /* otro ejemplo */

    ptr2 = ptr + 15; /* asignación a otro puntero */

    /* finalmente, libera la zona de memoria */
    free(ptr);
}
