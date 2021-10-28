// Se dă ecuația de gradul al II-lea: ax^2 + bx + c = 0. 
// Să se calculeze rădăcinile ecuației folosind ori de câte ori se poate operatorii de atribuire combinați.

// COMPILARE IN C: gcc pb1.c -lm

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void ecuatie_grad2(float a, float b, float c) {
    float delta = b * b - 4 * a * c;
    
    if(delta < 0 ) {
        printf("Ecuatia are solutii numere complexe!\n");
    } else if(delta == 0) {
        float x = -b / (2 * a);
        printf("Ecuatia are solutiile x1 = x2 = %f!\n", x);
    } else {
        float x1 = (-b + sqrt(delta)) / (2 * a);
        float x2 = (-b - sqrt(delta)) / (2 * a);
        printf("Ecuatia are solutiile: x1 = %f si x2 = %f!", x1, x2);
    }
}

int main() {
    // int a, b, c;
    // scanf("%f%f%f", &a, &b, &c);
    // ecuatie_grad2(a, b, c);
    // ecuatie_grad2(1, 2, 3);
    return 0;
}