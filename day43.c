#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to construct the tree from level order array
struct Node* constructTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    
    // Queue to keep track of parent nodes
    struct Node* queue[n];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n && front < rear) {
        struct Node* current = queue[front++];

        // Left Child
        if (i < n) {
            current->left = newNode(arr[i++]);
            if (current->left != NULL) {
                queue[rear++] = current->left;
            }
        }

        // Right Child
        if (i < n) {
            current->right = newNode(arr[i++]);
            if (current->right != NULL) {
                queue[rear++] = current->right;
            }
        }
    }
    return root;
}

// Inorder Traversal: Left -> Root -> Right
void printInorder(struct Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = constructTree(arr, n);
    
    printInorder(root);
    printf("\n");

    return 0;
}