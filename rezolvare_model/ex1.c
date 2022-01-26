#include <stdio.h>
#include <stdlib.h>

int alocare_matrice_inferioara(int ***inf, int dim) {
    /*
        [ ] ->   1
        [ ] ->   1 2
        [ ] ->   1 2 3
    */
    *inf = (int**)malloc(dim * sizeof(int*));
    if (*inf == NULL) {
        return 1;
    }

    for (int i = 0 ; i < dim ; i++) {
        (*inf)[i] = (int*)malloc((i + 1) * sizeof(int));
        if ((*inf)[i] == NULL) {
            return 1;
        }
    }
    return 0;
}

int alocare_matrice_superioara(int ***sup, int dim) {
    /*
        VIZUAL:
        [ ] ->   1 2 3
        [ ] ->     1 2
        [ ] ->       1

        MEMORIE:
        [ ] ->   1 2 3
        [ ] ->   1 2
        [ ] ->   1
    */

    *sup = (int**)malloc(dim * sizeof(int*));
    if (*sup == NULL) {
        return 1;
    }

    for (int i = 0 ; i < dim ; i++) {
        (*sup)[i] = (int*)malloc((dim - i) * sizeof(int));
        if ((*sup)[i] == NULL) {
            return 1;
        }
    }
    return 0;
}

void citire_matrice_inferioara(int ***inf, int dim) {
    for (int i = 0 ; i < dim ; i++) {
        for (int j = 0 ; j <= i ; j++) {
            scanf("%d", &(*inf)[i][j]);
        }
    }
}


void citire_matrice_superioara(int ***sup, int dim) {
    for (int i = 0 ; i < dim ; i++) {
        for (int j = 0 ; j < dim - i ; j++ ) {
            scanf("%d", &(*sup)[i][j]);
        }
    }
}

int alocare_matrice(int ***A, int lin, int col) {
    *A = (int**)malloc(lin * sizeof(int*));
    if (*A == NULL) {
        return 1;
    }
    for (int i = 0 ; i < lin ; i++) {
        (*A)[i] = (int*)malloc(col * sizeof(int));
        if ((*A)[i] == NULL) {
            return 1;
        }
    }
    return 0;
}

void formare_matrice(int ***A, int **inf, int **sup, int dim) {
    int col = dim + 1;
    for (int i = 0 ; i < dim ; i++) {
        for (int j = 0 ; j < dim - i ; j++) {
            (*A)[i][j] = sup[i][j];
        }

        for (int j = dim - i ; j < col ; j++) {
            (*A)[i][j] = inf[i][j - dim + i];
        }
    }   
}

void afisare_matrice(int **A, int dim) {
    for (int i = 0 ; i  < dim ; i++) {
        for (int j = 0 ; j < i ; j++) {
                printf("0 ");
        }
        for (int j = 0 ; j < dim + 1 ; j++) {
            printf("%d ", A[i][j]);
        }
        for (int j = 0 ; j < dim - i - 1 ; j++) {
            printf("0 ");
        }
        printf("\n");
    }
}

int alocare_vector(int **v, int dim) {
    *v = (int*)malloc(dim * sizeof(int));
    if (*v == NULL) {
        return 1;
    }
    return 0;
}

void citire_vector(int **v, int dim) {
    for (int i = 0 ; i < dim ; i++) {
        scanf("%d", &(*v)[i]);
    }
}

void produs_matrice_vector(int **A, int *x, int dim) {
    for (int i = 0 ; i < dim ; i++) {
        int prod = 0;
        for (int j = 0 ; j < dim + 1 ; j++) {
            prod += A[i][j] * x[i + j];
        }
        printf("%d\n", prod);
    }
}

void free_matrice(int ***matrice, int lin) {
    for (int i = 0 ; i < lin ; i++) {
        free((*matrice)[i]);
    }
    free(*matrice);
}

int main() {
    int dim, **inf, **sup, **A, *x;
    printf("Dimensiune: ");
    scanf("%d", &dim);

    if (alocare_matrice_inferioara(&inf, dim) == 1) {
        exit(EXIT_FAILURE);
    }

    if (alocare_matrice_superioara(&sup, dim) == 1) {
        exit(EXIT_FAILURE);
    }

    if (alocare_matrice(&A, dim, dim + 1) == 1) {
        exit(EXIT_FAILURE);
    }

    if (alocare_vector(&x, 2 * dim) == 1) {
        exit(EXIT_FAILURE);
    }

    citire_matrice_inferioara(&inf, dim);
    citire_matrice_superioara(&sup, dim);
    formare_matrice(&A, inf, sup, dim);
    citire_vector(&x, 2 * dim);
    // afisare_matrice(A, dim);
    produs_matrice_vector(A, x, dim);

    free(x);
    free_matrice(&inf, dim);
    free_matrice(&sup, dim);
    free_matrice(&A, dim);

    exit(EXIT_SUCCESS);
}