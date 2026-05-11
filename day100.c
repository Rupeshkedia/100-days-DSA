#include <stdio.h>
#include <stdlib.h>

// Structure to store value and its original position
typedef struct {
    int val;
    int index;
} Element;

void merge(Element* arr, int left, int mid, int right, int* counts, Element* temp) {
    int i = left;      // Pointer for left subarray
    int j = mid + 1;  // Pointer for right subarray
    int k = left;
    int right_smaller_count = 0;

    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            // Element on right is smaller than element on left
            right_smaller_count++;
            temp[k++] = arr[j++];
        } else {
            // Element on left is smaller or equal
            // Record how many elements from the right were jumped over
            counts[arr[i].index] += right_smaller_count;
            temp[k++] = arr[i++];
        }
    }

    // Copy remaining elements from left subarray
    while (i <= mid) {
        counts[arr[i].index] += right_smaller_count;
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy back to original array
    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }
}

void mergeSort(Element* arr, int left, int right, int* counts, Element* temp) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, counts, temp);
        mergeSort(arr, mid + 1, right, counts, temp);
        merge(arr, left, mid, right, counts, temp);
    }
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* counts = (int*)calloc(numsSize, sizeof(int));
    Element* arr = (Element*)malloc(numsSize * sizeof(Element));
    Element* temp = (Element*)malloc(numsSize * sizeof(Element));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    mergeSort(arr, 0, numsSize - 1, counts, temp);

    free(arr);
    free(temp);
    return counts;
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = 4;
    int returnSize;
    
    int* result = countSmaller(nums, n, &returnSize);

    printf("Input:  [5, 2, 6, 1]\n");
    printf("Output: [");
    for (int i = 0; i < returnSize; i++) {
        printf("%d%s", result[i], (i == returnSize - 1) ? "" : ", ");
    }
    printf("]\n");

    free(result);
    return 0;
}