#include <stdio.h>

int main()
{
    unsigned int a = 0b10101010; // 170 en decimal
    unsigned int b = 0b01010101; // 85 en decimal
    unsigned int c;

    // Operación AND bit a bit
    c = a & b;
    printf("a & b = %u (0b%08x)\n", c, c);

    // Operación OR bit a bit
    c = a | b;
    printf("a | b = %u (0b%08x)\n", c, c);

    // Operación NOT bit a bit
    c = ~a;
    printf("~a = %u (0b%08x)\n", c, c);

    // Operación XOR bit a bit
    c = a ^ b;
    printf("a ^ b = %u (0b%08x)\n", c, c);

    // Desplazamiento a la izquierda
    c = a << 2;
    printf("a << 2 = %u (0b%08x)\n", c, c);

    // Desplazamiento a la derecha
    c = a >> 2;
    printf("a >> 2 = %u (0b%08x)\n", c, c);

    return 0;
}
