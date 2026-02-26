#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int main() {
    int n, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Input number of nodes
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        // Allocate memory
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            // First node
            head = newNode;
            temp = newNode;
        } else {
            // Insert at end
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    // Forward Traversal
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}