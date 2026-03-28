#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a Binary Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Function to create a new node
struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

// Helper function to check if two trees are mirrors of each other
bool isMirror(struct Node* root1, struct Node* root2) {
    // If both are NULL, they are symmetric
    if (root1 == NULL && root2 == NULL)
        return true;

    // If only one is NULL, or values don't match, they are not symmetric
    if (root1 && root2 && root1->data == root2->data)
        return isMirror(root1->left, root2->right) && 
               isMirror(root1->right, root2->left);

    return false;
}

// Function to build tree from level-order traversal
struct Node* buildTree(int n, int arr[]) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * n);
    int head = 0, tail = 0;
    queue[tail++] = root;

    int i = 1;
    while (i < n && head < tail) {
        struct Node* current = queue[head++];

        // Left Child
        if (i < n) {
            current->left = newNode(arr[i++]);
            if (current->left) queue[tail++] = current->left;
        }

        // Right Child
        if (i < n) {
            current->right = newNode(arr[i++]);
            if (current->right) queue[tail++] = current->right;
        }
    }
    free(queue);
    return root;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(n, arr);

    if (isMirror(root, root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}