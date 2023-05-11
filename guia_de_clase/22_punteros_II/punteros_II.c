#include <stdio.h>

int main()
{
    int a;    // declaración de variable int
    int v[3]; // declaración de vector de int
    int *p;   // declaración de puntero int

    p = &a;    // inicialización de puntero
    p = &v[0]; // inicializacion de puntero a array

    a = 10; // asignación de valor a variable a

    v[0] = 1; // asignación de valor a primer elemento de vector v
    v[1] = 2; // asignación de valor a segundo elemento de vector v
    v[2] = 3; // asignación de valor a tercer elemento de vector v

    p = &a; // inicialización de puntero p con dirección de variable a

    printf("Valor de variable a: %d\n", a);                      // imprime valor de variable a
    printf("Valor de primer elemento de vector v: %d\n", v[0]);  // imprime valor de primer elemento de vector v
    printf("Valor de segundo elemento de vector v: %d\n", v[1]); // imprime valor de segundo elemento de vector v
    printf("Valor de tercer elemento de vector v: %d\n", v[2]);  // imprime valor de tercer elemento de vector v

    printf("Valor apuntado por puntero p: %d\n", *p);                               // imprime valor apuntado por puntero p
    printf("Valor de primer elemento de vector v usando puntero: %d\n", *(p + 0));  // imprime valor de primer elemento de vector v usando puntero
    printf("Valor de segundo elemento de vector v usando puntero: %d\n", *(p + 1)); // imprime valor de segundo elemento de vector v usando puntero
    printf("Valor de tercer elemento de vector v usando puntero: %d\n", *(p + 2));  // imprime valor de tercer elemento de vector v usando puntero

    return 0;
}
