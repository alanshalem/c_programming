/*7. Programa que muestra el uso de un array de punteros a función*/
#include <stdio.h>
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
    int (*func[4])(int, int);
    int opIndex;
    //-- Asignacion del puntero a funcion --
    func[SUMA] = suma;
    func[RESTA] = resta;
    func[DIVISION] = division;
    func[MULTIPLICACION] = multiplicacion;
    //-- Ingreso de datos --
    printf("Ingrese un numero:\r\n");
    scanf("%d", &a);
    printf("Ingrese un numero:\r\n");
    scanf("%d", &b);
    printf("Ingrese operacion:\r\n");
    printf("0. Suma\r\n");
    printf("1. Resta\r\n");
    printf("2. Division\r\n");
    printf("3. Multiplicacion\r\n");
    scanf("%d", &opIndex);
    if (opIndex < SUMA || opIndex > MULTIPLICACION)
    {
        printf("Operacion invalida\r\n");
        return (-1);
    }
    //-- Uso del puntero a funcion --
    r = func[opIndex](a, b);
    printf("El resultado es: %d\r\n", r);
    return (0);
}
