// Pentru valori întregi citite de la tastatură 
// să se tiparească valoarea corespunzătoare în binar.

#include <stdio.h>
#include <stdlib.h>

void convert10to2_1(int number) {
    for (int i = 8 * sizeof(number) - 1 ; i >= 0 ; i--) {
        int x = 1 << i; // mask
        if ((number & x) != 0) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

void convert10to2_2(int number) {
    for (int i = 8 * sizeof(number) - 1 ; i >= 0 ; i--) {
        printf("%d", ((number & (1 << i)) != 0) ? 1 : 0);
    }
    printf("\n");
}

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

int main() {
    int n = 10;
    convert10to2_1(n);
    convert10to2_2(n);
    convert10to2_3(n);
    printf("Ne-a iesit exercitiul\n");
    return 0;
}