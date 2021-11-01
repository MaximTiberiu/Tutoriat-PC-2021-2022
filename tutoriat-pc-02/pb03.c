/*
    Fie x și y două numere naturale. 
    Calculați numărul biților din reprezentarea binară internă a 
    numărului x a căror valoare trebuie comutată pentru a obține numărul y.
*/

#include <stdio.h>
#include <stdlib.h>

int numarBiti(int x, int y) {
    int contorBiti = 0;

    /*
        CAZ PRINCIPAL (y > x)
        x: 000101
        y: 011001
    */
    while(y) {
        if((y & 1) != (x & 1)) {
            contorBiti++;
        }
        y = y >> 1;
        x = x >> 1;
    }

    /*
        CAZ SECUNDAR (x > y)
        y: 000
        x: 101
    */
   while(x) {
       if ((x & 1) == 1) {
           contorBiti++;
       }
       x = x >> 1;
   }

   return contorBiti;
}

int main() {
    // x = 1001
    // y = 1100
    printf("%d\n", numarBiti(9, 12));

    // x = 1101
    // y = 0011
    printf("%d\n", numarBiti(13, 3));
    return 0;
}