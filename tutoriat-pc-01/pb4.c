// Se citește un număr întreg de la tastatură. 
// Să se determine dacă acesta este par sau impar folosind doar operatorii logici la nivel de biți.

#include <stdio.h>
#include <stdlib.h>

// &, |, <<, >>, ^, ~

// 1001&
// 0001
// ----
// 0001 -> impar

// 1000&
// 0001
// ----
// 0000

void parImpar(int n) {
    if(n & 1) {
        printf("IMPAR\n");
    } else {
        printf("PAR\n");
    }
}


int main() {
    parImpar(6);
    parImpar(7);
    return 0;
}