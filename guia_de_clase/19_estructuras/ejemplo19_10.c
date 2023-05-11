/*10.Programa que demuestra el uso de sizeof */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANT ((int)10) //!< Cantidad.
struct data
{
    char *ptr;
    int varInt;
    int vectInt[CANT];
};
int main(void)
{
    int varInt, vectInt[CANT], *ptrInt;
    char varChar, vectChar[CANT], *ptrChar;
    struct data varStruct, vectStruct[CANT], *ptrStruct;
    printf("sizeof(varInt): %d\r\n", sizeof(varInt));
    printf("sizeof(vectInt): %d\r\n", sizeof(vectInt));
    printf("sizeof(vectInt[0]): %d\r\n", sizeof(vectInt[0]));
    printf("sizeof(ptrInt): %d\r\n", sizeof(ptrInt));
    printf("sizeof(*ptrInt): %d\r\n", sizeof(*ptrInt));
    printf("sizeof(varChar): %d\r\n", sizeof(varChar));
    printf("sizeof(vectChar): %d\r\n", sizeof(vectChar));
    printf("sizeof(vectChar[0]): %d\r\n", sizeof(vectChar[0]));
    printf("sizeof(ptrChar): %d\r\n", sizeof(ptrChar));
    printf("sizeof(*ptrChar): %d\r\n", sizeof(*ptrChar));
    printf("sizeof(varStruct): %d\r\n", sizeof(varStruct));
    printf("sizeof(vectStruct): %d\r\n", sizeof(vectStruct));
    printf("sizeof(vectStruct[0]): %d\r\n", sizeof(vectStruct[0]));
    printf("sizeof(ptrStruct): %d\r\n", sizeof(ptrStruct));
    printf("sizeof(*ptrStruct): %d\r\n", sizeof(*ptrStruct));
    printf("sizeof(varStruct.ptr): %d\r\n", sizeof(varStruct.ptr));
    printf("sizeof(varStruct.varInt): %d\r\n", sizeof(varStruct.varInt));
    printf("sizeof(varStruct.vectInt): %d\r\n", sizeof(varStruct.vectInt));
    return (0);
}
