#include <stdio.h> // Incluimos la librería estándar de entrada-salida

int main()
{
    int entero = 42;
    printf("%d\n", entero); // Imprime el valor del entero en formato decimal
    // Salida: 42

    int entero_3d = 5;
    printf("%3d\n", entero_3d); // Imprime el valor del entero en formato decimal, ocupando tres espacios en total
    // Salida:   5 (con dos espacios adelante)

    int entero_03d = 8;
    printf("%03d\n", entero_03d); // Imprime el valor del entero en formato decimal, ocupando tres espacios en total y rellenando con ceros si hay menos de tres dígitos
    // Salida: 008

    char caracter = 'a';
    printf("%c\n", caracter); // Imprime el caracter ASCII correspondiente
    // Salida: a

    int entero_octal = 15;
    printf("%o\n", entero_octal); // Imprime el valor del entero en formato octal
    // Salida: 17

    int entero_hexa = 255;
    printf("%x\n", entero_hexa); // Imprime el valor del entero en formato hexadecimal
    // Salida: ff

    float flotante = 3.14159;
    printf("%f\n", flotante); // Imprime el valor del flotante con 6 decimales
    // Salida: 3.141590

    double doble = 2.71828;
    printf("%lf\n", doble); // Imprime el valor del doble con 6 decimales
    // Salida: 2.718280

    float flotante_2_3 = 3.14159;
    printf("%2.3f\n", flotante_2_3); // Imprime el valor del flotante con 2 dígitos antes del punto decimal y 3 después del punto decimal
    // Salida: 3.142

    printf("%%\n"); // Imprime el caracter %
    // Salida: %

    return 0;
}