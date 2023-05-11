#include <stdio.h>

int main()
{
    int numero, i, es_primo = 1;

    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);

    if (numero <= 1)
    { // comprobamos si el numero es menor o igual a 1
        printf("%d no es un numero primo.\n", numero);
        return 0;
    }

    for (i = 2; i <= numero / 2; i++)
    { // comprobamos si el numero es divisible por cualquier numero entre 2 y la mitad de si mismo
        if (numero % i == 0)
        {
            es_primo = 0;
            break;
        }
    }

    if (es_primo == 1)
    {
        printf("%d es un numero primo.\n", numero);
    }
    else
    {
        printf("%d no es un numero primo.\n", numero);
    }

    return 0;
}

/*
#define LIMITE_SUPERIOR 100

int main()
{
    int numero, i, es_primo = 1;

    printf("Ingrese un numero entero: ");
    scanf("%d", &numero);

    if (numero <= 1)
    { // comprobamos si el numero es menor o igual a 1
        printf("%d no es un numero primo.\n", numero);
        return 0;
    }

    for (i = 2; i <= numero / 2 && i <= LIMITE_SUPERIOR; i++)
    { // comprobamos si el numero es divisible por cualquier numero entre 2 y el límite superior
        if (numero % i == 0)
        {
            es_primo = 0;
            break;
        }
    }

    if (es_primo == 1)
    {
        printf("%d es un numero primo.\n", numero);
    }
    else
    {
        printf("%d no es un numero primo.\n", numero);
    }

    return 0;
}
*/
