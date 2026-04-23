#include <stdio.h>

// Lower Bound: First index i such that arr[i] >= x
int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n; // Default if no element is >= x

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x) {
            ans = mid;      // Potential answer, but look for a smaller index
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

// Upper Bound: First index i such that arr[i] > x
int upperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    int ans = n; // Default if no element is > x

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x) {
            ans = mid;      // Potential answer, but look for a smaller index
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int arr[] = {1, 2, 4, 4, 4, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;

    printf("Array: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    
    printf("\nTarget: %d", x);
    printf("\nLower Bound (index): %d", lowerBound(arr, n, x));
    printf("\nUpper Bound (index): %d", upperBound(arr, n, x));

    return 0;
}