#include <stdio.h>
#include <stdlib.h>

// Helper function for qsort to sort intervals by their start time
int compare(const void *a, const void *b) {
    return (*(int **)a)[0] - (*(int **)b)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    if (intervalsSize <= 0) {
        *returnSize = 0;
        return NULL;
    }

    // 1. Sort intervals based on start time
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** merged = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));
    int count = 0;

    // 2. Initialize with the first interval
    merged[count] = (int*)malloc(2 * sizeof(int));
    merged[count][0] = intervals[0][0];
    merged[count][1] = intervals[0][1];
    (*returnColumnSizes)[count] = 2;
    count++;

    for (int i = 1; i < intervalsSize; i++) {
        // Get the last merged interval
        int lastEnd = merged[count - 1][1];

        // 3. Check for overlap
        if (intervals[i][0] <= lastEnd) {
            // Overlap: update the end time if the current interval ends later
            if (intervals[i][1] > lastEnd) {
                merged[count - 1][1] = intervals[i][1];
            }
        } else {
            // No overlap: add as a new interval
            merged[count] = (int*)malloc(2 * sizeof(int));
            merged[count][0] = intervals[i][0];
            merged[count][1] = intervals[i][1];
            (*returnColumnSizes)[count] = 2;
            count++;
        }
    }

    *returnSize = count;
    return merged;
}

int main() {
    // Example: [[1,3],[2,6],[8,10],[15,18]]
    int rows = 4;
    int* intervals[4];
    int data[4][2] = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    for(int i = 0; i < rows; i++) intervals[i] = data[i];

    int returnSize;
    int* returnColumnSizes;
    int colSize = 2;

    int** result = merge(intervals, rows, &colSize, &returnSize, &returnColumnSizes);

    printf("Merged Intervals:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("[%d, %d] ", result[i][0], result[i][1]);
        free(result[i]); // Clean up
    }
    
    free(result);
    free(returnColumnSizes);
    return 0;
}