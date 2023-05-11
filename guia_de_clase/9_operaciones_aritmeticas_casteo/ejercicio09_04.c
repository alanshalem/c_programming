// 4. Realice un programa que calcule e imprima (con 4 decimales) la raíz cuadrada de un número ingresado
// por teclado. ¿Qué ocurre si el número ingresado es negativo? Indique su respuesta en un comentario
// en el código.
// ~$ ./ejercicio09_04.out
// Ingrese número: 2
// La raiz cuadrada de 2 es 1.4142

#include <stdio.h>
#include <math.h>

int main()
{
    float num, raiz;

    printf("Ingrese número: ");
    scanf("%f", &num);

    if (num < 0)
    {
        printf("Error: no se puede calcular la raíz cuadrada de un número negativo.\n");
        return 1;
    }

    raiz = sqrt(num);

    printf("La raiz cuadrada de %.4f es %.4f\n", num, raiz);

    return 0;
}