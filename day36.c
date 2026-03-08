#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *rear;
};

// Function to add an element
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    
    if (q->rear == NULL) {
        q->rear = newNode;
        q->rear->next = q->rear; // Points to itself
    } else {
        newNode->next = q->rear->next; // New node points to front
        q->rear->next = newNode;       // Old rear points to new node
        q->rear = newNode;             // Update rear to new node
    }
}

// Function to remove an element
void dequeue(struct Queue* q) {
    if (q->rear == NULL) return;

    struct Node* front = q->rear->next;
    
    if (front == q->rear) { // Only one node in queue
        free(front);
        q->rear = NULL;
    } else {
        q->rear->next = front->next; // Rear points to the new front
        free(front);
    }
}

// Function to display the queue
void display(struct Queue* q) {
    if (q->rear == NULL) return;

    struct Node* temp = q->rear->next; // Start from front
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != q->rear->next);
    printf("\n");
}

int main() {
    struct Queue q = {NULL};
    int n, m, val;

    // Input number of elements to enqueue
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val);
    }

    // Input number of dequeue operations
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        dequeue(&q);
    }

    // Output final queue
    display(&q);

    return 0;
}