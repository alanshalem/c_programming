#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
/*typedef unsigned int sigset_t;*/
void signal_handler(int sig)
{
    printf("Signal received: %d\n", sig);
}

int main()
{
    /*struct sigaction
    {
        void (*sa_handler)(int);
        sigset_t sa_mask;
        int sa_flags;
    };*/
    pid_t pid = getpid();
    printf("My PID is: %d\n", pid);

    pid_t ppid = getppid();
    printf("My parent's PID is: %d\n", ppid);

    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    printf("Sending SIGINT signal in 3 seconds...\n");
    sleep(3);
    kill(pid, SIGINT);

    printf("Setting up alarm for 5 seconds...\n");
    alarm(5);
    pause();

    printf("Exiting program...\n");
    exit(0);
}