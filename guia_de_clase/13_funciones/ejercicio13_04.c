/*
4. Implemente una función que realice las cuatro operaciones básicas entre dos números de tipo float y
retorne el resultado. El prototipo de la función es el siguiente
float calculo (float opA, float opB, char op)
Donde:
● opA y OpB son los números con los cuales se debe realizar la operación
● op: La operación a realizar
    ○ ‘+’: Realiza la suma.
    ○ ‘-’: Realiza la resta.
    ○ ‘*’: Realiza el producto
    ○ ‘/’: Realiza la división
● La función devuelve cero si la operación es inválida.
*/

#include <stdio.h>

float calculo(float opA, float opB, char op);

int main()
{
    float opA, opB, resultado;
    char op;

    printf("Ingrese el primer número: ");
    scanf("%f", &opA);

    printf("Ingrese el segundo número: ");
    scanf("%f", &opB);

    printf("Ingrese la operación a realizar (+, -, *, /): ");
    scanf(" %c", &op);

    resultado = calculo(opA, opB, op);

    if (resultado == 0)
    {
        printf("Operación inválida.\n");
    }
    else
    {
        printf("El resultado de la operación es: %.2f\n", resultado);
    }

    return 0;
}

float calculo(float opA, float opB, char op)
{
    float resultado;

    switch (op)
    {
    case '+':
        resultado = opA + opB;
        break;
    case '-':
        resultado = opA - opB;
        break;
    case '*':
        resultado = opA * opB;
        break;
    case '/':
        if (opB == 0)
        {
            resultado = 0;
        }
        else
        {
            resultado = opA / opB;
        }
        break;
    default:
        resultado = 0;
        break;
    }

    return resultado;
}
