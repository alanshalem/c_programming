/*2. Utilizando un editor de texto, cree un archivo con el nombre prueba.txt. Escriba en él la leyenda: Hola
mundo!!! guarde y cierre el archivo. Implemente un programa que lea el contenido del archivo
prueba.txt usando la función fread y que imprima el contenido por pantalla utilizando printf (Tenga en
cuenta que el archivo no está almacenado el '\0') además imprimalo usando la función printHex (No
copie la función en su código, use el archivo .c generado anteriormente) . Intente leer el archivo byte a
byte o de a 32 bytes. Verifique el valor devuelto por las funciones fread y feof en cada caso.*/

#include <stdio.h>

void printHex(void *dataPtr, int dataSize);

int main()
{
    FILE *fp;
    fp = fopen("prueba.txt", "rb"); // Abrir el archivo en modo lectura binaria

    if (fp == NULL)
    {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    printf("Leyendo el archivo byte a byte...\n");
    unsigned char buffer;
    int bytesLeidos = 0;
    while (fread(&buffer, 1, 1, fp) == 1)
    {                                      // Leer un byte del archivo
        printf("%c", buffer);              // Imprimir el byte como caracter
        printHex(&buffer, sizeof(buffer)); // Imprimir el byte en hexadecimal
        bytesLeidos++;
    }
    printf("\nSe leyeron %d bytes del archivo\n", bytesLeidos);

    fseek(fp, 0, SEEK_SET); // Volver al principio del archivo

    printf("\nLeyendo el archivo de a 32 bytes...\n");
    unsigned char buffer2[32];
    int bytesLeidos2 = 0;
    while (fread(buffer2, 1, 32, fp) == 32)
    { // Leer 32 bytes del archivo
        int i;
        for (i = 0; i < 32; i++)
        {
            printf("%c", buffer2[i]);                  // Imprimir cada byte como caracter
            printHex(&buffer2[i], sizeof(buffer2[i])); // Imprimir cada byte en hexadecimal
        }
        bytesLeidos2 += 32;
    }
    printf("\nSe leyeron %d bytes del archivo\n", bytesLeidos2);

    fclose(fp); // Cerrar el archivo

    return 0;
}

void printHex(void *dataPtr, int dataSize)
{
    unsigned char *bytePtr = (unsigned char *)dataPtr; // Convertir el puntero a un puntero a bytes
    int i;
    for (i = 0; i < dataSize; i++)
    {
        printf("%02x ", bytePtr[i]); // Imprimir cada byte en hexadecimal
    }
    printf("\n"); // Imprimir un salto de línea al final
}
