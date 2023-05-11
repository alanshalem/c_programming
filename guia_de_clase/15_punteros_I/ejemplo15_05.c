/* 5. Se realiza una función que devuelve un puntero al elemento central de un vector de enteros.
Finalmente se imprime el elemento central del vector usando el puntero obtenido con el
Advertencia:
No olvide inicializar el puntero antes de utilizarlo.
Advertencia:
Evite realizar operaciones de incremento o decremento sobre punteros, por ejemplo: p++ ó p--;*/

#include <stdio.h>
#define CANT ((int)3)

int *medio(int *dataPtr, int dataCant)
{
    int *p;
    p = dataPtr + (dataCant / 2);
    return (p);
}
int main(void)
{
    int v[CANT] = {1, 2, 3};
    int *q;
    q = medio(&v[0], CANT);
    //-- Imprimo el elemento central --
    printf("El elemento central vale %d\r\n", *q);
    return (0);
}
