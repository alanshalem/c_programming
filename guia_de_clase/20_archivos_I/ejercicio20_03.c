/*3. Desarrolle un programa que cree un archivo llamado prueba.txt y utilizando la función fprintf (verifique
el valor devuelto por ella) escriba todos los números impares entre cero y 100. Si el archivo existiera lo
deberá sobrescribir.*/

#include <stdio.h>

int main()
{
    FILE *archivo;
    int i;
    archivo = fopen("prueba.txt", "w"); // Crear el archivo en modo escritura (si ya existe, se sobrescribirá)
    if (archivo == NULL)
    {
        printf("Error al crear el archivo.");
        return 1;
    }
    for (i = 1; i <= 100; i += 2)
    { // Escribir los números impares en el archivo
        fprintf(archivo, "%d\n", i);
    }
    fclose(archivo); // Cerrar el archivo
    printf("Se han escrito los números impares en el archivo 'prueba.txt'.");
    return 0;
}
