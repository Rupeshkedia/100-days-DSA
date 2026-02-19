#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Comparison function for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void findClosestToZero(int arr[], int n) {
    if (n < 2) {
        printf("Invalid Input\n");
        return;
    }

    // 1. Sort the array
    qsort(arr, n, sizeof(int), compare);

    int left = 0;
    int right = n - 1;
    int min_sum = INT_MAX;
    int res_l = left, res_r = right;

    // 2. Use two pointers
    while (left < right) {
        int sum = arr[left] + arr[right];

        // Update the minimum sum if the current one is closer to zero
        if (abs(sum) < abs(min_sum)) {
            min_sum = sum;
            res_l = left;
            res_r = right;
        }

        if (sum < 0) {
            left++;
        } else if (sum > 0) {
            right--;
        } else {
            // If sum is 0, it's the closest possible
            break;
        }
    }

    printf("The pair is: %d and %d\n", arr[res_l], arr[res_r]);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findClosestToZero(arr, n);

    return 0;
}