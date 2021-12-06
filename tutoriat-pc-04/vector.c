#include <stdio.h>
#include <stdlib.h>

int* read_1(int *n) {
    
    scanf("%d", n); // n = 5
    int *v = (int*)malloc(*n * sizeof(int)); // v = {0, 0, 0, 0, 0}

    for (int i = 0 ; i < *n ; i++) {
        scanf("%d", &v[i]);
    } // v = {1, 2, 3, 4, 5}

    return v; // {1, 2, 3, 4, 5}
}

void read(int **v, int n) {
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", (*v + i)); // scanf("%d", &(*v)[i]));
    }
}

void print(int *v, int n) {
    for (int i = 0 ; i < n ; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void alocare_memorie(int **v, int *n) {
    scanf("%d", n);
    *v = (int*)malloc(*n * sizeof(int));
}

void stergere_memorie(int **v) {
    free(*v);
}

int main() {
    // v - alocat dinamic cu valorile {0, 1, 2, 3, 4}
    // int *a = (int*)malloc(5 * sizeof(int));
    // int *v = (int*)calloc(5, sizeof(int));

    // for (int i = 0 ; i < 5 ; i++) {
    //     scanf("%d", &v[i]);
    // }

    int *v;
    int n;

    // v = read_1(&n); // v = {1, 2, 3, 4, 5}
    alocare_memorie(&v, &n);
    read(&v, n);
    print(v, n);
    stergere_memorie(&v);
    return 0;
}