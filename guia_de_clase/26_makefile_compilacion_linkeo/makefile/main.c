#include <stdio.h>
#include <string.h>
#include "funciones.h"
int main(void)
{
    int a, b, r;
    char op, *p;
    int (*func[4])(int, int);
    char listOp[] = "+-/*";
    int opIndex;
    //-- Asignacion del puntero a funcion --
    func[SUMA] = suma;
    func[RESTA] = resta;
    func[DIVISION] = division;
    func[MULTIPLICACION] = multiplicacion;
    //-- Ingreso de datos --
    printf("Ingrese un numero:\r\n");
    scanf("%d", &a);
    printf("Ingrese operacion\r\n");
    scanf("%*c%c", &op);
    printf("Ingrese un numero:\r\n");
    scanf("%d", &b);
    p = strchr(listOp, op);
    if (p == NULL)
    {
        printf("Operacion invalida\r\n");
        return (0);
    }
    opIndex = (int)(p - listOp);
    //-- Uso del puntero a funcion --
    r = func[opIndex](a, b);
    printf("El resultado es: %d\r\n", r);
    return (0);
}
