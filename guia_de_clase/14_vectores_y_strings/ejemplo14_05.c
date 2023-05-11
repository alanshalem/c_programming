/* 5. Programa que le pide al usuario que ingrese una palabra para luego indicar la cantidad de vocales
    que tiene la misma.
*/
#include <stdio.h>
#define CANT ((int)32)
#define CANT_VOCALES ((int)10)
int main(void)
{
    char v[CANT];
    char vocales[CANT_VOCALES] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I',
                                  'O', 'U'};
    int vocalesCont = 0;
    int i, j;
    //-- Ingreso palabra --
    printf("Ingrese palabra\r\n");
    scanf("%s", &v[0]);
    //-- Cuento las vocales --
    i = 0;
    while (v[i] != '\0')
    {
        for (j = 0; j < sizeof(vocales); j++)
        {
            if (v[i] == vocales[j])
            {
                vocalesCont++;
            }
        }
        i++;
    }
    printf("La cantidad de vocales es: %d\r\n", vocalesCont);
    return (0);
}
