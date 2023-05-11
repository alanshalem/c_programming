/*4. Programa que muestra cómo generar 10 números pseudoaleatorios.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define CANT ((int)10)
int main(void)
{
    int i;
    /*
    Inicializo la semilla para la función rand() utilizando la función time(NULL) que devuelve el número de segundos transcurridos desde el 1 de enero de 1970.
    De esta forma, cada vez que se ejecute el programa, la secuencia de números pseudoaleatorios será diferente.
    */
    srand(time(NULL));
    for (i = 0; i < CANT; i++)
    {
        /*Se utiliza un ciclo for para generar 10 números pseudoaleatorios utilizando la función rand() */
        printf("%d\r\n", rand());
    }
    return (0);
}
