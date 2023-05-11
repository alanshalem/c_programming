#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50] = "Hola";
    char str2[] = " Mundo";

    // strcat: Concatenar un string con otro
    strcat(str1, str2);
    printf("%s\n", str1); // Hola Mundo

    // strchr: Busca un caracter en un string
    char *ptr = strchr(str1, 'M');
    if (ptr != NULL)
    {
        printf("El caracter 'M' fue encontrado en la posición %ld.\n", ptr - str1);
    }

    // strcmp: Compara dos strings alfabéticamente
    int cmp = strcmp(str1, "Hola Mundo");
    if (cmp == 0)
    {
        printf("Las cadenas son iguales.\n");
    }
    else if (cmp > 0)
    {
        printf("%s es mayor alfabéticamente que 'Hola Mundo'.\n", str1);
    }
    else
    {
        printf("%s es menor alfabéticamente que 'Hola Mundo'.\n", str1);
    }

    // strcpy: Copia un string en otro
    char str3[50];
    strcpy(str3, str1);
    printf("str3 = %s\n", str3); // Hola Mundo

    // strlen: Obtiene el tamaño de un string
    printf("La longitud de '%s' es %ld.\n", str1, strlen(str1)); // La longitud de 'Hola Mundo' es 10.

    // strstr: Busca un string en otro string
    char *ptr2 = strstr(str1, "Mundo");
    if (ptr2 != NULL)
    {
        printf("La cadena 'Mundo' fue encontrada en la posición %ld.\n", ptr2 - str1);
    }

    // memcpy: Copia una cantidad de bytes de una zona de memoria en otra
    char source[] = "Texto de origen";
    char destination[50];
    memcpy(destination, source, strlen(source) + 1);
    printf("destination = %s\n", destination); // Texto de origen

    // memset: Escribe una zona de memoria con un carácter determinado
    char buffer[50];
    memset(buffer, '*', sizeof(buffer));
    printf("buffer = %s\n", buffer); // **************************************************

    // memcmp: Compara dos zonas de memoria
    char s1[] = "hola";
    char s2[] = "hola";
    int result = memcmp(s1, s2, sizeof(s1));
    if (result == 0)
    {
        printf("s1 y s2 son iguales.\n");
    }
    else if (result < 0)
    {
        printf("s1 es menor que s2.\n");
    }
    else
    {
        printf("s1 es mayor que s2.\n");
    }

    return 0;
}
