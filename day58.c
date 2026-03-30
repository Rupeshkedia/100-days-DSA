#include <stdio.h>
#include <stdlib.h>

// Standard Tree Node Structure
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

// Search function to find index of value in inorder array
int search(int arr[], int strt, int end, int value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Recursive function to build the tree
struct Node* buildTree(int in[], int pre[], int inStrt, int inEnd, int* preIndex) {
    if (inStrt > inEnd)
        return NULL;

    // Pick current node from Preorder traversal using preIndex
    struct Node* tNode = newNode(pre[(*preIndex)++]);

    // If this node has no children, return
    if (inStrt == inEnd)
        return tNode;

    // Find the index of this node in Inorder traversal
    int inIndex = search(in, inStrt, inEnd, tNode->data);

    // Construct left and right subtrees
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, preIndex);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);

    return tNode;
}

// Function to print postorder traversal
void printPostorder(struct Node* node) {
    if (node == NULL)
        return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    int preIndex = 0;
    struct Node* root = buildTree(inorder, preorder, 0, n - 1, &preIndex);

    printPostorder(root);
    printf("\n");

    return 0;
}