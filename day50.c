#include <stdio.h>
#include <stdlib.h>

// Definition of the node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new BST node
struct Node* createNode(int value) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Recursive function to search for a key in a BST
struct Node* search(struct Node* root, int key) {
    // Base Case: root is null (not found) or key is present at root
    if (root == NULL || root->data == key) {
        return root;
    }

    // Key is greater than root's data, search in the right subtree
    if (key > root->data) {
        return search(root->right, key);
    }

    // Key is smaller than root's data, search in the left subtree
    return search(root->left, key);
}

int main() {
    // Manually creating a simple BST for demonstration:
    //        50
    //       /  \
    //      30   70
    struct Node* root = createNode(50);
    root->left = createNode(30);
    root->right = createNode(70);

    int target = 30;
    struct Node* result = search(root, target);

    if (result != NULL) {
        printf("Element %d found in the tree.\n", result->data);
    } else {
        printf("Element %d not found.\n", target);
    }

    return 0;
}