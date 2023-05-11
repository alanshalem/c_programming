/*3. Implemente dos programas uno cliente TCP y otro servidor TCP
a. El cliente leerá un archivo de texto el cual será enviado al servidor y luego se quedará
esperando la devolución de los datos por parte del main y los almacenará en otro archivo.
b. El servidor esperará conexiones de clientes y convertirá todos los caracteres a mayúscula y se
los devolverá al cliente.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <IP> <port>\n", argv[0]);
        exit(1);
    }
    char *ip = argv[1];
    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        perror("socket() error");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect() error");
        exit(1);
    }

    char filename[BUF_SIZE];
    printf("Enter the name of the file to send: ");
    fgets(filename, BUF_SIZE, stdin);
    filename[strlen(filename) - 1] = '\0'; // remove newline character from fgets

    FILE *fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        perror("fopen() error");
        exit(1);
    }

    char buf[BUF_SIZE];
    int read_cnt = 0;
    while ((read_cnt = fread(buf, 1, BUF_SIZE, fp)) > 0)
    {
        write(sock, buf, read_cnt);
    }

    shutdown(sock, SHUT_WR);

    memset(buf, 0, sizeof(buf));
    int read_len = 0;
    while ((read_len = read(sock, buf, BUF_SIZE)) > 0)
    {
        fwrite(buf, 1, read_len, stdout);
    }

    fclose(fp);
    close(sock);

    return 0;
}
