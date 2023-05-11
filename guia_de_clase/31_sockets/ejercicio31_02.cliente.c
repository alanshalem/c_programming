/*2. Implemente dos programas uno cliente TCP y otro servidor TCP
a. El cliente esperará el ingreso de un texto por teclado el que enviará al servidor. Luego se
quedará esperando la respuesta del mismo para imprimir lo devuelto en pantalla.
b. El servidor recibirá un texto el cual deberá convertirlo a morse y enviarlo de regreso al cliente*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define MSG_SIZE 1024

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[MSG_SIZE] = {0};

    // Crear el socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("Error al crear el socket");
        exit(EXIT_FAILURE);
    }

    // Configurar la dirección del servidor
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convertir la dirección IP del servidor de string a binary
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        perror("Error al convertir la dirección IP");
        exit(EXIT_FAILURE);
    }

    // Conectar al servidor
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error al conectarse al servidor");
        exit(EXIT_FAILURE);
    }

    printf("Ingrese un texto: ");
    fgets(buffer, MSG_SIZE, stdin);

    // Enviar el texto al servidor
    send(sock, buffer, strlen(buffer), 0);

    // Esperar la respuesta del servidor
    valread = read(sock, buffer, MSG_SIZE);

    printf("Texto recibido: %s\n", buffer);

    return 0;
}
