/*3. Implemente dos programas uno cliente TCP y otro servidor TCP
a. El cliente leerá un archivo de texto el cual será enviado al servidor y luego se quedará
esperando la devolución de los datos por parte del main y los almacenará en otro archivo.
b. El servidor esperará conexiones de clientes y convertirá todos los caracteres a mayúscula y se
los devolverá al cliente.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <ctype.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Uso: %s <puerto>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    int opt_val = 1;
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &opt_val, sizeof(opt_val)) == -1)
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sock_fd, 5) == -1)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Servidor TCP escuchando en el puerto %d...\n", port);

    while (1)
    {
        struct sockaddr_in client_addr = {0};
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sock_fd == -1)
        {
            perror("accept");
            continue;
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_addr.sin_addr, client_ip, INET_ADDRSTRLEN);
        printf("Nueva conexión desde %s:%d\n", client_ip, ntohs(client_addr.sin_port));

        char buffer[BUF_SIZE];
        ssize_t bytes_received = recv(client_sock_fd, buffer, BUF_SIZE, 0);
        if (bytes_received == -1)
        {
            perror("recv");
            continue;
        }

        buffer[bytes_received] = '\0';
        printf("Texto recibido desde el cliente: %s\n", buffer);

        // Convertir texto a mayúsculas
        for (int i = 0; i < bytes_received; i++)
        {
            buffer[i] = toupper(buffer[i]);
        }

        if (send(client_sock_fd, buffer, bytes_received, 0) == -1)
        {
            perror("send");
            continue;
        }

        printf("Texto enviado al cliente: %s\n", buffer);

        close(client_sock_fd);
    }

    close(sock_fd);
    return 0;
}
