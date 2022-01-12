#include <stdio.h>
#include <stdlib.h>

int alloc_inf(int ***v, int *n) {
    scanf("%d", n);
    *v = (int**)malloc(*n * sizeof(int*));
    if (*v == NULL) {
        fprintf(stderr, "Eroare malloc!\n");
        return 1;
    }
    for (int i = 0 ; i < *n ; i++) {
        (*v)[i] = (int*)malloc((i + 1) * sizeof(int));
        if ((*v)[i] == NULL) {
            fprintf(stderr, "Eroare malloc!\n");
            return 1;
        }
    }
    return 0;
}

int alloc_sup(int ***v, int n) {
    *v = (int**)malloc(n * sizeof(int*));
    if (*v == NULL) {
        fprintf(stderr, "Eroare malloc!\n");
        return 1;
    }
    for (int i = n ; i > 0 ; i--) {
        (*v)[n - i] = (int*)malloc(i * sizeof(int));
        if ((*v)[n - i] == NULL) {
            fprintf(stderr, "Eroare malloc!\n");
            return 1;
        }
    }
    return 0;
}

/*
 n = 3

 1 1 1
 1 1
 1
*/

void read_inf(int ***v, int n) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j <= i ; j++) {
            scanf("%d", &(*v)[i][j]);
        }
    }
}

void read_sup(int ***v, int n) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < (n - i) ; j++) {
            scanf("%d", &(*v)[i][j]);
        }
    }
}

/*
 n = 3

 1 1 1
 1 1
 1
*/

void print_inf(int **v, int n) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j <= i ; j++) {
             printf("%d ", v[i][j]);
        }
       printf("\n");
    }
}

void print_sup(int **v, int n) {
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < i ; j++) {
            printf("  ");
        }
        for (int j = 0 ; j < (n - i) ; j++) {
             printf("%d ", v[i][j]);
        }
       printf("\n");
    }
}

/*
1 0 0  
2 3 0
4 5 6

7 8  9  
0 10 11 
0 0  12
*/


void product(int **inf, int **sup, int n) {
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            int prod = 0;
            if(i < j) {
                for(int k = 0 ; k <= i ; k++)
                    prod += inf[i][k] * sup[k][j - k];
            }
            else {
                for(int k = 0 ; k <= j ; k++)
                    prod += inf[i][k] * sup[k][j - k];
            }
            printf("%d ", prod);
        }
        printf("\n");
    }
}

/*
1 0 0    1
1 2 0 -> 1 2 
1 2 3    1 2 3

1 2 3    1 2 3
0 1 2 -> 1 2 
0 0 1    1 
*/

void free_matrice(int ***v, int n) {
    for (int i = 0 ; i < n ; i++) {
        free((*v)[i]);
    }
    free(*v);
}

int main() {
    int n, **i, **s;
    if (alloc_inf(&i, &n) == 1) {
        return 1;
    }
    if (alloc_sup(&s, n) == 1) {
        return 1;
    }

    read_inf(&i, n);
    read_sup(&s, n);

    printf("--------------------\n");
    print_inf(i, n);
    printf("--------------------\n");
    print_sup(s, n);
    printf("--------------------\n");

    product(i, s, n);

    free_matrice(&i, n);
    free_matrice(&s, n);
    return 0;
}
