/*2. Implemente un programa imprima una leyenda cada cierto tiempo. La cantidad de segundos que
transcurren entre cada impresión es ingresada por línea de comandos en segundos.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

void print_message()
{
    printf("¡Hola mundo!\n");
}

int main(int argc, char *argv[])
{
    int seconds = 1; // Valor por defecto
    int option;

    // Obtener el argumento de la cantidad de segundos
    while ((option = getopt(argc, argv, "s:")) != -1)
    {
        switch (option)
        {
        case 's':
            seconds = atoi(optarg);
            break;
        default:
            fprintf(stderr, "Uso: %s [-s segundos]\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    // Imprimir mensaje cada cierto tiempo
    while (1)
    {
        print_message();
        sleep(seconds);
    }

    return 0;
}
