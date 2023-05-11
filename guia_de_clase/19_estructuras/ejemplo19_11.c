/*11. Programa que demuestra*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data
{
    int varInt0;
    char varChar0;
    int varInt1;
    char varChar1;
};
struct dataAlign
{
    int varInt0;
    int varInt1;
    char varChar0;
    char varChar1;
};
int main(void)
{
    struct data varStruct;
    struct dataAlign varStructAlign;
    printf("sizeof(varStruct): %ld\r\n", sizeof(varStruct));
    printf("sizeof(varStructAlign): %ld\r\n", sizeof(varStructAlign));
    return (0);
}

/*
Advertencia:
El sizeof de una estructura no siempre coincide con la sumatoria de los sizeof de cada campo, esto se
debe a la alineación de los campo de la estructura.
*/
