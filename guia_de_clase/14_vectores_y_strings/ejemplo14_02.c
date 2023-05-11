/*
2. Programa en el cual se define un vector de diez números enteros y se inicializa en tiempo de
compilación con la tabla de multiplicar del 5. Pida al usuario que ingrese un número entre cero y
nueve, para luego calcular la multiplicación por cinco de dicho número indexando el vector.
*/
#include <stdio.h>
#define CANT ((int)10)
int main(void)
{
    int m5[CANT] = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45};
    int num;
    //-- Ingreso numero --
    printf("Ingrese numero\r\n");
    scanf("%d", &num);

    if ((num >= 0) && (num <= 9))
    {
        printf("El resultado es: %d\r\n", m5[num]);
    }
    else
    {
        printf("Imposible calcular\r\n");
    }
    return (0);
}
