#include <stdio.h>

// Function to merge two halves and count inversions
long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Index for left subarray
    int j = mid + 1; // Index for right subarray
    int k = left;    // Index for resultant temp subarray
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // There is an inversion because arr[i] > arr[j]
            temp[k++] = arr[j++];
            // Since left and right subarrays are sorted, all elements 
            // from arr[i] to arr[mid] will be greater than arr[j]
            inv_count += (mid - i + 1);
        }
    }

    // Copy remaining elements of left subarray, if any
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements of right subarray, if any
    while (j <= right)
        temp[k++] = arr[j++];

    // Copy back the merged elements to original array
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

// Function to split the array and sum up the counts
long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSortAndCount(arr, temp, left, mid);
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right);

        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];

    long long result = mergeSortAndCount(arr, temp, 0, n - 1);

    printf("Number of inversions are: %lld\n", result);
    return 0;
}