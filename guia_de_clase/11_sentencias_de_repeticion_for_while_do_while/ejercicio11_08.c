/* 8. Realice un programa que calcule el promedio de todas las notas ingresadas por teclado. Las notas
válidas están en el intervalo [1; 10] y el ingreso de datos terminará cuando el usuario coloque como
nota el valor -1 el cual no deberá tenerse en cuenta para el promedio. Si el usuario ingresa un número
fuera del rango deberá informar con una leyenda en pantalla y continuar el ingreso de datos. Además
deberá controlar que la cantidad de notas válidas ingresadas sea mayor que tres en caso contrario
deberá indicarle al usuario que continúe con el ingreso de datos. Finalmente muestre el promedio
con 2 decimales. Utilice do-while. */

#include <stdio.h>

int main()
{
    int nota, cantidad_notas = 0;
    float suma_notas = 0.0, promedio;

    do
    {
        printf("Ingrese una nota entre 1 y 10 (-1 para salir): ");
        scanf("%d", &nota);

        if (nota == -1)
        {
            break;
        }

        if (nota < 1 || nota > 10)
        {
            printf("Nota invalida. Debe ser entre 1 y 10.\n");
            continue;
        }

        cantidad_notas++;
        suma_notas += nota;
    } while (1);

    if (cantidad_notas < 3)
    {
        printf("Debe ingresar al menos tres notas validas.\n");
    }
    else
    {
        promedio = suma_notas / cantidad_notas;
        printf("El promedio de las notas ingresadas es: %.2f\n", promedio);
    }

    return 0;
}
