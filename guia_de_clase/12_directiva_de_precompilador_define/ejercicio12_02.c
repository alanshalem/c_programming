/*
Implemente un programa que calcule el factorial de un número entero positivo ingresado por teclado.
El factorial de n es el producto de todos los enteros positivos hasta n inclusive.
- Para n > 0 => n! = 1 x 2 x 3 x … x n
- Para n = 0 => n! = 1

Se deben verificar todas las condiciones necesarias para asegurar que el resultado obtenido sea correcto. Además, se debe determinar el número máximo para el cual se puede calcular el factorial.

Verifique el funcionamiento del programa con los siguientes valores:
x   x! (salida de Stdout)
-1  No puedo calcular el factorial de un número negativo
0   1
1   1
2   2
3   6
12  479001600
*/

#include <stdio.h>

int main()
{
    int numero, i, factorial = 1;

    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    if (numero < 0)
    { // comprobamos si el numero ingresado es negativo
        printf("No puedo calcular el factorial de un numero negativo\n");
        return 0;
    }
    else if (numero == 0)
    { // si el numero es 0, el factorial es 1
        printf("El factorial de 0 es 1\n");
        return 0;
    }
    else
    { // para cualquier otro caso, calculamos el factorial
        for (i = 1; i <= numero; i++)
        {
            factorial *= i;
        }
        printf("El factorial de %d es %d\n", numero, factorial);
    }

    return 0;
}
