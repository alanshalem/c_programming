/*
2. Por ejemplo en el siguiente fragmento de código la variable
a. El parámetro param son solo accesibles dentro de la función funcSuma1
b. Las variables aux y res son solo accesibles dentro de la función main.
c. La variable suma es global y es accesible en todas las funciones del archivo .c en este
caso es accesible por funcSuma1 y por la función main
*/
#include <stdio.h>
int suma;
int funcSuma1(int param)
{
    suma = param + 1;
    return (suma);
}
int main(void)
{
    int num, res;
    printf("Ingrese numero\r\n");
    scanf("%d", &num);
    res = funcSuma1(num);
    printf("res = %d\r\n", res);
    printf("suma = %d\r\n", suma);
    return (0);
}
/*
Advertencia:
Evite en lo posible el uso de variables globales.
*/
