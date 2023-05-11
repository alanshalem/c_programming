/*7. Programa que ejemplifica el uso de kill para enviar la SIGUSR1*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
int main(int argc, char *argv[])
{
    int r;
    //-- Verifico los argumentos --
    if (argc < 2)
    {
        printf("Uso ./enviarSignal PID\r\n");
        return (-1);
    }
    r = kill(atoi(argv[1]), SIGUSR1);
    if (r != 0)
    {
        printf("Error kill\r\n");
        return (-2);
    }
    printf("Se pudo enviar la SIGUSR1\r\n");
    return (0);
}
