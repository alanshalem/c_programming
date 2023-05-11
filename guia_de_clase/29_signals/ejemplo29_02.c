/*2. Programa en el que se imprime la leyenda "Hola signal" al recibir la signal SIGUSR1*/
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void handler_SIGUSR1(int mySignal)
{
    printf("Hola signal %d\r\n", mySignal);
}

/*typedef unsigned int sigset_t;

struct sigaction
{
    void (*sa_handler)(int);
    sigset_t sa_mask;
    int sa_flags;
};*/

int main(void)
{
    int r;
    struct sigaction s;
    //-- Relleno la estructura sigaction --
    s.sa_handler = handler_SIGUSR1;
    s.sa_flags = 0;
    sigemptyset(&s.sa_mask);
    r = sigaction(SIGUSR1, &s, NULL);
    if (r < 0)
    {

        //-- Error --
        printf("sigaction error: %d> %s\r\n", errno, strerror(errno));
        return (-1);
    }
    else
    {
        printf("Espero a SIGUSR1\r\n");
        while (1)
        {
            sleep(1);
        }
    }
    return (0);
}