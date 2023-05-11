/*
11. Implemente una función que convierta en binario un número entero positivo pasado como parámetro.
El prototipo de la función es
char* imprimirBinario (int n);
Donde:
n número a imprimir en binario.
Devuelve NULL si el número es menor que cero, en caso contrario devuelve el puntero a un string con
el número binario.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *imprimirBinario(int n)
{
    if (n < 0)
    {
        return NULL;
    }

    char *binario = (char *)malloc(33 * sizeof(char)); // Reservamos espacio para 32 bits y el caracter nulo '\0'
    if (binario == NULL)
    {
        return NULL;
    }

    int i = 31; // Empezamos a llenar el string desde la posición 31 (más significativa)
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            binario[i] = '0';
        }
        else
        {
            binario[i] = '1';
        }
        n /= 2;
        i--;
    }

    // Si el número no llenó todos los bits, completamos con ceros a la izquierda
    while (i >= 0)
    {
        binario[i] = '0';
        i--;
    }

    // Terminamos el string con el caracter nulo '\0'
    binario[32] = '\0';

    return binario;
}

int main()
{
    int n;
    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &n);

    char *binario = imprimirBinario(n);
    if (binario == NULL)
    {
        printf("El numero ingresado es negativo. No se puede convertir a binario.\n");
    }
    else
    {
        printf("El numero en binario es: %s\n", binario);
        free(binario); // Liberamos la memoria reservada
    }

    return 0;
}
