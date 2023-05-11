/*9. Escriba un programa que le permita al usuario jugar a adivinar un número secreto entre 0 y 9. Para
ello le pedirá que ingrese un numero (el secreto) y luego le pedirá que ingrese números hasta
adivinarlo. Si el usuario ingresa un número fuera del rango válido [0; 9] deberá indicarlo y en el caso
del número secreto deberá continuar pidiendo hasta que ingrese el valor en el rango válido. El
programa continuará pidiendo números hasta que el usuario lo adivine indicando "GANASTE" con lo
cual debe de comenzar nuevamente el juego o se equivoque 3 veces indicando "NO GANASTE,
INTENTALO OTRA VEZ" . Utilice while*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numero_secreto, intentos = 0, numero_usuario;
    char jugar_nuevamente;

    srand(time(NULL)); // inicializar la semilla para generar números aleatorios
    do
    {
        numero_secreto = rand() % 10; // generar un número aleatorio entre 0 y 9
        intentos = 0;

        printf("Adivina el numero secreto (entre 0 y 9):\n");

        while (intentos < 3)
        {
            printf("Intento #%d: ", intentos + 1);
            scanf("%d", &numero_usuario);

            if (numero_usuario < 0 || numero_usuario > 9)
            {
                printf("Numero invalido. Debe ser entre 0 y 9.\n");
                continue;
            }

            if (numero_usuario == numero_secreto)
            {
                printf("GANASTE!\n");
                break;
            }
            else
            {
                printf("Incorrecto\n");
                intentos++;
            }
        }

        if (intentos == 3)
        {
            printf("NO GANASTE, INTENTALO OTRA VEZ.\n");
        }

        printf("Quieres jugar de nuevo? (s/n): ");
        scanf(" %c", &jugar_nuevamente);
    } while (jugar_nuevamente == 's' || jugar_nuevamente == 'S');

    return 0;
}
