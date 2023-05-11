/*3. Programa que genera una violacion de segmento y es capturada la signal SIGSEGV.*/
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdlib.h>
void handler_SIGSEGV(int mySignal)
{
    printf("Violacion de segmento %d\r\n", mySignal);
    exit(0);
}
int main(void)
{
    int r;
    struct sigaction s;
    int *p = NULL;
    //-- Relleno la estructura sigaction --
    s.sa_handler = handler_SIGSEGV;
    s.sa_flags = 0;
    sigemptyset(&s.sa_mask);
    r = sigaction(SIGSEGV, &s, NULL);
    if (r < 0)
    {
        //-- Error --
        printf("sigaction error: %d> %s\r\n", errno, strerror(errno));
        return (-1);
    }
    else
    {
        printf("Apunto de generar una violacion de segmento\r\n");
        *p = 0;
    }
    return (0);
}
