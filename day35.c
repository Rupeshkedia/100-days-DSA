#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Global pointers for the queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to add an element to the rear
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        return; // Memory allocation failed
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

// Function to print the queue from front to rear
void display() {
    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, value;

    // Read number of elements
    if (scanf("%d", &n) != 1) return 0;

    // Enqueue each input element
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &value) == 1) {
            enqueue(value);
        }
    }

    // Output the queue
    display();

    return 0;
}