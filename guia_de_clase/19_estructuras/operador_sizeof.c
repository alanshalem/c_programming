#include <stdio.h>

int main()
{
    int a;
    float b;
    char c;
    double d;
    long e;

    printf("El tamaño de un int es: %ld bytes\n", sizeof(a));
    printf("El tamaño de un float es: %ld bytes\n", sizeof(b));
    printf("El tamaño de un char es: %ld bytes\n", sizeof(c));
    printf("El tamaño de un double es: %ld bytes\n", sizeof(d));
    printf("El tamaño de un long es: %ld bytes\n", sizeof(e));

    int array[] = {1, 2, 3, 4, 5};
    printf("El tamaño de un array de 5 enteros es: %ld bytes\n", sizeof(array));
    printf("El tamaño de un entero es: %ld bytes\n", sizeof(array[0]));

    int matriz[4][5];
    int size_matriz = sizeof(matriz);
    printf("Tamaño de la matriz: %d bytes\n", size_matriz);

    char string[] = "Hola mundo!";
    printf("El tamaño de un string es: %ld bytes\n", sizeof(string));

    struct persona
    {
        char nombre[20];
        int edad;
        float altura;
    };

    struct persona p;
    int size_persona = sizeof(p);
    printf("Tamaño de la estructura persona: %d bytes\n", size_persona);

    int *puntero;
    int size_puntero = sizeof(puntero);
    printf("Tamaño del puntero: %d bytes\n", size_puntero);

    return 0;
}
