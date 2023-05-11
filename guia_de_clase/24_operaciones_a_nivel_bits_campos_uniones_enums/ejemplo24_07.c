/*7. Programa que demuestra uso de un enum*/
#include <stdio.h>
enum dias_E
{
    DOMINGO = 0,
    LUNES,
    MARTES,
    MIERCOLES,
    JUEVES,
    VIERNES,
    SABADO,
};
int main(void)
{
    int dia;
    printf("Ingrese numero indicando el dia de la semana (0 - 6)\r\n");
    scanf("%d", &dia);
    switch (dia)
    {
    case 0:
        printf("Domingo\r\n");
        break;
    case 1:
        printf("Lunes\r\n");
        break;
    case 2:
        printf("Martes\r\n");
        break;
    case 3:
        printf("Miercoles\r\n");
        break;
    case 4:
        printf("Jueves\r\n");
        break;
    case 5:
        printf("Viernes\r\n");
        break;
    case 6:
        printf("Sabado\r\n");
        break;
    default:
        printf("Ingreso invalido\r\n");
        break;
    }
    return (0);
}
