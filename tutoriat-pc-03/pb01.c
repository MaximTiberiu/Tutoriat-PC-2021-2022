#include <stdio.h>
#include <stdlib.h>

int cautare_binara(int a[], int x, int st, int dr) {
    // a = 1 2 3 4 5 6 7
    // x = 3

    if (st > dr) return -1;
    if (a[st] == x) return st;
    if (a[dr] == x) return dr;

    int mijloc = (st + dr) / 2;
    if (a[mijloc] == x) return mijloc;
    else if (a[mijloc] < x) return cautare_binara(a, x, mijloc + 1, dr);
    else return cautare_binara(a, x, st, mijloc - 1);
}

int main() {
    int n, e1, e2;
    scanf("%d%d%d", &n, &e1, &e2);

    int a[n];

    for(int i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
    }
    // i = 0 1 2 3 4
    // a = 7 8 5 9 8
    for(int i = 1 ; i < n ; i++) {
        if (a[i - 1] > a[i]) {
            printf("Vectorul este invalid!\n");
            return -1;
        }
    }

    int poz_e1 = cautare_binara(a, e1, 0, n - 1);
    int poz_e2 = cautare_binara(a, e2, 0, n - 1);

    if (poz_e1 == -1 || poz_e2 == -1) {
        printf("Unul dintre elementele cerute nu a fost gasit!\n");
        return -1;
    }

    if (poz_e1 > poz_e2) {
        poz_e1 = poz_e1 ^ poz_e2;
        poz_e2 = poz_e1 ^ poz_e2;
        poz_e1 = poz_e1 ^ poz_e2;
    }

    for (int i = poz_e1 ; i <= poz_e2 ; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    return 0;
}