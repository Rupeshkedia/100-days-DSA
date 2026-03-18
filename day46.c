#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue setup for Level Order Traversal
struct Node** createQueue(int* front, int* rear) {
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 500);
    *front = *rear = 0;
    return queue;
}

void enQueue(struct Node** queue, int* rear, struct Node* new_node) {
    queue[*rear] = new_node;
    (*rear)++;
}

struct Node* deQueue(struct Node** queue, int* front) {
    (*front)++;
    return queue[*front - 1];
}

// Function to perform Level Order Traversal
void printLevelOrder(struct Node* root) {
    int front, rear;
    struct Node** queue = createQueue(&front, &rear);
    struct Node* temp_node = root;

    while (temp_node) {
        printf("%d ", temp_node->data);

        // Enqueue left child
        if (temp_node->left)
            enQueue(queue, &rear, temp_node->left);

        // Enqueue right child
        if (temp_node->right)
            enQueue(queue, &rear, temp_node->right);

        // Dequeue node and make it temp_node
        temp_node = deQueue(queue, &front);
    }
}

// Helper function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main() {
    // Creating a sample tree
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Level Order Traversal: ");
    printLevelOrder(root);

    return 0;
}