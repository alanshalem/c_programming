// 4. Realice un programa utilizando la sentencia do-while que imprima los números del 0 al 9

#include <stdio.h>

int main(void)
{
    int i = 0;
    do
    {
        printf("i: %d \r\n", i);
        i++;
    } while (i < 10);
    return 0;
}