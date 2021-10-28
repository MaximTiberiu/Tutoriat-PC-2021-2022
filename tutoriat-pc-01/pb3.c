// Se citește un număr întreg n de la tastatură. 
// Să se calculeze n * 8, n / 4 si n * 10 folosind operatorii logici de deplasare la nivel de bit

#include <stdio.h>
#include <stdlib.h>

// &, |, <<, >>, ^, ~

// (2)0010 (<<1) -> 0100(4)

int n_ori8(int n) {
    return n << 3;
}

int n_pe4(int n) {
    return n >> 2;
}

int n_ori10(int n) {
    return n << 3 + n << 1;
}

int main() {
    n_ori8(2);
    n_pe4(6);
    n_ori10(5);
    return 0;
}