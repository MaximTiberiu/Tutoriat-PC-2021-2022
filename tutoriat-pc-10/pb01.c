#include <stdio.h>
#include <stdlib.h>

int alloc_matrix(int ***v, int *n) {
    scanf("%d", n);
    *v = (int**)malloc(*n * sizeof(int*));
    if (*v == NULL) {
        fprintf(stderr, "Eroare malloc!\n");
        return 1;
    }
    for (int i = 0 ; i < *n ; i++) {
        (*v)[i] = (int*)malloc(*n * sizeof(int));
        if ((*v)[i] == NULL) {
            fprintf(stderr, "Eroare malloc!\n");
            return 1;
        }
    }
    return 0;
}

void read_matrix(int ***v, int n) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            scanf("%d", &(*v)[i][j]);
        }
    }
}

void print_matrix(int **v, int n) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
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

int alloc_vector(int **v, int n) {
    *v = (int*)malloc(n * sizeof(int));
    if (*v == NULL) {
        fprintf(stderr, "Eroare malloc!\n");
        return 1;
    }
    return 0;
}

void read_vector(int **v, int n) {
    
    for (int i = 0 ; i < n ; i++) {
        // scanf("%d", &(*v)[i]);
        // SAU
        scanf("%d", (*v + i));
    }
}

void print_vector(int *v, int n) {
    for (int i = 0 ; i < n ; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void free_vector(int **v) {
    free(*v);
}

void product(int **a, int *v, int n) {
    for (int i = 0 ; i < n ; i++) {
        int sum = 0;
        for (int j = 0 ; j < n ; j++) {
            sum += a[i][j] * v[j];
        }
        printf("%d ", sum);
    }
    printf("\n");
}

int main() {
    int n, **a, *v;
    if (alloc_matrix(&a, &n) == 1) {
        return 1;
    }
    if (alloc_vector(&v, n) == 1) {
        return 1;
    }

    read_matrix(&a, n);
    read_vector(&v, n);

    printf("--------------------\n");
    print_matrix(a, n);
    printf("--------------------\n");
    print_vector(v, n);
    printf("--------------------\n");

    product(a, v, n);

    free_vector(&v);
    free_matrice(&a, n);
    return 0;
}