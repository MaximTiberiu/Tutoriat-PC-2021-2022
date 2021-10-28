// Se citesc trei numere întregi de la tastatură. 
// Să se afișeze maximul dintre cele 3 numere folosind operatorul decizional.

#include <stdio.h>
#include <stdlib.h>

int max_3(int a, int b, int c) {
    // CONDITIE ? INSTRUCTIUNI_TRUE : INTRUSCTIUNI_FALSE
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

int main() {
    printf("%d\n", max_3(4, 2, 7));
    return 0;
}