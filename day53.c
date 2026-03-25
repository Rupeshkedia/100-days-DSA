#include <stdio.h>
#include <stdlib.h>

// Structure for a Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue element to store node and its horizontal distance
struct QueueItem {
    struct Node* node;
    int hd;
};

// Function to create a new node
struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Global or large arrays to handle vertical columns
// In a production environment, a Hash Map would be better.
int* columns[2001]; 
int columnSizes[2001];
#define OFFSET 1000 // To handle negative horizontal distances

void verticalOrder(struct Node* root) {
    if (!root) return;

    struct QueueItem queue[2000];
    int head = 0, tail = 0;

    int min_hd = 0, max_hd = 0;

    queue[tail++] = (struct QueueItem){root, 0};

    while (head < tail) {
        struct QueueItem current = queue[head++];
        struct Node* temp = current.node;
        int hd = current.hd;

        // Store the node in its respective column
        int index = hd + OFFSET;
        columns[index] = realloc(columns[index], (columnSizes[index] + 1) * sizeof(int));
        columns[index][columnSizes[index]++] = temp->data;

        if (hd < min_hd) min_hd = hd;
        if (hd > max_hd) max_hd = hd;

        if (temp->left) 
            queue[tail++] = (struct QueueItem){temp->left, hd - 1};
        if (temp->right) 
            queue[tail++] = (struct QueueItem){temp->right, hd + 1};
    }

    // Print the columns from leftmost to rightmost
    for (int i = min_hd; i <= max_hd; i++) {
        int index = i + OFFSET;
        for (int j = 0; j < columnSizes[index]; j++) {
            printf("%d ", columns[index][j]);
        }
        printf("\n");
        free(columns[index]);
    }
}

// Function to build tree from level order input
struct Node* buildTree() {
    int n, val;
    if (scanf("%d", &n) == EOF || n == 0) return NULL;
    
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    struct Node* root = newNode(arr[0]);
    struct Node* q[2000];
    int f = 0, r = 0;
    q[r++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = q[f++];
        
        // Left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[r++] = curr->left;
        }
        i++;
        
        // Right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[r++] = curr->right;
        }
        i++;
    }
    free(arr);
    return root;
}

int main() {
    struct Node* root = buildTree();
    verticalOrder(root);
    return 0;
}