/*2. Programa que demuestra el desplazamiento a la izquierda y a la derecha. Imprime la operación
realizada con los valores en binario.*/
#include <stdio.h>
#include <string.h>
//-- Agregar la funcion chartoBin --
int main(void)
{
    unsigned char entrada;
    unsigned char salida;
    char entradaV[9];
    char salidaV[9];
    entrada = 0x01;
    salida = entrada << 1;
    chartoBin(entrada, entradaV);
    chartoBin(salida, salidaV);
    printf("%s << 1 : %s\r\n", &entradaV[0], &salidaV[0]);
    entrada = 0x01;
    salida = entrada << 2;
    chartoBin(entrada, entradaV);
    chartoBin(salida, salidaV);
    printf("%s << 2 : %s\r\n", &entradaV[0], &salidaV[0]);
    entrada = 0x01;
    salida = entrada << 4;
    chartoBin(entrada, entradaV);
    chartoBin(salida, salidaV);
    printf("%s << 4 : %s\r\n", &entradaV[0], &salidaV[0]);
    entrada = 0x01;
    salida = entrada << 7;
    chartoBin(entrada, entradaV);
    chartoBin(salida, salidaV);
    printf("%s << 7 : %s\r\n", &entradaV[0], &salidaV[0]);
    entrada = 0x80;
    salida = entrada >> 1;
    chartoBin(entrada, entradaV);
    chartoBin(salida, salidaV);
    printf("%s >> 1 : %s\r\n", &entradaV[0], &salidaV[0]);
    entrada = 0x80;
    salida = entrada >> 2;
    chartoBin(entrada, entradaV);
    chartoBin(salida, salidaV);
    printf("%s >> 2 : %s\r\n", &entradaV[0], &salidaV[0]);
    entrada = 0x80;
    salida = entrada >> 4;
    chartoBin(entrada, entradaV);
    chartoBin(salida, salidaV);
    printf("%s >> 4 : %s\r\n", &entradaV[0], &salidaV[0]);
    entrada = 0xA0;
    salida = entrada >> 7;
    chartoBin(entrada, entradaV);
    chartoBin(salida, salidaV);
    printf("%s >> 7 : %s\r\n", &entradaV[0], &salidaV[0]);
    return (0);
}
