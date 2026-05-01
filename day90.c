#include <stdio.h>
#include <limits.h>

// Function to check if it's possible to paint all boards 
// within a given 'max_time' using at most 'k' painters.
int isPossible(int boards[], int n, int k, long long max_time) {
    int painters_count = 1;
    long long current_board_sum = 0;

    for (int i = 0; i < n; i++) {
        // If a single board is longer than max_time, it's impossible
        if (boards[i] > max_time) return 0;

        if (current_board_sum + boards[i] > max_time) {
            // Assign to a new painter
            painters_count++;
            current_board_sum = boards[i];
            
            if (painters_count > k) return 0;
        } else {
            current_board_sum += boards[i];
        }
    }
    return 1;
}

int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;

    int boards[n];
    long long low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        if (boards[i] > low) low = boards[i]; // Max element
        high += boards[i];                   // Sum of elements
    }

    long long result = high;

    // Binary search for the minimum maximum time
    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isPossible(boards, n, k, mid)) {
            result = mid;
            high = mid - 1; // Try to find a smaller maximum
        } else {
            low = mid + 1;  // Need more time
        }
    }

    printf("%lld\n", result);

    return 0;
}