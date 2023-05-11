/*
2. Implemente un código que genere un número pseudo aleatorio entre [0; 99] , luego el programa debe
pedirle al usuario números e indicarle si acertó o no el número generado pseudo aleatoriamente. Si el
usuario repite un número el programa deberá indicarlo, lo mismo si el usuario ingresa uno fuera de
rango.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numero_aleatorio, numero_usuario;

    // Generar número aleatorio entre [0; 99]
    srand(time(0));
    numero_aleatorio = rand() % 100;

    // Preguntar al usuario por un número y verificar si es correcto
    while (1)
    {
        printf("Adivina el número entre 0 y 99: ");
        scanf("%d", &numero_usuario);

        // Verificar si el número está en el rango correcto
        if (numero_usuario < 0 || numero_usuario > 99)
        {
            printf("El número debe estar entre 0 y 99. Intenta de nuevo.\n");
            continue;
        }

        // Verificar si el número ha sido repetido
        if (numero_usuario == numero_aleatorio)
        {
            printf("¡Felicidades! Adivinaste el número.\n");
            break;
        }
        else
        {
            printf("Incorrecto. Intenta de nuevo.\n");
        }
    }

    return 0;
}
