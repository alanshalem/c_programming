/*
5. Implemente una función que le pase como parámetro dos números que representan los catetos de
un triángulo rectángulo y me devuelva la hipotenusa. El prototipo es
float calcHipo (float catetoA, float catetoB)
*/

#include <stdio.h>
#include <math.h>

float calcHipo(float catetoA, float catetoB);

int main()
{
    float a, b, hipo;
    printf("Ingrese los valores de los catetos: ");
    scanf("%f %f", &a, &b);
    hipo = calcHipo(a, b);
    printf("La hipotenusa es: %.2f\n", hipo);
    return 0;
}

float calcHipo(float catetoA, float catetoB)
{
    float hipotenusa;
    hipotenusa = sqrt(catetoA * catetoA + catetoB * catetoB);
    return hipotenusa;
}
