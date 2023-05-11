#include <stdio.h>

#define CANT ((int)10)

int main(void)
{
    int i;
    for (i = 0; i < CANT; i++)
    {
        printf("%d.Hola\r\n", i);
    }
    return (0);
}