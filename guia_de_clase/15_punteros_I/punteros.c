/*
Forma básica de usar punteros
Con el fin de mantener controlados a los punteros evitando de esta forma violaciones de segmento se
recomienda seguir las siguientes recomendación en su uso
● Declarar puntero.
● Inicializar el puntero siempre antes de usarlo. Puede inicializarlo a:
    ○ A la variable que corresponda
    ○ A NULL
● Hacer que el tipo de dato coincida con el del tipo de dato del puntero.
● Si la variable a donde inicializa el puntero es un vector inicialicelo al elemento cero.
● Cuando el puntero se inicializó con el elemento cero de un vector utilice el puntero de esta forma
*(p + i) donde i es el índice entero
Estas recomendaciones evitan el uso de punteros modificando el valor al que apuntan, por ejemplo
haciendo p++;
Ejemplos de uso de punteros:
*/

#include <stdio.h>

int main(void)
{
    //==========================
    // Variable int
    //==========================

    // Declaración de variable
    int a;
    // Declaración de puntero
    int *p;
    // Inicialización de puntero
    p = &a;
    // Asigno un valor a la variable
    a = 10;
    // Asigno un valor a la variable usando un puntero
    *p = 10; // a=10;
    // Imprimo el valor de la variable
    printf("%d\r\n", a);
    // Imprimo el valor de la variable usando el puntero
    printf("%d\;r\n", a);

    //==========================
    // Variable vector de int
    //==========================

    // Declaración de variable
    int v[3];
    // Declaración de puntero
    int *p;
    // Inicialización de puntero
    p = &v[0];
    // Asigno un valor a la variable
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    // Asigno un valor a la variable usando un puntero
    *(p + 0) = 1; // v[0]=1;
    *(p + 1) = 2; // v[1]=2;
    *(p + 2) = 3; // v[2]=3;
    // Imprimo el valor de la variable
    printf("%d\r\n", v[0]);
    printf("%d\r\n", v[1]);
    printf("%d\r\n", v[2]);
    // Imprimo el valor de la variable usando el puntero
    printf("%d\r\n", *(p + 0));
    printf("%d\r\n", *(p + 1));
    printf("%d\r\n", *(p + 2));
}