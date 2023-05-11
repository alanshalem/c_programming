/*
Ejercicios
1. Implemente una función que calcule el promedio de un vector de tipo float. El prototipo de la función
es
float promedio (float *dataPtr, int dataCant);
Donde:
dataPtr: Es el puntero a los datos.
dataCant: Es la cantidad de elementos del vector apuntado.
*/

#include <stdio.h>

float promedio(float *dataPtr, int dataCant) {
    float suma = 0.0;
    
    for (int i = 0; i < dataCant; i++) {
        suma += dataPtr[i];
    }
    
    return suma / dataCant;
}

int main() {
    float arr[5] = {3.4, 5.2, 1.0, 7.5, 2.8};
    float prom = promedio(arr, 5);
    
    printf("El promedio es: %.2f\n", prom);
    
    return 0;
}
