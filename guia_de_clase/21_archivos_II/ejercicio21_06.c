/*6. Desarrolle un programa que lea utilizando la función fread el archivo creado en el punto anterior y
coloque los datos en un vector de enteros generado dinámicamente. Finalmente imprima en decimal y
hexadecimal por pantalla el vector de enteros leído. Compare lo impreso en pantalla con lo observado
en el archivo utilizando un editor hexadecimal.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp;
    int *vector;
    int num, count = 0;

    fp = fopen("entero.bin", "rb"); // Abrir archivo en modo lectura binaria
    if (fp == NULL)
    {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    // Obtener la cantidad de enteros en el archivo
    fseek(fp, 0L, SEEK_END);
    count = ftell(fp) / sizeof(int);
    rewind(fp);

    // Asignar memoria dinámicamente para el vector
    vector = (int *)malloc(count * sizeof(int));
    if (vector == NULL)
    {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }

    // Leer los enteros del archivo y almacenarlos en el vector
    fread(vector, sizeof(int), count, fp);

    // Cerrar el archivo
    fclose(fp);

    // Imprimir el vector en decimal y hexadecimal
    printf("Vector en decimal:\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d ", vector[i]);
    }
    printf("\n\n");

    printf("Vector en hexadecimal:\n");
    for (int i = 0; i < count; i++)
    {
        printf("0x%08X ", vector[i]);
    }
    printf("\n");

    // Liberar la memoria del vector
    free(vector);

    return 0;
}
