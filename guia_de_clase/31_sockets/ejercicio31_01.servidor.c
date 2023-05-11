/*1. Implemente dos programas uno cliente TCP y otro servidor TCP
a. El cliente se conectará al servidor y recibirá un número entero que imprimirá en pantalla antes de
finalizar su ejecución.
b. El servidor cada vez que se conecte un cliente deberá devolverle un número aleatorio y se
quedará esperando una nueva conexión.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#ifndef SO_REUSEPORT
#define SO_REUSEPORT 15
#endif

#define PORT 8080

int main(int argc, char const *argv[])
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Crear socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Asignar direcciones y puerto
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Enlazar socket
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Escuchar conexiones entrantes
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Esperar por conexiones entrantes
    while (1)
    {
        printf("Esperando por conexiones entrantes...\n");
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t *)&addrlen)) < 0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Generar un número aleatorio y enviarlo al cliente
        srand(time(NULL));
        int random_num = rand() % 100;
        printf("Enviando número aleatorio: %d\n", random_num);
        send(new_socket, &random_num, sizeof(int), 0);

        close(new_socket);
    }

    return 0;
}
