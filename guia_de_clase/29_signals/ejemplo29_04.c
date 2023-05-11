/*4. Programa que genera una excepción de división por cero y es capturada la signal SIGFPE.*/
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
void handler_SIGFPE(int mySignal)
{
    printf("Excepcion de punto flotante %d\r\n", mySignal);
    exit(0);
}
int main(void)
{
    int r;
    struct sigaction s;
    //-- Relleno la estructura sigaction --
    s.sa_handler = handler_SIGFPE;
    s.sa_flags = 0;
    sigemptyset(&s.sa_mask);
    r = sigaction(SIGFPE, &s, NULL);
    if (r < 0)
    {
        //-- Error --
        printf("sigaction error: %d> %s\r\n", errno, strerror(errno));
        return (-1);
    }
    else
    {
        printf("Calculo 1 / 0\r\n");
        //-- Division por cero en enteros genera excepcion de punto flotante --
        r = 1 / 0;
        printf("%d\r\n", r);
    }
    return (0);
}