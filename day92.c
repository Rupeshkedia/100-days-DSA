#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* 
   Lomuto Partition Scheme:
   This function takes the last element as pivot, places
   the pivot element at its correct position in sorted
   array, and places all smaller elements to left of pivot 
   and all greater elements to right of pivot.
*/
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = (low - 1);    // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The main function that implements QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int data[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(data) / sizeof(data[0]);
    
    printf("Unsorted Array: \n");
    printArray(data, n);
    
    quickSort(data, 0, n - 1);
    
    printf("Sorted array: \n");
    printArray(data, n);
    return 0;
}