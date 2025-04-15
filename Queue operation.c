#include <stdio.h>
#include <stdlib.h>

// Define a Node structure for the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a Queue structure with front and rear pointers
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create a new node
Node* CreateNode(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to create a new queue
Queue* CreateQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Function to add an element to the queue
void enqueue(Queue* q, int data) {
    Node* newnode = CreateNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newnode;
        return;
    }
    q->rear->next = newnode;
    q->rear = newnode;
}

// Function to remove and return the front element from the queue
int dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return data;
}

// Function to display the queue elements
void displayQueue(Queue* q) {
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the queue
int main() {
    Queue* q = CreateQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("Queue elements: ");
    displayQueue(q);

    printf("Dequeued element: %d\n", dequeue(q));

    printf("Queue after one dequeue: ");
    displayQueue(q);

    return 0;
}
