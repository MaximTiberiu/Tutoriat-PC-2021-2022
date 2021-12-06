#include <stdio.h>
#include <stdlib.h>

int** read_1(int *n, int*m) {
    scanf("%d%d", n, m);

    int **a = (int**)malloc(*n * sizeof(int*));
    for (int i = 0 ; i < *n ; i++) {
        a[i] = (int*)malloc(*m * sizeof(int));
    }

    for (int i = 0 ; i < *n ; i++) {
        for (int j = 0 ; j < *m ; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    return a;
}

void read(int ***a, int n, int m) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            scanf("%d", &(*a)[i][j]);
        }
    }
}

void print(int **a, int n, int m) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void alocare_memorie(int ***a, int *n, int *m) {
    scanf("%d%d", n, m);
    *a = (int**)malloc(*n * sizeof(int*));
    for (int i = 0 ; i < *n ; i++) {
        (*a)[i] = (int*)malloc(*m * sizeof(int));
    }
}

void stergere_memorie(int ***a, int n) {
    for (int i = 0 ; i < n ; i++) {
        free((*a)[i]);
    }
    free(*a);
}

int main() {
    int **a;
    int n, m;
    // scanf("%d%d", &n, &m);

    // a = (int**)malloc(n * sizeof(int*));
    // for (int i = 0 ; i < n ; i++) {
    //     a[i] = (int*)malloc(m * sizeof(int));
    // }
    
    // for (int i = 0 ; i < n ; i++) {
    //     for (int j = 0 ; j < m ; j++) {
    //         scanf("%d", &a[i][j]);
    //     }
    // }

    // read(&a, &n, &m);
    alocare_memorie(&a, &n, &m);
    read(&a, n, m);
    printf("--------\n\n");
    print(a, n, m);
    stergere_memorie(&a, n);
    
    return 0;
}