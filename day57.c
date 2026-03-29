#include <stdio.h>
#include <stdlib.h>

// Structure for the tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Function to mirror the tree
void mirror(struct Node* root) {
    if (root == NULL) return;

    // Swap left and right children
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursive calls
    mirror(root->left);
    mirror(root->right);
}

// Inorder traversal: Left -> Root -> Right
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Driver code to handle level-order input
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    if (n == 0) return 0;

    int val;
    scanf("%d", &val);
    struct Node* root = newNode(val);

    // Queue for level-order construction
    struct Node* queue[n];
    int head = 0, tail = 0;
    queue[tail++] = root;

    for (int i = 1; i < n && head < tail; ) {
        struct Node* current = queue[head++];

        // Process left child
        if (scanf("%d", &val) == 1) {
            if (val != -1) {
                current->left = newNode(val);
                queue[tail++] = current->left;
            }
            i++;
        }

        // Process right child
        if (i < n && scanf("%d", &val) == 1) {
            if (val != -1) {
                current->right = newNode(val);
                queue[tail++] = current->right;
            }
            i++;
        }
    }

    mirror(root);
    inorder(root);
    printf("\n");

    return 0;
}