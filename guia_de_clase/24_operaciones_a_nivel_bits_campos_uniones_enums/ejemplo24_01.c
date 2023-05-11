/*1. Programa que demuestra el uso de la función toBin*/
#include <stdio.h>
#include <string.h>
void chartoBin(unsigned char data, char *binPtr)
{
    int i;
    int sizeBit = sizeof(data) * 8;
    memset(binPtr, '\0', sizeof(*binPtr));
    for (i = 0; i < sizeBit; i++)
    {
        if ((data % 2) == 0)
        {
            *(binPtr + sizeBit - 1 - i) = '0';
        }
        else
        {
            *(binPtr + sizeBit - 1 - i) = '1';
        }
        data = data >> 1;
    }
    *(binPtr + i) = '\0';
}
int main(void)
{
    char vect[33];
    chartoBin((unsigned char)0x01, &vect[0]);
    printf("%s\r\n", &vect[0]);
    chartoBin((unsigned char)0x80, &vect[0]);
    printf("%s\r\n", &vect[0]);
    chartoBin((unsigned char)0xA5, &vect[0]);
    printf("%s\r\n", &vect[0]);
    return (0);
}
