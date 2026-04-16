#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10007 // A prime number for better hash distribution

// Structure for Hash Map entries
typedef struct {
    int key;   // The prefix sum
    int value; // The first index where this sum occurred
    int filled; 
} HashEntry;

// Simple Hash Function
int hash(int key) {
    int h = key % MAX_SIZE;
    return (h < 0) ? h + MAX_SIZE : h;
}

// Function to find the longest subarray with sum 0
int maxLen(int arr[], int n) {
    HashEntry* hashTable = (HashEntry*)calloc(MAX_SIZE, sizeof(HashEntry));
    int prefixSum = 0;
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // Case 1: If prefix sum is 0, the subarray is from index 0 to i
        if (prefixSum == 0) {
            max_len = i + 1;
        }

        // Case 2: Check if prefixSum exists in the hash table
        int h = hash(prefixSum);
        while (hashTable[h].filled) {
            if (hashTable[h].key == prefixSum) {
                // If found, calculate length and update max_len
                int length = i - hashTable[h].value;
                if (length > max_len) {
                    max_len = length;
                }
                goto next_iteration; 
            }
            h = (h + 1) % MAX_SIZE; // Linear probing
        }

        // Case 3: If prefixSum is new, insert it into the hash table
        hashTable[h].key = prefixSum;
        hashTable[h].value = i;
        hashTable[h].filled = 1;

        next_iteration:;
    }

    free(hashTable);
    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of the longest 0-sum subarray is %d\n", maxLen(arr, n));

    return 0;
}