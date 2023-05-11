/*6. Programa que demuestra uso de una union*/
#include <stdio.h>
union intCharVect
{
    int varInt;
    char vectChar[4];
};
int main(void)
{
    union intCharVect data;
    data.varInt = 0x12345678;
    printf("data.varInt = 0x%x\r\n", data.varInt);
    printf("data.vectChar[0] = 0x%x\r\n", data.vectChar[0]);
    printf("data.vectChar[1] = 0x%x\r\n", data.vectChar[1]);
    printf("data.vectChar[2] = 0x%x\r\n", data.vectChar[2]);
    printf("data.vectChar[3] = 0x%x\r\n", data.vectChar[3]);
    printf("sizeof (data) = %ld\r\n", sizeof(data));
    printf("sizeof (data.varInt) = %ld\r\n", sizeof(data.varInt));
    printf("sizeof (data.vectChar) = %ld\r\n", sizeof(data.vectChar));
    return (0);
}
