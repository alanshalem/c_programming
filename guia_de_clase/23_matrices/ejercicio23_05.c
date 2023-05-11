/*5. Implemente un programa que le permita a dos usuarios jugar al ta-te-ti. La selección del casillero a
jugar se realiza usando el número de casillero.
0 1 2
3 4 5
6 7 8
Por ejemplo si el usuario quiere colocar una X en el centro deberá ingresar 4.
El programa deberá realizar lo siguiente::
● El programa debe indicar si el usuario puede jugar en la posición que indica o si esa posición ya
fue jugada. Deberá seguir pidiéndole al usuario que juegue hasta que ingrese una jugada válida
● El programa debe indicar si algún jugador gana la partida o es un empate.*/
#include <stdio.h>

void imprimir_tablero(char tablero[])
{
    printf(" %c | %c | %c \n", tablero[0], tablero[1], tablero[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tablero[3], tablero[4], tablero[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tablero[6], tablero[7], tablero[8]);
}

int hay_ganador(char tablero[])
{
    // Comprobamos si hay un ganador en alguna de las filas
    for (int i = 0; i <= 6; i += 3)
    {
        if (tablero[i] == tablero[i + 1] && tablero[i + 1] == tablero[i + 2])
            return 1;
    }

    // Comprobamos si hay un ganador en alguna de las columnas
    for (int i = 0; i <= 2; i++)
    {
        if (tablero[i] == tablero[i + 3] && tablero[i + 3] == tablero[i + 6])
            return 1;
    }

    // Comprobamos si hay un ganador en alguna de las diagonales
    if (tablero[0] == tablero[4] && tablero[4] == tablero[8])
        return 1;

    if (tablero[2] == tablero[4] && tablero[4] == tablero[6])
        return 1;

    // Si no hay ganador, comprobamos si es empate
    for (int i = 0; i < 9; i++)
    {
        if (tablero[i] == ' ')
            return 0;
    }

    return 2;
}

int main()
{
    char tablero[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    int jugador = 1;
    int casilla;

    printf("¡Bienvenidos al Ta-Te-Ti!\n");

    while (1)
    {
        imprimir_tablero(tablero);

        // Pedimos al usuario que seleccione una casilla
        do
        {
            printf("Jugador %d, elige una casilla (0-8): ", jugador);
            scanf("%d", &casilla);

            if (tablero[casilla] != ' ')
                printf("Casilla ocupada, intenta de nuevo.\n");
        } while (tablero[casilla] != ' ');

        // Marcamos la casilla seleccionada por el jugador
        if (jugador == 1)
            tablero[casilla] = 'X';
        else
            tablero[casilla] = 'O';

        // Comprobamos si hay un ganador o empate
        if (hay_ganador(tablero) == 1)
        {
            printf("¡Jugador %d ha ganado!\n", jugador);
            imprimir_tablero(tablero);
            break;
        }
        else if (hay_ganador(tablero) == 2)
        {
            printf("¡Empate!\n");
            imprimir_tablero(tablero);
            break;
        }

        // Cambiamos de jugador
        if (jugador == 1)
            jugador = 2;
        else
            jugador = 1;
    }

    return 0;
}
