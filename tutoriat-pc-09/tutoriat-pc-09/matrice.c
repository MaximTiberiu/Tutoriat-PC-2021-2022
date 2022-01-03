#include <stdio.h>
#include <stdlib.h>

int alloc(int ***v, int *n, int *m) {
    scanf("%d %d", n, m);
    *v = (int**)malloc(*n * sizeof(int*));
    if (*v == NULL) {
        fprintf(stderr, "Eroare malloc!\n");
        return 1;
    }
    for (int i = 0 ; i < *n ; i++) {
        (*v)[i] = (int*)malloc(*m * sizeof(int));
        if ((*v)[i] == NULL) {
            fprintf(stderr, "Eroare malloc!\n");
            return 1;
        }
    }
    return 0;
}

void read(int ***v, int n, int m) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            scanf("%d", &(*v)[i][j]);
        }
    }
}

void print(int **v, int n, int m) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
             printf("%d ", v[i][j]);
        }
       printf("\n");
    }
}

void free_matrice(int ***v, int n) {
    for (int i = 0 ; i < n ; i++) {
        free((*v)[i]);
    }
    free(*v);
}

int main() {
    int n, m, **v;
    if (alloc(&v, &n, &m) == 1) {
        return 1;
    }
    read(&v, n, m);
    print(v, n, m);
    free_matrice(&v, n);
    return 0;
}