/*1. Programa que le pide al usuario el nombre de un archivo e imprima en pantalla el tamaño en bytes del
mismo.*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(void)
{
    int aux;
    struct stat st;
    //-- leo la estructura stat del archivo --
    aux = stat("./ejemplo01.c", &st);
    if (aux < 0)
    {
        printf("Error en fstat\r\n");
        return (-1);
    }
    printf("El archivo tiene %ld bytes\r\n", st.st_size);
    return (0);
}
