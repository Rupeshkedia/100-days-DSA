#include <stdio.h>
#include <stdlib.h>

// Node for the bucket (Linked List)
struct Node {
    float data;
    struct Node* next;
};

// Function to sort individual buckets using Insertion Sort
struct Node* InsertionSort(struct Node* list) {
    if (!list || !list->next) return list;

    struct Node* sorted = NULL;
    struct Node* current = list;

    while (current != NULL) {
        struct Node* next = current->next;
        if (sorted == NULL || sorted->data >= current->data) {
            current->next = sorted;
            sorted = current;
        } else {
            struct Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    return sorted;
}

void BucketSort(float arr[], int n) {
    struct Node** buckets;
    buckets = (struct Node**)malloc(sizeof(struct Node*) * n);

    // 1. Initialize empty buckets
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // 2. Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        int bucketIndex = n * arr[i]; // Index in range [0, n-1]
        
        newNode->next = buckets[bucketIndex];
        buckets[bucketIndex] = newNode;
    }

    // 3. Sort individual buckets and 4. Concatenate
    int index = 0;
    for (int i = 0; i < n; i++) {
        buckets[i] = InsertionSort(buckets[i]);
        struct Node* curr = buckets[i];
        while (curr) {
            arr[index++] = curr->data;
            struct Node* temp = curr;
            curr = curr->next;
            free(temp); // Free memory
        }
    }
    free(buckets);
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    for (int i = 0; i < n; i++) printf("%f ", arr[i]);

    BucketSort(arr, n);

    printf("\n\nSorted array: \n");
    for (int i = 0; i < n; i++) printf("%f ", arr[i]);

    return 0;
}