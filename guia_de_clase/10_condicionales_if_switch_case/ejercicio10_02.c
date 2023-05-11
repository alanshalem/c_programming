// 2. Escriba un programa donde ingresa por teclado un par de valores enteros, que representan las
// coordenadas rectangulares de distintos puntos en el plano. Se pide determinar e informar por
// pantalla:
// -Si ambos valores son cero.
// -A cuál cuadrante pertenece el punto.
// -La distancia al origen de coordenadas. que se calcula como: r=sqrt(a^2+b^2)

#include <stdio.h>
#include <math.h>

int main()
{
    int x, y;

    printf("Ingrese la coordenada x: ");
    scanf("%d", &x);
    printf("Ingrese la coordenada y: ");
    scanf("%d", &y);

    if (x == 0 && y == 0)
    {
        printf("Ambos valores son cero.\n");
    }
    else
    {
        if (x > 0 && y > 0)
        {
            printf("El punto se encuentra en el primer cuadrante.\n");
        }
        else if (x < 0 && y > 0)
        {
            printf("El punto se encuentra en el segundo cuadrante.\n");
        }
        else if (x < 0 && y < 0)
        {
            printf("El punto se encuentra en el tercer cuadrante.\n");
        }
        else
        {
            printf("El punto se encuentra en el cuarto cuadrante.\n");
        }

        double distance = sqrt(x * x + y * y);
        printf("La distancia al origen de coordenadas es %.2f\n", distance);
    }

    return 0;
}
