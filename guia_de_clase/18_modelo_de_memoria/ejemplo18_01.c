/*
Ámbito de uso de una variable. (scope de una variable)
El ámbito de uso (scope) de una variable es la zona o parte del programa donde es posible accederla.
1. Por ejemplo en el siguiente fragmento de código la variable
a. La variable suma y el parámetro param son solo accesibles dentro de la función funcSuma1
b. Las variables aux y res son solo accesibles dentro de la función main.
*/
#include <stdio.h>
int funcSuma1(int param)
{
    int suma;
    suma = param + 1;
    return (suma);
}
int main(void)
{
    int num, res;
    printf("Ingrese numero\r\n");
    scanf("%d", &num);
    res = funcSuma1(num);
    printf("Ingrese numero\r\n");
    return (0);
}

/*
Advertencia : Nunca devuelva la dirección de una variable local o parametro de una función
*/
int *funcMal(void)
{
    int MAL = 10;
    return (&MAL);
}