// valida emails, direcciones ip, numeros de tarjetas y fecha y hora
// compilar con gcc -Wall -o validar validar.c fvalidar.c
#include <stdio.h>
#include <string.h>
#include "fvalidar.h"

#define ERRCMDLINE  1
#define ERRBADFUNC  2

int main(int ac, char **av){
    int n;
    
    // valida que por lo menos haya 2 argumentos
    if (ac < 3){
        printf("Error en la linea de comandos. Cantidad de parametros insuficiente.\n");
        return ERRCMDLINE;
    }

    // opcion email
    if (strcmp(av[1], "email") == 0){
        for (n=2; n<ac; n++){
            printf("%s => email ", av[n]);
            if (validar_email(av[n]))
                printf("valido\n");
            else
                printf("invalido\n");
        }
    }

    // opcion ip
    else if (strcmp(av[1], "ip") == 0){
        for (n=2; n<ac; n++){
            printf("%s => ip ", av[n]);
            if (validar_ip(av[n]))
                printf("valida\n");
            else
                printf("invalida\n");
        }
    }

    // opcion tarjeta
    else if (strcmp(av[1], "tarjeta") == 0){
        for (n=2; n<ac; n++){
            printf("%s => tarjeta ", av[n]);
            if (validar_tarjeta(av[n]))
                printf("valida\n");
            else
                printf("invalida\n");
        }
    }

    // opcion fecha
    else if (strcmp(av[1], "fecha") == 0){
        for (n=2; n<ac; n++){
            printf("%s => fecha ", av[n]);
            if (validar_fecha(av[n]))
                printf("valida\n");
            else
                printf("invalida\n");
        }
    }

    // opcion invalida
    else {
        printf("Error en la linea de comandos. Opcion %s invalida.\n", av[1]);
        return ERRBADFUNC;
    }

    //
    return 0;
}
