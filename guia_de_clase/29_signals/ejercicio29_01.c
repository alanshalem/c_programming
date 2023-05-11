/*1. Implemente un programa que imprima la leyenda "Hola Mundo" cinco segundos después de que se
presione CTRL-C. (use alarm)*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int sig)
{
    if (sig == SIGINT)
    {
        alarm(5);
    }
    else if (sig == SIGALRM)
    {
        printf("Hola Mundo\n");
    }
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1)
    {
        perror("sigaction");
        return 1;
    }
    while (1)
    {
        pause();
    }
    return 0;
}
