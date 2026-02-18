#include <stdio.h>

void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotate(int arr[], int n, int k) {
    k = k % n; // Handles cases where k is larger than array size
    
    reverse(arr, 0, n - 1);    // Reverse whole array
    reverse(arr, 0, k - 1);    // Reverse first k elements
    reverse(arr, k, n - 1);    // Reverse the rest
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int k = 2;

    rotate(arr, n, k);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}