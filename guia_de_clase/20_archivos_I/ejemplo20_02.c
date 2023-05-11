/*2. Programa lee un archivo que contiene una línea de texto y la imprime en pantalla.*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *f;
    int aux;
    char buffer[32], *p;
    //-- Abro el archivo --
    f = fopen("./prueba.txt", "r");
    if (f == NULL)
    {
        printf("Error al abrir el archivo\r\n");
        return (-1);
    }
    //-- Leo --
    p = fgets(buffer, sizeof(buffer), f);
    if (p == NULL)
    {
        printf("Error al leer el archivo\r\n");
        return (-2);
    }
    printf("El string leido es: %s\r\n", buffer);
    //-- Cierro --
    aux = fclose(f);
    if (aux != 0)
    {
        printf("Error al cerrar el archivo\r\n");
        return (-3);
    }
    return (0);
}
