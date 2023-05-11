/*6. Programa que captura la presión de las teclas CTRL-C del teclado*/
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
void handler_SIGINT(int mySignal)
{
    printf("Presionaron CTRL-C %d\r\n", mySignal);
}
int main(void)
{
    int r;
    struct sigaction s;
    //-- Relleno la estructura sigaction --
    s.sa_handler = handler_SIGINT;
    s.sa_flags = 0;
    sigemptyset(&s.sa_mask);
    r = sigaction(SIGINT, &s, NULL);
    if (r < 0)
    {
        //-- Error --
        printf("sigaction error: %d> %s\r\n", errno, strerror(errno));
        return (-1);
    }
    else
    {
        //-- Configuro la alarma para dentro de 5 segundos --
        do
        {
            sleep(1);
        } while (1);
    }
    return (0);
}
