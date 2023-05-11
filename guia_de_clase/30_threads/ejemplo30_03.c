/*3. Muestra el uso de mutex*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int c = 0;
pthread_mutex_t lock;

void *threadFunc(void *p)
{
    int i;
    pthread_mutex_lock(&lock);
    for (i = 0; i < 1e8; i++)
    {
        c++;
    }
    pthread_mutex_unlock(&lock);
}

int main(void)
{
    pthread_t t0, t1;
    void *tRet;
    int rVal;
    rVal = pthread_create(&t0, NULL, threadFunc, NULL);
    if (rVal != 0)
    {
        printf("Errror pthread_create\r\n");
        return (-1);
    }
    rVal = pthread_create(&t1, NULL, threadFunc, NULL);
    if (rVal != 0)
    {
        printf("Errror pthread_create\r\n");
        return (-1);
    }
    rVal = pthread_join(t0, &tRet);
    if (rVal != 0)
    {
        printf("Errror pthread_create\r\n");
        return (-1);
    }
    rVal = pthread_join(t1, &tRet);
    if (rVal != 0)
    {
        printf("Errror pthread_create\r\n");
        return (-1);
    }
    printf("c: %d\r\n", c);
    return (0);
}
