#include <stdio.h>
#include <stdlib.h>

// Simple Insertion Sort to sort individual buckets
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n) {
    // 1. Create n empty buckets (using 2D array for simplicity in basics)
    // In a production environment, you'd use linked lists.
    float buckets[n][n]; 
    int bucketSizes[n];
    for (int i = 0; i < n; i++) bucketSizes[i] = 0;

    // 2. Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = n * arr[i]; 
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // 3. Sort individual buckets and concatenate
    int index = 0;
    for (int i = 0; i < n; i++) {
        insertionSort(buckets[i], bucketSizes[i]);
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[index++] = buckets[i][j];
        }
    }
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.123, 0.665, 0.343};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) printf("%f ", arr[i]);
    return 0;
}