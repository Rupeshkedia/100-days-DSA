#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Comparator function for qsort to sort strings alphabetically
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void findWinner(char *votes[], int n) {
    if (n == 0) return;

    // 1. Sort the array of names alphabetically
    qsort(votes, n, sizeof(char *), compareStrings);

    char *winner = votes[0];
    int max_votes = 1;
    
    char *curr_candidate = votes[0];
    int curr_count = 1;

    // 2. Iterate through the sorted list to count occurrences
    for (int i = 1; i < n; i++) {
        if (strcmp(votes[i], curr_candidate) == 0) {
            curr_count++;
        } else {
            // Check if previous candidate won
            if (curr_count > max_votes) {
                max_votes = curr_count;
                winner = curr_candidate;
            }
            // Reset for the new name encountered
            curr_candidate = votes[i];
            curr_count = 1;
        }
    }

    // Final check for the last candidate group in the loop
    if (curr_count > max_votes) {
        max_votes = curr_count;
        winner = curr_candidate;
    }

    printf("Winner: %s, Votes: %d\n", winner, max_votes);
}

int main() {
    // Example set of votes
    char *votes[] = {"John", "Johnny", "Jackie", "Johnny", "John", "Jackie"};
    int n = sizeof(votes) / sizeof(votes[0]);

    findWinner(votes, n);

    return 0;
}