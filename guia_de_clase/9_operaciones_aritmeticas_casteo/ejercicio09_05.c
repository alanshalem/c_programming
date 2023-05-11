// 5. Realice un programa que calcule e imprima la coseno de un ángulo expresado en grados ingresado
// por teclado.
// ~$ ./ejercicio09_05.out
// Ingrese número: 45
// El coseno de 45 es 0.707

#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main()
{
    double angulo, coseno;

    printf("Ingrese ángulo en grados: ");
    scanf("%lf", &angulo);

    // Convertir de grados a radianes
    angulo = angulo * M_PI / 180.0;

    // Calcular el coseno del ángulo en radianes
    coseno = cos(angulo);

    printf("El coseno de %lf es %lf\n", angulo * 180.0 / M_PI, coseno);

    return 0;
}
