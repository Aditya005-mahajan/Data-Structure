#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} node;

typedef struct {
    struct node *first;
} list;

// Function to create a list
list* make_list(void) {
    list *l;
    l = (list*) malloc(sizeof(list));
    l->first = NULL;
    return l;
}

// Function to create and insert at end
void createlist(list *l, int v) {
    node *n, *p;
    n = (node*) malloc(sizeof(node));
    n->info = v;
    n->next = NULL;

    if (l->first == NULL) {
        l->first = n;
    } else {
        p = l->first;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = n;
    }
}

// Insert at the beginning
void first_node(list *l, int v) {
    node *n;
    n = (node*) malloc(sizeof(node));
    n->info = v;
    n->next = l->first;
    l->first = n;
}

// Insert in middle (after a specific value)
void midaddnode(list *l, int p, int v) {
    node *temp = l->first;
    while (temp != NULL && temp->info != p) {
        temp = temp->next;
    }
    if (temp == NULL) return;

    node *n = (node*) malloc(sizeof(node));  // Fixed this line
    n->info = v;
    n->next = temp->next;
    temp->next = n;
}

// Insert at end (reusing createlist function)
void last_node(list *l, int v) {
    createlist(l, v);
}

// Delete by value
void delete_node(list *l, int val) {
    node *temp = l->first, *prev = NULL;

    if (temp != NULL && temp->info == val) {
        l->first = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->info != val) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

// Display list
void display(list *l) {
    node *temp = l->first;
    printf("NTR VAL IN LIST:\n");
    while (temp != NULL) {
        printf("%d\n", temp->info);
        temp = temp->next;
    }

    temp = l->first;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    list *l = make_list();

    createlist(l, 4);
    createlist(l, 8);
    createlist(l, 9);
    createlist(l, 5);
    createlist(l, 6);

    display(l);

    printf("\nNTR FIRST NODE IN LIST: 1\n");
    first_node(l, 1);
    display(l);

    printf("\nNTR NODE IN MIDDLE:\n");
    printf("ntr prev node 8\n");
    printf("ntr new node 10\n");
    midaddnode(l, 8, 10);
    display(l);

    printf("\nNTR LAST NODE: 7\n");
    last_node(l, 7);
    display(l);

    printf("\nNtr val to be del: 9\n");
    delete_node(l, 9);
    display(l);

    return 0;
}


