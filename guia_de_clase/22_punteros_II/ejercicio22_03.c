/*3. Elabore un programa que por línea de comandos se pasan dos valores reales y el símbolo de la
operación (‘+’, ‘-’, ‘*’, ‘/’). Se deberá presentar por pantalla, los datos ingresados, la operación y el
resultado. Si el símbolo utilizado no correspondiera a ninguna de las cuatro operaciones deberá
presentar un mensaje de "Operación no válida"*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Verificar si se proporcionaron los argumentos necesarios
    if (argc != 4)
    {
        printf("Uso: %s <valor1> <valor2> <operacion>\n", argv[0]);
        return 1;
    }

    // Convertir los argumentos a números reales
    float valor1 = atof(argv[1]);
    float valor2 = atof(argv[2]);

    // Realizar la operación correspondiente
    float resultado;
    char operacion = argv[3][0]; // Obtener el primer caracter de la cadena

    switch (operacion)
    {
    case '+':
        resultado = valor1 + valor2;
        break;
    case '-':
        resultado = valor1 - valor2;
        break;
    case '*':
        resultado = valor1 * valor2;
        break;
    case '/':
        resultado = valor1 / valor2;
        break;
    default:
        printf("Operacion no valida\n");
        return 1;
    }
    // Imprimir los resultados
    printf("Valor 1: %f\n", valor1);
    printf("Valor 2: %f\n", valor2);
    printf("Operacion: %c\n", operacion);
    printf("Resultado: %f\n", resultado);

    return 0;
}
