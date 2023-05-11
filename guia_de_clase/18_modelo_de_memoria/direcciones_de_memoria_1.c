/*
Direcciones de memoria
La memoria es el lugar donde se almacenan variables y el programa, suele organizarse en bytes y a cada
uno de estos se le asigna un número que lo identifica llamado dirección. Estas direcciones se escriben en
hexadecimal ya que facilita su lectura. En el siguiente diagrama se muestra 4 posiciones de memoria de 1
byte que almacenan los números 0, 1, 2, 3 y a su izquierda las direcciones de cada uno de ellos
                    1 Byte
0x7ffebdeb2f60      0
0x7ffebdeb2f61      1
0x7ffebdeb2f62      2
0x7ffebdeb2f63      3
En el código nunca colocamos posiciones de memoria fijas (salvo por el NULL) ya que cada vez que
ejecutamos el código nuevamente el sistema operativo nos asignará una zona de memoria distinta. Las
variables son la abstracción que usamos para referirnos a las zonas de memoria.
Para que sea más fácil ver los ejemplo vamos a simplificar los números de las direcciones y arriba vamos
a indicar el ancho en bytes de la memoria, los siguientes ejemplo colocamos 4 bytes para que coincida
con el tamaño de una variable int y sea más fácil de leer. Además no vamos a tener en cuenta el byte
order de los datos almacenados en memoria.
A continuación se muestra un pequeño código y se indica en verde la línea donde se detuvo la ejecución
(la linea en verde no fue ejecutada al momento de imprimir el mapa de memoria) a la derecha se observa
un mapa de memoria con las dos variables que intervienen en el código.

*/

#include <stdio.h>
int main(void)
{
    int num = 0, res = 0;
    printf("Ingrese numero\r\n");
    scanf("%d", &num);
    res = num + 1;
    printf("res = %d\r\n", num);
    return (0);
}

/*
            4 Bytes
0x7F00      0x00000000  num
0x7F04      0x00000000  res
*/