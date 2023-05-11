/*4. Programa que escribe un número entero ingresado por el usuario en un archivo llamado pruebaNum.txt*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *f;
    int aux;
    int a;
    //-- Ingreso de un numero entero --
    printf("Ingrese numero\r\n");
    scanf("%d", &a);
    //-- Abro el archivo --
    f = fopen("./pruebaNum.txt", "w");
    if (f == NULL)
    {
        printf("Error al abrir el archivo\r\n");
        return (-1);
    }
    //-- Escribo --
    aux = fprintf(f, "%d\r\n", a);
    if (aux < 0)
    {
        printf("Error al escribir en el archivo\r\n");
        return (-1);
    }
    //-- Cierro --
    aux = fclose(f);
    if (aux != 0)
    {
        printf("Error al cerrar el archivo\r\n");
    }
    return (0);
}
