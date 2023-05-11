#include <stdio.h>
#include <math.h>
// Para que no arroje undefined reference to 'f(x)' debemos linkear la libreria math.h en la compilacion
// $ gcc funciones_matematicas.c -Wall -o funciones_matematicas.out -lm
int main(void)
{
    double num = 3.14159;
    double exponente = 2.0;

    // Funciones trigonométricas
    double seno = sin(num);
    printf("El seno de %f es %f\n", num, seno);

    double coseno = cos(num);
    printf("El coseno de %f es %f\n", num, coseno);

    double tangente = tan(num);
    printf("La tangente de %f es %f\n", num, tangente);

    // Funciones exponenciales y logarítmicas
    double expone = exp(exponente);
    printf("e elevado a la %f es %f\n", exponente, expone);

    double logaritmo = log(num);
    printf("El logaritmo natural de %f es %f\n", num, logaritmo);

    double logaritmo_base10 = log10(num);
    printf("El logaritmo base 10 de %f es %f\n", num, logaritmo_base10);

    // Funciones de redondeo
    double redondeo = round(num);
    printf("El redondeo de %f es %f\n", num, redondeo);

    double techo = ceil(num);
    printf("El techo de %f es %f\n", num, techo);

    double piso = floor(num);
    printf("El piso de %f es %f\n", num, piso);

    // Funciones matemáticas adicionales
    double raiz = sqrt(num);
    printf("La raíz cuadrada de %f es %f\n", num, raiz);

    double potencia = pow(num, exponente);
    printf("%f elevado a la %f es %f\n", num, exponente, potencia);

    return 0;
}