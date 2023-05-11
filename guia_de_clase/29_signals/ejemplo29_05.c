/*5. Programa que configura la función alarma para que se ejecute el handler de SIGALRM cada 5
segundos*/
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
void handler_SIGALRM(int mySignal)
{
    printf("Alarma %d\r\n", mySignal);
    alarm(5); //-- Configuro la alarma en 5 segundos --
}
int main(void)
{
    int r;
    struct sigaction s;
    //-- Relleno la estructura sigaction --
    s.sa_handler = handler_SIGALRM;
    s.sa_flags = 0;
    sigemptyset(&s.sa_mask);
    r = sigaction(SIGALRM, &s, NULL);
    if (r < 0)
    {
        //-- Error --
        printf("sigaction error: %d> %s\r\n", errno, strerror(errno));
        return (-1);
    }
    else
    {
        //-- Configuro la alarma para dentro de 5 segundos --
        alarm(5);
        do
        {
            pause();
        } while (1);
    }
    return (0);
}
