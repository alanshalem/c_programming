/*8. Programa que muestra el uso de un array de punteros a función.*/
#include <stdio.h>
#include <string.h>
#define SUMA ((int)0)
#define RESTA ((int)1)
#define DIVISION ((int)2)
#define MULTIPLICACION ((int)3)
int suma(int a, int b)
{
    return (a + b);
}
int resta(int a, int b)
{
    return (a - b);
}
int division(int a, int b)
{
    return (a / b);
}
int multiplicacion(int a, int b)
{
    return (a * b);
}
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
