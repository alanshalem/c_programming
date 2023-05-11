// 3. Realice un programa que le pida al usuario el ingreso de dos números enteros, calcule la división e
// informe el cociente(entero) y el resto(use el operador %)
// ~$ ./ejercicio09_03.out
// Ingrese número: 101
// Ingrese número: 2
// El cociente es: 50
// El resto es: 1

#include <stdio.h>

int main()
{
    int num1, num2, cociente, resto;

    printf("Ingrese número: ");
    scanf("%d", &num1);
    printf("Ingrese número: ");
    scanf("%d", &num2);

    cociente = num1 / num2;
    resto = num1 % num2;

    printf("El cociente es: %d\n", cociente);
    printf("El resto es: %d\n", resto);

    return 0;
}