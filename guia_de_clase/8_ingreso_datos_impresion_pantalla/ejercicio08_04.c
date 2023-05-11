// Informatica 1 - Guia de Clase - pag 44
// 4. Implemente un programa que utilizando la función scanf le solicite al usuario que ingrese un número entero. Luego imprima este número como se muestra a continuación
// ~$ ./ejercicio08_04.out
// Ingrese número: 33
// El número ingresado es: 33

#include <stdio.h>

int main(void)
{
    int varInt = 0;

    printf("Ingrese número: \r\n");
    scanf("%d", &varInt);
    printf("El número ingresado es: %d\r\n", varInt);

    return 0;
}
