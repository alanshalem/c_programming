/*4. Implemente un programa que le agregue la leyenda Adiós!! al archivo prueba.txt creado en el punto
anterior, sin destruir el contenido previo del archivo*/
#include <stdio.h>

int main()
{
    FILE *archivo;
    char *mensaje = "Adiós!!\n";

    archivo = fopen("prueba.txt", "a");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    fprintf(archivo, "%s", mensaje);

    fclose(archivo);

    return 0;
}
