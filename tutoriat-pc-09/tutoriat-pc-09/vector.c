#include <stdio.h>
#include <stdlib.h>

int alloc(int **v, int *n) {
    scanf("%d", n);
    *v = (int*)malloc(*n * sizeof(int));
    if (*v == NULL) {
        fprintf(stderr, "Eroare malloc!\n");
        return 1;
    }
    return 0;
}

void read(int **v, int n) {
    
    for (int i = 0 ; i < n ; i++) {
        // scanf("%d", &(*v)[i]);
        // SAU
        scanf("%d", (*v + i));
    }
}

void print(int *v, int n) {
    for (int i = 0 ; i < n ; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void free_vector(int **v) {
    free(*v);
}

int realloc_vector(int **v, int *n) {
    scanf("%d", n);
    int *v1 = (int*)realloc(*v, *n * sizeof(int));
    if (*v1 == NULL) {
        fprintf(stderr, "Eroare realloc!\n");
        return 1;
    } 
    *v = v1;
    return 0;
}

int main() {
    int n, *v;
    if (alloc(&v, &n) == 1) {
        return 1;
    }
    read(&v, n);
    print(v, n);
    free_vector(&v);

    // int *p = (int*)malloc(5 * sizeof(int));
    // for (int i = 0 ; i < 5 ; i++) {
    //     scanf("%d", &p[i]);
    // }
    // for (int i = 0 ; i < 5 ; i++) {
    //     printf("%d ", p[i]);
    // }
    // printf("\n");

    // p = (int*)realloc(p, 7 * sizeof(int));
    // p[2] = -789;
    // p[5] = 100;
    // p[6] = -5;
    // for (int i = 0 ; i < 7 ; i++) {
    //     printf("%d ", p[i]);
    // }
    // printf("\n");

    return 0;
}