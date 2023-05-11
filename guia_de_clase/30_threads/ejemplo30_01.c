/*1. Crea un hilo de ejecución nuevo*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void *threadFunc1(void *p)
{
    int i;
    for (i = 0; i < 6; i++)
    {
        sleep(1);
        printf("Th1: Paso 1 segundo\r\n");
    }
    return (NULL);
}
void *threadFunc2(void *p)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        sleep(1);
        printf("Th2: Paso 1 segundo\r\n");
    }
    return (NULL);
}
int main(void)
{
    pthread_t t1;
    void *t1sRet;
    int rVal;
    rVal = pthread_create(&t1, NULL, threadFunc1, NULL);
    if (rVal != 0)
    {
        printf("Errror pthread_create\r\n");
        return (-1);
    }
    threadFunc2(NULL);
    rVal = pthread_join(t1, &t1sRet);
    if (rVal != 0)
    {
        printf("Errror pthread_create\r\n");
        return (-1);
    }
    return (0);
}