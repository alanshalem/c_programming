/*3. Programa que demuestra uso del operador not*/
#include <stdio.h>
#include <string.h>
//-- Agregar la funcion chartoBin --
int main(void)
{
    unsigned char entrada;
    unsigned char salida;
    char entradaV[9];
    char salidaV[9];
    entrada = 0x00;
    salida = ~entrada;
    chartoBin(entrada, entradaV);
    chartoBin(salida, salidaV);
    printf("~%s : %s\r\n", &entradaV[0], &salidaV[0]);
    entrada = 0xFF;
    salida = entrada << 2;
    chartoBin(entrada, entradaV);
    chartoBin(salida, salidaV);
    printf("~%s : %s\r\n", &entradaV[0], &salidaV[0]);
    entrada = 0x01;
    salida = entrada << 4;
    chartoBin(entrada, entradaV);
    chartoBin(salida, salidaV);
    printf("~%s : %s\r\n", &entradaV[0], &salidaV[0]);
    entrada = 0xAA;
    salida = entrada << 7;
    chartoBin(entrada, entradaV);
    chartoBin(salida, salidaV);
    printf("~%s : %s\r\n", &entradaV[0], &salidaV[0]);
    return (0);
}
