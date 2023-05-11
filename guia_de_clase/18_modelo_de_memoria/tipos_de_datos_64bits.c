#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("Tipo de dato\tDescripción\tCantidad de bytes\tRango\n");

    printf("char\t\tCarácter\t%d\t\t%d a %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("unsigned char\tCarácter\t%d\t\t0 a %d\n", sizeof(unsigned char), UCHAR_MAX);
    printf("short\t\tNúmero entero\t%d\t\t%d a %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("unsigned short\tNúmero entero\t%d\t\t0 a %d\n", sizeof(unsigned short), USHRT_MAX);
    printf("int\t\tNúmero entero\t%d\t\t%d a %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("unsigned int\tNúmero entero\t%d\t\t0 a %u\n", sizeof(unsigned int), UINT_MAX);
    printf("float\t\tNúmero real\t%d\t\t%e a %e\n", sizeof(float), FLT_MIN, FLT_MAX);
    printf("double\t\tNúmero real\t%d\t\t%e a %e\n", sizeof(double), DBL_MIN, DBL_MAX);
    printf("void*; int*; float*; char*\tPunteros\t%d\t\t---\n", sizeof(void *));

    return 0;
}
