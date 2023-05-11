#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("El tipo de dato char ocupa %ld bytes y tiene un rango de %d a %d.\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("El tipo de dato int ocupa %ld bytes y tiene un rango de %d a %d.\n", sizeof(int), INT_MIN, INT_MAX);
    printf("El tipo de dato float ocupa %ld bytes y tiene un rango de %e a %e.\n", sizeof(float), FLT_MIN, FLT_MAX);
    printf("El tipo de dato double ocupa %ld bytes y tiene un rango de %e a %e.\n", sizeof(double), DBL_MIN, DBL_MAX);
    return 0;
}
