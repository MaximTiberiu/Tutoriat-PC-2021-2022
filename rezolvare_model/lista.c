#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// sterge nodul cu informatia <data>
void delete_node(struct node **head, char *data) {
    struct node *curr_node = *head;
    struct node *p_node;

    if (curr_node != NULL && strcmp(curr_node->data, data) == 0) {
        *head = curr_node->next;
        free(curr_node);
        return;
    }

    while (curr_node != NULL && strcmp(curr_node->data, data) != 0) {
        p_node = curr_node;
        curr_node = curr_node->next;
    }

    if (curr_node == NULL) {
        return;
    }

    p_node->next = curr_node->next;
    free(curr_node);
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

int main() {
    struct node *head = NULL;
    append(&head, "mere");
    append(&head, "pere");
    append(&head, "struguri");
    push(&head, "gutui");
    push(&head, "afine");
    insert(head->next->next->next, "capsuni");
    print_list(head);
    delete_node(&head, "pere");
    print_list(head);
    reverse_list(&head);
    print_list(head);
    free_list(&head);
    exit(EXIT_SUCCESS);
}