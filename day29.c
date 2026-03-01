#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to rotate the linked list
struct Node* rotateRight(struct Node* head, int k, int n) {
    if (!head || k == 0 || n == 0) return head;

    // Handle cases where k > n
    k = k % n;
    if (k == 0) return head;

    struct Node* temp = head;
    
    // 1. Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // 2. Make the list circular
    temp->next = head;

    // 3. Find the new tail: (n - k) steps from head
    // We move (n - k - 1) steps to land ON the new tail
    struct Node* newTail = head;
    for (int i = 0; i < n - k - 1; i++) {
        newTail = newTail->next;
    }

    // 4. Update head and break the circle
    head = newTail->next;
    newTail->next = NULL;

    return head;
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int n, k, val;
    struct Node *head = NULL, *tail = NULL;

    // Input size
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 0;
    }

    // Input elements and build list
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Input k
    scanf("%d", &k);

    // Rotate and print
    head = rotateRight(head, k, n);
    printList(head);

    return 0;
}