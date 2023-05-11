/*2. Programa que escribe en un archivo llamado prueba.bin un número entero ingresado por teclado*/
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    FILE *f;
    int aux, a;
    //-- Abro el archivo --
    f = fopen("./prueba.bin", "w");
    if (f == NULL)
    {
        printf("Error al abrir el archivo\r\n");
        return (-1);
    }
    //-- Ingreso un entero --
    printf("Ingrese un numero\r\n");
    scanf("%d", &a);
    //-- Escribo --
    aux = fwrite(&a, sizeof(a), 1, f);
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