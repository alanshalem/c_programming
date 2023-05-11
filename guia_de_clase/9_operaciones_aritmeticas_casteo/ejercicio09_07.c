/* 7. Implemente un programa que solicite un número y calcule el logaritmo en base 2 del mismo.
~$ ./ejercicio09_07.out
Ingrese número: 64
El logaritmo en base 2 de 64 es 6 */

#include <stdio.h>
#include <math.h>

int main() {
    double numero, logaritmo;
    
    printf("Ingrese un número: ");
    scanf("%lf", &numero);
    
    // Calcular el logaritmo en base 2 utilizando la fórmula
    logaritmo = log(numero) / log(2.0);
    
    printf("El logaritmo en base 2 de %.2lf es %.2lf\n", numero, logaritmo);
    
    return 0;
}

