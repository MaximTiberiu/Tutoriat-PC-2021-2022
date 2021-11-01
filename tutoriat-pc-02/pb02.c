// Se citesc 2 numere întregi, x și n, unde n este între 0 si 15. Să se afișeze: 
// bitul n din x, numărul x în care se seteaza bitul n, 
// numărul x în care se reseteaza bitul n, numărul x în care se complementează bitul n.

#include <stdio.h>
#include <stdlib.h>

const char* INVALID_INPUT_MESSAGE = "Invalid input!\n";
// * = []

void convert10to2_3(int number) {
    // 10 - 00000...0001010
    char bits[8 * sizeof(number)];

    int cnt = 0;
    while(number) {
        bits[cnt] = number & 1;
        cnt++;
        number >>= 1;
    }

    for (int i = cnt - 1 ; i >= 0 ; i--) {
        printf("%d", bits[i]);
    }
    printf("\n");
}

void testareBit(int number, int pos) {
    convert10to2_3(number);
    printf("%d", ((number & (1 << pos)) != 0) ? 1 : 0);
} 

void setareBit(int number, int pos) {
    convert10to2_3(number);
    number = number | (1 << pos);
    convert10to2_3(number);
}

void resetareBit(int number, int pos) {
    convert10to2_3(number);
    number = number & (~(1 << pos));
    convert10to2_3(number);
}

void comutareBit(int number, int pos) {
    convert10to2_3(number);
    number = number ^ (1 << pos);
    convert10to2_3(number);
}

int main() {
    int x, n;
    scanf("%d%d", &x, &n);
    if(n < 0 || n > 15) {
        printf("%s", INVALID_INPUT_MESSAGE);
        return 1;
    }

    printf("\n\n------------------TESTARE\n");
    testareBit(x, n);

    printf("\n\n------------------SETARE\n");
    setareBit(x, n);

    printf("\n\n------------------RESETARE\n");
    resetareBit(x, n);

    printf("\n\n------------------COMUTARE\n");
    comutareBit(x, n);
    return 0;
}