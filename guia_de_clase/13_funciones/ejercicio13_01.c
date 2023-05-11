/*
1. Implemente una función que calcule el área de un círculo. Utilice la constante de pi de math.h.
El prototipo es
float areaCirculo (float radio);
*/

#include <stdio.h>
#include <math.h>

float areaCirculo(float radio);

int main()
{
    float radio, area;
    printf("Ingrese el radio del circulo: ");
    scanf("%f", &radio);
    area = areaCirculo(radio);
    printf("El area del circulo es: %.2f\n", area);
    return 0;
}

float areaCirculo(float radio)
{
    float area = M_PI * radio * radio;
    return area;
}