/*1. Implemente dos programas uno cliente TCP y otro servidor TCP
a. El cliente se conectará al servidor y recibirá un número entero que imprimirá en pantalla antes de
finalizar su ejecución.
b. El servidor cada vez que se conecte un cliente deberá devolverle un número aleatorio y se
quedará esperando una nueva conexión.*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[])
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    int num;

    // Crear socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\nError al crear socket\n");
        return -1;
    }

    // Configurar la dirección del servidor
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convertir la dirección IP de formato texto a formato binario
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("\nDirección no válida/soportada\n");
        return -1;
    }

    // Conectar al servidor
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConexión fallida\n");
        return -1;
    }

    // Leer el número enviado por el servidor
    valread = read(sock, &num, sizeof(num));
    printf("Número recibido del servidor: %d\n", num);

    // Cerrar el socket
    close(sock);

    return 0;
}
