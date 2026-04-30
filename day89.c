#include <stdio.h>
#include <stdbool.h>

// Function to check if a specific 'max pages' limit is feasible
bool isPossible(int arr[], int n, int m, int mid) {
    int studentCount = 1;
    int currentSum = 0;

    for (int i = 0; i < n; i++) {
        if (currentSum + arr[i] <= mid) {
            currentSum += arr[i];
        } else {
            studentCount++;
            // If students needed exceed m or a single book is larger than mid
            if (studentCount > m || arr[i] > mid) {
                return false;
            }
            currentSum = arr[i];
        }
    }
    return true;
}

int allocateBooks(int arr[], int n, int m) {
    if (m > n) return -1; // Not enough books for each student to have one

    int sum = 0;
    int maxVal = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }

    int low = maxVal;
    int high = sum;
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;   // This mid works, but try to find a smaller maximum
            high = mid - 1;
        } else {
            low = mid + 1;  // This mid is too small, increase the limit
        }
    }
    return result;
}

// Standard main function to avoid 'undefined reference to WinMain'
int main() {
    int n, m;
    
    // Reading input: n = number of books, m = number of students
    if (scanf("%d %d", &n, &m) != 2) {
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int answer = allocateBooks(arr, n, m);
    printf("%d\n", answer);

    return 0;
}