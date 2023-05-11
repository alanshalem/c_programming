/*5. Desarrolle un programa que le pida al usuario que ingrese 10 números enteros y los vaya almacenando
en un archivo con el nombre entero.bin utilizando la función fwrite. Verifique el contenido del archivo
utilizando un editor hexa y un editor de texto. Obtenga conclusiones.*/
#include <stdio.h>

#define MAX_NUMEROS 10

int main()
{
    int numeros[MAX_NUMEROS];

    // Pedir al usuario que ingrese los números
    printf("Ingrese %d numeros enteros:\n", MAX_NUMEROS);
    for (int i = 0; i < MAX_NUMEROS; i++)
    {
        scanf("%d", &numeros[i]);
    }

    // Abrir el archivo para escritura binaria
    FILE *archivo = fopen("entero.bin", "wb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    // Escribir los números en el archivo
    fwrite(numeros, sizeof(int), MAX_NUMEROS, archivo);

    // Cerrar el archivo
    fclose(archivo);

    // Verificar el contenido del archivo
    printf("Contenido del archivo:\n");
    archivo = fopen("entero.bin", "rb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo\n");
        return 1;
    }

    int numero_leido;
    while (fread(&numero_leido, sizeof(int), 1, archivo) == 1)
    {
        printf("%d ", numero_leido);
    }

    fclose(archivo);

    return 0;
}
