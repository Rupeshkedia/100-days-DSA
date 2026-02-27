#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to get the length of a linked list
int getCount(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find the intersection point
struct Node* getIntersectionNode(struct Node* head1, struct Node* head2) {
    int c1 = getCount(head1);
    int c2 = getCount(head2);
    int d;

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    // Move the pointer of the longer list by 'd' nodes
    if (c1 > c2) {
        d = c1 - c2;
        for (int i = 0; i < d; i++) ptr1 = ptr1->next;
    } else {
        d = c2 - c1;
        for (int i = 0; i < d; i++) ptr2 = ptr2->next;
    }

    // Traverse both lists together
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1; // Intersection found
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

int main() {
    int n, m, val;
    struct Node *head1 = NULL, *head2 = NULL, *temp = NULL;

    // Input for first list
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        if (head1 == NULL) {
            head1 = temp = newNode(val);
        } else {
            temp->next = newNode(val);
            temp = temp->next;
        }
    }

    // Input for second list
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &val);
        if (head2 == NULL) {
            head2 = temp = newNode(val);
        } else {
            temp->next = newNode(val);
            temp = temp->next;
        }
    }

    struct Node* intersection = getIntersectionNode(head1, head2);

    if (intersection) {
        printf("%d\n", intersection->data);
    } else {
        printf("No Intersection\n");
    }

    return 0;
}