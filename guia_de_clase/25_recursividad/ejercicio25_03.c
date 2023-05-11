/*3. Implemente una función que pase a binario en un vector un dato int pasado como parámetro.*/
#include <stdio.h>

void decimalToBinary(int decimal, int binary[])
{
    int i = 0;
    while (decimal > 0)
    {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }
}

int main()
{
    int decimal = 10;
    int binary[32] = {0};

    decimalToBinary(decimal, binary);

    printf("El número %d en binario es: ", decimal);
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
    printf("\n");

    return 0;
}
