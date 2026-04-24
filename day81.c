#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    // Outer loop for each pass
    for (i = 0; i < n - 1; i++) {
        // Inner loop to compare adjacent elements
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if the element is greater than the next
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;

    // Input the size of the array
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];

    // Input the n space-separated integers
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    // Print the sorted array
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}