#include <stdio.h>
#include <stdlib.h>

int main() {
    // int a = 5;
    // printf("Valoarea lui a = %d.\n", a);
    // printf("Adresa lui a = %p.\n", &a);

    // int *pa = &a;
    // printf("Adresa lui a = %p.\n", pa);
    // printf("Adresa lui pa = %p.\n", &pa);
    // printf("Valoarea lui a = %d.\n", *pa);

    // *pa = 6;
    // printf("Valoarea noua a lui a = %d.\n", a);
    // return 0;

    // int a[5]; // alocare statica

    // for (int i = 0 ; i < 5 ; i++) {
    //     scanf("%d", &a[i]);
    // }

    // for(int i = 0 ; i < 5 ; i++) {
    //     printf("%d ", a[i]);
    // }

    int *v = (int*)malloc(5 * sizeof(int));
    

    for (int i = 0 ; i < 5 ; i++) {
        scanf("%d", &v[i]);
    }

    for(int i = 0 ; i < 5 ; i++) {
        printf("%d ", v[i]);
    }

    free(v);
    return 0;
}