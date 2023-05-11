/* 7. Realice un programa que calcule el promedio de todas las notas ingresadas por teclado. Las notas
válidas están en el intervalo [1; 10] y el ingreso de datos terminará cuando el usuario coloque como
nota el valor -1 el cual no deberá tenerse en cuenta para el promedio. Si el usuario ingresa un número
fuera del rango deberá informar con una leyenda en pantalla y continuar el ingreso de datos.
Finalmente muestre el promedio con 2 decimales */

#include <stdio.h>

int main(void)
{
    int nota = 0, cantidadDeNotas = 0, sum = 0;

    do
    {
        printf("Ingresa una nota: \r\n");
        scanf("%d", &nota);
        if (nota >= 1 && nota <= 10)
        {
            sum += nota;
            cantidadDeNotas++;
        }
        else if (nota != -1)
        {
            printf("Nota invalida. Las notas deben estar entre 1 y 10.\n");
        }
    } while (nota != -1);

    if (cantidadDeNotas > 0)
    {
        float promedio = (float)sum / cantidadDeNotas;
        printf("El promedio de las notas ingresadas es: %.2f\n", promedio);
    }
    else
    {
        printf("No se ingresaron notas validas.\n");
    }

    return 0;
}