#include <stdio.h>
#include <stdlib.h>

// Definition of the Binary Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* node) {
    // Base Case 1: Tree is empty
    if (node == NULL) {
        return 0;
    }
    
    // Base Case 2: Node is a leaf
    if (node->left == NULL && node->right == NULL) {
        return 1;
    }
    
    // Recursive Step: Sum leaves of left and right subtrees
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}

int main() {
    /* Constructed binary tree:
                1
              /   \
             2     3
            / \
           4   5
    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Total leaf nodes: %d\n", countLeafNodes(root));

    return 0;
}