/*5. Programa que imprime todos los argumentos pasados por línea de comandos*/
#include <stdio.h>
int main(int argc, char *argv[])
{
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("%d.%s\r\n", i, argv[i]);
    }
    return (0);
}
