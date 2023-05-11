/*10. Implemente un programa que le pida al usuario que ingrese un número entero y luego informe la
cantidad de dígitos del mismo. Utilice while.*/
#include <stdio.h>

int main()
{
    int num, cant_digitos = 0;

    printf("Ingrese un numero entero: ");
    scanf("%d", &num);

    while (num != 0)
    {
        num /= 10;
        cant_digitos++;
    }

    printf("El numero tiene %d digitos.\n", cant_digitos);

    return 0;
}
