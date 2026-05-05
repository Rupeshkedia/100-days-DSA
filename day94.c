#include <stdio.h>
#include <stdlib.h>

void countingSort(int array[], int size) {
    if (size <= 0) return;

    // 1. Find the maximum element to determine the range
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    // 2. Build the frequency (count) array and initialize with zeros
    // Size is max + 1 to accommodate the value of 'max' as an index
    int *count = (int *)calloc(max + 1, sizeof(int));
    int *output = (int *)malloc(size * sizeof(int));

    // Store the count of each element
    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    // 3. Compute prefix sums (Cumulative count)
    // This tells us the actual position of this digit in the output array
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // 4. Build the output array
    // We iterate backwards to maintain stability
    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // 5. Copy the sorted elements back into the original array
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }

    // Clean up memory
    free(count);
    free(output);
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int data[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(data) / sizeof(data[0]);
    
    printf("Original array: ");
    printArray(data, n);

    countingSort(data, n);

    printf("Sorted array:   ");
    printArray(data, n);
    
    return 0;
}