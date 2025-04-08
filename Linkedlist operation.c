#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int info;
    struct node *next;
} node;

typedef struct {
    struct node *first;
} list;

list *make_list(void) {
    list *l = (list *)malloc(sizeof(list));
    l->first = NULL;
    return l;
}

void creatlist(list *l, int v) {
    node *n = (node *)malloc(sizeof(node));
    n->info = v;
    
    if (l->first == NULL) {
        n->next = NULL;
        l->first = n;
    } else {
        node *p = l->first;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = n;
        n->next = NULL;
    }
}

void firstnode(list *l, int v) {
    node *n = (node *)malloc(sizeof(node));
    n->info = v;
    n->next = l->first;
    l->first = n;
}

void maddnode(list *l, int p, int v) {
    node *n = (node *)malloc(sizeof(node));
    n->info = v;
    node *t = l->first;
    
    while (t != NULL && t->info != p) {
        t = t->next;
    }
    
    if (t != NULL) {
        n->next = t->next;
        t->next = n;
    } else {
        printf("Value %d not found in the list.\n", p);
        free(n);
    }
}

void laddnode(list *l, int v) {
    creatlist(l, v);
}

void printlist(list *l) {
    node *t = l->first;
    
    printf("Linked List: ");
    while (t != NULL) {
        printf("%d -> ", t->info);
        t = t->next;
    }
    printf("NULL\n");
}

void dellist(list *l, int v) {
    node *t = l->first, *s = NULL;
    
    if (t != NULL && t->info == v) {
        l->first = t->next;
        free(t);
        return;
    }

    while (t != NULL && t->info != v) {
        s = t;
        t = t->next;
    }

    if (t == NULL) {
        printf("Value %d not found in the list.\n", v);
        return;
    }

    s->next = t->next;
    free(t);
}

int main() {
    list *ls = make_list();
    int a, v, p, i, n;

    printf("Enter the number of values in the list: ");
    scanf("%d", &n);

    printf("Enter %d values:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a);
        creatlist(ls, a);
    }

    printlist(ls);

    printf("\nEnter value to insert at first: ");
    scanf("%d", &v);
    firstnode(ls, v);
    printlist(ls);

    printf("\nEnter node after which to insert: ");
    scanf("%d", &p);
    printf("Enter new node value: ");
    scanf("%d", &v);
    maddnode(ls, p, v);
    printlist(ls);

    printf("\nEnter value to insert at last: ");
    scanf("%d", &v);
    laddnode(ls, v);
    printlist(ls);

    printf("\nEnter value to delete: ");
    scanf("%d", &v);
    dellist(ls, v);
    printlist(ls);

    return 0;
}