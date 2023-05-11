/*1. Programa imprime en pantalla su propio PID (Process ID) y el PID del proceso padre (PPID, Parent
Process ID)*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main(void)
{
    pid_t pid, ppid;
    //-- Obtengo mi pid y el pid del padre --
    pid = getpid();
    printf("PID: %d\r\n", pid);
    ppid = getppid();
    printf("PPID: %d\r\n", ppid);
    return (0);
}
