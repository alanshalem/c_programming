// 4. Elabore un programa donde se ingresan dos valores reales y el símbolo de la operación (‘+’, ‘-’, ‘*’, ‘/’).
// Se deberá presentar por pantalla, los datos ingresados, la operación y el resultado. Si el símbolo
// utilizado no correspondiera a ninguna de las cuatro operaciones deberá presentar un mensaje de
// "Operación no válida". Para leer el símbolo de la operación desde el teclado use
// scanf ("%*c%c", &op). (El programa deberá resolverse mediante el uso de la estructura
// switch)
#include <stdio.h>

int main()
{
    float num1, num2, result;
    char op;

    printf("Ingrese el primer número: ");
    scanf("%f", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%f", &num2);

    printf("Ingrese el símbolo de la operación (+, -, *, /): ");
    scanf("%*c%c", &op);

    switch (op)
    {
    case '+':
        result = num1 + num2;
        printf("%.2f + %.2f = %.2f\n", num1, num2, result);
        break;
    case '-':
        result = num1 - num2;
        printf("%.2f - %.2f = %.2f\n", num1, num2, result);
        break;
    case '*':
        result = num1 * num2;
        printf("%.2f * %.2f = %.2f\n", num1, num2, result);
        break;
    case '/':
        if (num2 == 0)
        {
            printf("No se puede dividir por cero.\n");
        }
        else
        {
            result = num1 / num2;
            printf("%.2f / %.2f = %.2f\n", num1, num2, result);
        }
        break;
    default:
        printf("Operación no válida.\n");
        break;
    }

    return 0;
}
