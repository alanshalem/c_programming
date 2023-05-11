/*5. Programa que lee un número entero que se encuentra almacenado en un archivo.*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *f;
    int aux;
    int a;
    //-- Abro el archivo --
    f = fopen("./pruebaNum.txt", "r");
    if (f == NULL)
    {
        printf("Error al abrir el archivo\r\n");
        return (-1);
    }
    //-- Leo un numero del archivo --
    aux = fscanf(f, "%d\r\n", &a);
    if (aux <= 0)
    {
        printf("Error al leer el archivo\r\n");
        return (-1);
    }
    else
    {
        printf("El numero leido es: %d\r\n", a);
    }
    //-- Cierro --
    aux = fclose(f);
    if (aux != 0)
    {
        printf("Error al cerrar el archivo\r\n");
    }
    return (0);
}