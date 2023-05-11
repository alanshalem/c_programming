/*2. Muestra como pasar y recibir datos de un thread*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
void *threadFunc(void *p)
{
    int i;
    int *val;
    int *q;
    val = (int *)p;
    printf("Th: val = %d\r\n", *val);
    (*val)++;
    q = (int *)malloc(1 * sizeof(int));
    if (q != NULL)
    {
        *q = 27;
    }
    pthread_exit(q);
}
int main(void)
{
    pthread_t t;
    void *tRet;
    int rVal;
    int paramVal;
    paramVal = 100;
    printf("main: paramVal = %d\r\n", paramVal);
    rVal = pthread_create(&t, NULL, threadFunc, &paramVal);
    if (rVal != 0)
    {
        printf("Errror pthread_create\r\n");
        return (-1);
    }
    rVal = pthread_join(t, &tRet);
    if (rVal != 0)
    {
        printf("Errror pthread_create\r\n");
        return (-1);
    }
    printf("main: *tRet = %d\r\n", *((int *)tRet));
    printf("main: paramVal = %d\r\n", paramVal);
    return (0);
}
