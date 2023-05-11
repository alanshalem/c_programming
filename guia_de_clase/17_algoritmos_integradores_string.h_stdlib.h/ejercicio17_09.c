/*
9. Implemente una función en C que valide números de tarjeta de crédito utilizando el algoritmo de Luhn.
El prototipo de la función es el siguiente: int luhnAlg(char *tarjeta), donde tarjeta es un puntero al vector que contiene el número de la tarjeta de crédito terminado en ‘\0’.
La función devuelve cero o un número positivo indicando que la tarjeta es válida. Devuelve -1 si la cantidad de dígitos de la tarjeta es distinto que 16 y devuelve -2 si el número de tarjeta es inválido.
El algoritmo de Luhn funciona de la siguiente manera:
a. Multiplica los dígitos que se encuentran en la posición par del vector por dos, si el resultado es mayor o igual que diez, se suman cada uno de los dígitos.
b. Multiplica los dígitos que se encuentran en la posición impar del vector por uno.
c. Suma todos los resultados obtenidos en los puntos a y b, obteniendo la suma llamada S. Si el módulo 10 de la suma obtenida S es igual a cero, el número de tarjeta es válido.
A continuación se muestra un ejemplo de cómo se utiliza el algoritmo de Luhn para validar un número de tarjeta de crédito. /
/ Ejemplo:
Dígitos Tarjeta                 0   1   2   3   4   5   6   7   8   9   0   1   2   3   4   7
Valor a multiplicar por dígito  X2  X1  X2  X1  X2  X1  X2  X1  X2  X1  X2  X1  X2  X1  X2  X1
Resultado de la multiplicación  0   1   4   3   8   5   12  7   16  9   0   1   4   3   8   7
Dígitos a sumar                 0   1   4   3   8   5   1+2 7   1+6 9   0   1   4   3   8   7 = 70
70%10 = 0 => La tarjeta es válida */
int luhnAlg(char *tarjeta)
{
    int longitud = 0;
    while (tarjeta[longitud] != '\0')
    {
        longitud++;
    }
    if (longitud != 16)
    {
        return -1; // La cantidad de dígitos de la tarjeta no es igual a 16
    }
    int suma = 0;
    for (int i = 0; i < longitud; i++)
    {
        int digito = tarjeta[i] - '0';
        if (i % 2 == 0)
        { // Posición par
            digito *= 2;
            if (digito >= 10)
            {
                digito = (digito / 10) + (digito % 10);
            }
        }
        suma += digito;
    }
    if (suma % 10 == 0)
    {
        return 0; // La tarjeta es válida
    }
    else
    {
        return -2; // El número de tarjeta es inválido
    }
}

int luhnAlg(char *tarjeta)
{
    int longitud = 0;
    while (tarjeta[longitud] != '\0')
    {
        longitud++;
    }
    if (longitud != 16)
    {
        return -1; // La cantidad de dígitos de la tarjeta no es igual a 16
    }
    int suma = 0;
    for (int i = 0; i < longitud; i++)
    {
        int digito = tarjeta[i] - '0';
        if (i % 2 == 0)
        { // Posición par
            digito *= 2;
            if (digito >= 10)
            {
                digito = (digito / 10) + (digito % 10);
            }
        }
        suma += digito;
    }
    if (suma % 10 == 0)
    {
        return 0; // La tarjeta es válida
    }
    else
    {
        return -2; // El número de tarjeta es inválido
    }
}
