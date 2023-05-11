/*
2. Implemente una función que calcule el perímetro de un círculo. Utilice la constante de pi de
math.h. El prototipo es
float perimetroCirculo (float radio);
*/
#include <stdio.h>
#include <math.h>

float perimetroCirculo(float radio);

int main()
{
    float radio, perimetro;
    printf("Ingrese el radio del circulo: ");
    scanf("%f", &radio);

    perimetro = perimetroCirculo(radio);
    printf("El perimetro del circulo es: %.2f\n", perimetro);
    return 0;
}

float perimetroCirculo(float radio)
{
    float perimetro = 2 * M_PI * radio;
    return perimetro;
}
