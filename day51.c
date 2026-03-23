#include <stdio.h>
#include <stdlib.h>

// Structure for a BST node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to insert a node in BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

// Function to find the Lowest Common Ancestor
struct Node* findLCA(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        // If both n1 and n2 are smaller than root, LCA is in the left subtree
        if (root->data > n1 && root->data > n2)
            root = root->left;
        
        // If both n1 and n2 are greater than root, LCA is in the right subtree
        else if (root->data < n1 && root->data < n2)
            root = root->right;
        
        // If one is smaller and one is larger (or one is equal), this is the LCA
        else
            break;
    }
    return root;
}

int main() {
    int n, val, p, q;
    struct Node* root = NULL;

    // Input processing
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    scanf("%d %d", &p, &q);

    // Finding LCA
    struct Node* lca = findLCA(root, p, q);

    if (lca != NULL)
        printf("%d\n", lca->data);

    return 0;
}