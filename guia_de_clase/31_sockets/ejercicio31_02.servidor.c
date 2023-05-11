/*2. Implemente dos programas uno cliente TCP y otro servidor TCP
a. El cliente esperará el ingreso de un texto por teclado el que enviará al servidor. Luego se
quedará esperando la respuesta del mismo para imprimir lo devuelto en pantalla.
b. El servidor recibirá un texto el cual deberá convertirlo a morse y enviarlo de regreso al cliente
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void convertToMorse(char *msg);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Uso: %s <puerto>\n", argv[0]);
        return -1;
    }

    // Crear socket TCP
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1)
    {
        perror("Error al crear socket");
        return -1;
    }

    // Permitir reutilizar puerto
    int reuse = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) == -1)
    {
        perror("Error en setsockopt");
        return -1;
    }

    // Configurar dirección del servidor
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // Enlazar socket con dirección del servidor
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Error al enlazar socket con dirección del servidor");
        return -1;
    }

    // Escuchar conexiones entrantes
    if (listen(server_fd, 1) == -1)
    {
        perror("Error al escuchar conexiones entrantes");
        return -1;
    }

    printf("Servidor listo y escuchando en el puerto %s...\n", argv[1]);

    while (1)
    {
        // Aceptar conexión entrante
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd == -1)
        {
            perror("Error al aceptar conexión entrante");
            return -1;
        }

        printf("Cliente conectado\n");

        // Leer mensaje del cliente
        char buffer[BUFFER_SIZE];
        ssize_t bytes_recv = recv(client_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_recv == -1)
        {
            perror("Error al recibir mensaje del cliente");
            return -1;
        }

        buffer[bytes_recv] = '\0';
        printf("Mensaje recibido: %s\n", buffer);

        // Convertir mensaje a morse
        convertToMorse(buffer);

        // Enviar respuesta al cliente
        ssize_t bytes_sent = send(client_fd, buffer, strlen(buffer), 0);
        if (bytes_sent == -1)
        {
            perror("Error al enviar respuesta al cliente");
            return -1;
        }

        // Cerrar conexión con el cliente
        close(client_fd);
        printf("Cliente desconectado\n");
    }

    // Cerrar socket del servidor
    close(server_fd);
    printf("Socket del servidor cerrado\n");

    return 0;
}

void convertToMorse(char *msg)
{
    // Implementación de la conversión a morse
    // ...
}
