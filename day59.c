#include <stdio.h>
#include <stdlib.h>

// Structure for a binary tree node
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

// Function to find the index of a value in inorder array
int search(int arr[], int strt, int end, int value) {
    for (int i = strt; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

/* Recursive function to construct binary tree 
   postIndex is passed as a pointer to keep track of root candidates */
struct Node* buildTreeUtil(int in[], int post[], int inStrt, int inEnd, int* postIndex) {
    // Base case
    if (inStrt > inEnd)
        return NULL;

    // Pick current node from postorder traversal using postIndex
    struct Node* node = newNode(post[*postIndex]);
    (*postIndex)--;

    // If this node has no children, return
    if (inStrt == inEnd)
        return node;

    // Find the index of this node in Inorder traversal
    int inIndex = search(in, inStrt, inEnd, node->data);

    /* Using index in Inorder traversal, construct right and left subtrees.
       NOTE: Right subtree must be built first because in postorder, 
       the root of the right subtree appears before the left. */
    node->right = buildTreeUtil(in, post, inIndex + 1, inEnd, postIndex);
    node->left = buildTreeUtil(in, post, inStrt, inIndex - 1, postIndex);

    return node;
}

// Function to print preorder traversal
void printPreorder(struct Node* node) {
    if (node == NULL)
        return;
    printf("%d ", node->data);
    printPreorder(node->left);
    printPreorder(node->right);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int in[n], post[n];
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);

    int postIndex = n - 1;
    struct Node* root = buildTreeUtil(in, post, 0, n - 1, &postIndex);

    printPreorder(root);
    printf("\n");

    return 0;
}