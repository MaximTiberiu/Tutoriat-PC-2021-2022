#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    char *data;
    struct node *next;
};

void print_list(struct node *n) {
    while (n != NULL) {
        printf("%s ", n->data);
        n = n->next;
    }
    printf("\n");
}

// adauga la finalul listei
void append(struct node **head, char *data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    struct node *curr_node = *head;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    

    while (curr_node->next != NULL) {
        curr_node = curr_node->next;
    }

    curr_node->next = new_node;
}

// adauga la inceputul listei
void push(struct node **head, char *data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

// adauga dupa un anumit nod
void insert(struct node *p_node, char *data) {
    if (p_node == NULL) {
        return;
    }
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = p_node->next;
    p_node->next = new_node;
}

struct node* search_node(struct node **head, char *data) {
    struct node *curr_node = *head;
    struct node *p_node;

    while (curr_node != NULL && strcmp(curr_node->data, data) <= 0) {
        p_node = curr_node;
        curr_node = curr_node->next;
    }

    if (curr_node == NULL) {
        return NULL;
    }

    p_node->next = curr_node->next;
    return p_node;
}

// inverseaza o lista
void reverse_list(struct node **head) {
    struct node * p_node = NULL;
    struct node *curr_node = *head;
    struct node *n_node = NULL;

    while (curr_node != NULL) {
        n_node = curr_node->next;
        curr_node->next = p_node;
        p_node = curr_node;
        curr_node = n_node;
    }
    *head = p_node;
}

// dezaloca memoria unei liste
void free_list(struct node **head) {
    struct node *temp_node;
    while (*head != NULL) {
        temp_node = *head;
        *head = (*head)->next;
        free(temp_node);
    }
}

int citeste_fisier(struct node **head, char *nume_fisier) {
    FILE *in = fopen(nume_fisier, "r");
    if (in == NULL) {
        return 1;
    }

    char *dividers = " .,!?;:\n";
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while((read = getline(&line, &len, in)) != -1) {
        // printf("%zu: ", read);
        // printf("%s", line);
        char *token = strtok(line, dividers);
        while (token != NULL) {
            if (toupper(token[0]) == 'M') {
                if (*head != NULL && strcmp((*head)->data, token) > 0) {
                    push(head, token);
                } else {
                    struct node * prev_node = search_node(head, token);
                    insert(prev_node, token);
                    print_list(*head);
                }  
            }
            token = strtok(NULL, dividers);
        }
    }
    printf("\n");

    fclose(in);
    return 0;
}

int main() {
    struct node *head = NULL;
    citeste_fisier(&head, "text.txt");
    print_list(head);
    free_list(&head);
    exit(EXIT_SUCCESS);
}