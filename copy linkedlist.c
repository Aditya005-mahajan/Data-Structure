#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
    struct node* random;
} node;

node* duplicate(node* head) {
    if (head == NULL)
        return NULL;

    node* cur = head;
    while (cur != NULL) {
        node* temp = cur->next;
        cur->next = (node*)malloc(sizeof(node));
        cur->next->data = cur->data;
        cur->next->next = temp;
        cur = temp;
    }

    cur = head;
    while (cur != NULL) {
        if (cur->random != NULL)
            cur->next->random = cur->random->next;
        cur = cur->next->next;
    }

    node* original = head;
    node* copy = head->next;
    node* temp = copy;

    while (original != NULL) {
        original->next = original->next->next;
        if (copy->next != NULL)
            copy->next = copy->next->next;
        original = original->next;
        copy = copy->next;
    }

    return temp;
}

void printList(node* head) {
    node* temp = head;
    while (temp != NULL) {
        printf("Data: %d, Random: %d\n", temp->data, temp->random ? temp->random->data : -1);
        temp = temp->next;
    }
}

int main() {
    node* head = (node*)malloc(sizeof(node));
    head->data = 1;
    head->next = (node*)malloc(sizeof(node));
    head->next->data = 2;
    head->next->next = (node*)malloc(sizeof(node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next;

    printList(head);
    printf("\nDuplicate list:\n");

    node* duplicate_head = duplicate(head);
    printList(duplicate_head);

    return 0;
}