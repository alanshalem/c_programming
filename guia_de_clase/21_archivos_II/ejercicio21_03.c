/*3. Desarrolle un programa que cree un archivo llamado prueba.txt y utilizando la función fwrite escriba la
leyenda Hola info1!!! Si el archivo existiera lo deberá sobrescribir. Tenga en cuenta que el carácter '\0'
no debe ser escrito en el archivo. Verifique el contenido del archivo utilizando un editor hexa y un
editor de texto. Obtenga conclusiones.*/

#include <stdio.h>

#define FILENAME "prueba.txt"

int main()
{
    FILE *filePtr = fopen(FILENAME, "w");
    if (filePtr == NULL)
    {
        printf("Error al crear el archivo.\n");
        return 1;
    }

    char *mensaje = "Hola info1!!!";
    int size = strlen(mensaje);
    fwrite(mensaje, sizeof(char), size, filePtr);

    fclose(filePtr);
    printf("El archivo ha sido creado y escrito con éxito.\n");

    return 0;
}
