/*
15. Implemente una función que obtenga el dígito verificador de un número de CUIT pasado como
parámetro, el cálculo se realiza utilizando el algoritmo módulo11. El prototipo de la función es el
siguiente:
int cuitValida (char *cuit);
Parámetros
● cuit: puntero al vector que contiene el número de CUIT terminado en ‘\0’
Devuelve:
● Un número positivo indicando el dígito verificador.
● -1: Cuando la cantidad de dígitos es distinto de 10
● -2: Indica que el número de CUIT es inválido (contiene algo distinto a números)
Algoritmo módulo 11
a. Multiplique los dígitos desde el menos significativo por la serie 2,3,4,5,6,7.
b. Sume el resultado de las multiplicaciones anteriores.
c. Calcule el módulo 11 de la suma anterior.
d. Calcule 11 menos el resultado anterior, si el resultado es menor que 10 lo obtenido es el dígito
verificador. En cambio si vale 10 el dígito verificador es 9. Si vale 11 el dígito verificador es 0
Ejemplo:
CUIT                            2   0   1   2   3   4   5   6   7   8   Suma    %11     Dígito
Valor a multiplicar por dígito  X5  X4  X3  X2  X7  X6  X5  X4  X3  X2          148%11  11-5
Resultado de la multiplicación  10  0   3   4   21  24  25  24  21  16  =148    =5      6
*/

int cuitValida(char *cuit)
{
    int longitud = strlen(cuit);

    // Comprobar que el CUIT tiene 10 dígitos
    if (longitud != 10)
    {
        return -1;
    }

    // Comprobar que el CUIT sólo contiene dígitos
    for (int i = 0; i < longitud; i++)
    {
        if (!isdigit(cuit[i]))
        {
            return -2;
        }
    }

    // Calcular dígito verificador utilizando algoritmo módulo 11
    int factores[] = {5, 4, 3, 2, 7, 6, 5, 4, 3, 2};
    int suma = 0;
    for (int i = 0; i < 10; i++)
    {
        suma += factores[i] * (cuit[i] - '0');
    }
    int resto = suma % 11;
    int verificador = 11 - resto;
    if (verificador == 10)
    {
        verificador = 9;
    }
    else if (verificador == 11)
    {
        verificador = 0;
    }
    return verificador;
}
