#include <stdio.h>
#include <stdlib.h>

// Comparison function for qsort to sort stall positions
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to check if we can place k cows with at least 'mid' distance apart
int canPlaceCows(int stalls[], int n, int k, int mid) {
    int count = 1; // Place the first cow in the first stall
    int last_position = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - last_position >= mid) {
            count++;
            last_position = stalls[i];
            if (count == k) return 1; // Successfully placed all cows
        }
    }
    return 0; // Could not place k cows
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // 1. Sort the stalls to handle positions in order
    qsort(stalls, n, sizeof(int), compare);

    // 2. Binary Search on the answer (distance)
    int low = 1; // Minimum possible distance
    int high = stalls[n - 1] - stalls[0]; // Maximum possible distance
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlaceCows(stalls, n, k, mid)) {
            result = mid;     // This distance is possible, try for a larger one
            low = mid + 1;
        } else {
            high = mid - 1;   // Too far apart, try a smaller distance
        }
    }

    printf("%d\n", result);

    return 0;
}
