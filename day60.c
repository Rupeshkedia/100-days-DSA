#include <stdio.h>
#include <stdbool.h>

/**
 * Function to check if the array represents a Min-Heap.
 * We only need to check nodes that have at least one child.
 * These nodes exist from index 0 up to (n-2)/2.
 */
bool isMinHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        // Check if left child exists and violates the property
        if (arr[2 * i + 1] < arr[i]) {
            return false;
        }

        // Check if right child exists and violates the property
        if (2 * i + 2 < n && arr[2 * i + 2] < arr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    
    // Input number of elements
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    // Input level-order traversal
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n == 0 || isMinHeap(arr, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}