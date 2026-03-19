#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Helper function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to calculate the height of the tree
int getHeight(struct Node* node) {
    if (node == NULL) {
        // Base case: empty tree has height -1
        return -1;
    } else {
        // Recursive calls for subtrees
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        // Use the larger height and add 1
        if (leftHeight > rightHeight) {
            return (leftHeight + 1);
        } else {
            return (rightHeight + 1);
        }
    }
}

int main() {
    // Constructing a sample tree:
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Height of the tree is: %d", getHeight(root));

    return 0;
}