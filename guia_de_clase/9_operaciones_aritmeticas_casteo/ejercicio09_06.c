// 6. Realice un programa que calcule la hipotenusa de un triagulo rectangulo cuyos valores de sus catetos
// son ingresados por teclado.
// ~$ ./ejercicio09_06.out
// Ingrese número: 1
// Ingrese número: 1
// La hipotenusa es 1.4142

#include <stdio.h>
#include <math.h>

int main()
{
    double cateto1, cateto2, hipotenusa;

    printf("Ingrese el valor del primer cateto: ");
    scanf("%lf", &cateto1);

    printf("Ingrese el valor del segundo cateto: ");
    scanf("%lf", &cateto2);

    // Calcular la hipotenusa utilizando la fórmula del teorema de Pitágoras
    hipotenusa = sqrt(cateto1 * cateto1 + cateto2 * cateto2);

    printf("La hipotenusa es %lf\n", hipotenusa);

    return 0;
}
