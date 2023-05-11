// 2. Implemente un programa que permita el ingreso de un número real (float) e imprima por separado la parte entera y la decimal

#include <stdio.h>

int main(void)
{
    float numero, parte_entera, parte_decimal;

    printf("Ingrese numero: ");
    scanf("%f", &numero);

    parte_entera = (int)numero;                   // convertir a int para obtener la parte entera
    parte_decimal = numero - (float)parte_entera; // restar la parte entera para obtener la parte decimal

    printf("La parte entera es: %.0f\r\n", parte_entera);   // usar %.0f para mostrar solo la parte entera
    printf("La parte decimal es: %.2f\r\n", parte_decimal); // usar %.2f para mostrar dos decimales de la parte decimal

    return 0;
}
