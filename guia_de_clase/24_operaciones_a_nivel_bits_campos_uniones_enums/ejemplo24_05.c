/*5. Programa que demuestra uso del operador or*/
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
    salida = entrada | 0x01;
    chartoBin(entrada, entradaV);
    chartoBin(salida, salidaV);
    printf("%s | 0x01 : %s\r\n", &entradaV[0], &salidaV[0]);
    entrada = 0xF0;
    salida = entrada | 0x02;
    chartoBin(entrada, entradaV);
    chartoBin(salida, salidaV);
    printf("%s | 0x02 : %s\r\n", &entradaV[0], &salidaV[0]);
    entrada = 0x02;
    salida = entrada | 0x01;
    chartoBin(entrada, entradaV);
    chartoBin(salida, salidaV);
    printf("%s | 0x01 : %s\r\n", &entradaV[0], &salidaV[0]);
    entrada = 0x50;
    salida = entrada | 0x0F;
    chartoBin(entrada, entradaV);
    chartoBin(salida, salidaV);
    printf("%s | 0x0F : %s\r\n", &entradaV[0], &salidaV[0]);
    return (0);
}
