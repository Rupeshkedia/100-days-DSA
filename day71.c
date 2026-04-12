#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
#define EMPTY -1
#define DELETED -2

typedef struct {
    int key;
    int value;
} HashEntry;

HashEntry* hashTable[SIZE];

// Simple hash function
int h(int key) {
    return key % SIZE;
}

// Initialize table
void initTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Insert operation
void insert(int key, int value) {
    int index = h(key);
    for (int i = 0; i < SIZE; i++) {
        int probeIdx = (index + i * i) % SIZE;
        
        // Insert if slot is empty or previously deleted
        if (hashTable[probeIdx] == NULL || hashTable[probeIdx]->key == DELETED) {
            HashEntry* newEntry = (HashEntry*)malloc(sizeof(HashEntry));
            newEntry->key = key;
            newEntry->value = value;
            hashTable[probeIdx] = newEntry;
            return;
        }
    }
    printf("Table overflow: Could not insert %d\n", key);
}

// Search operation
int search(int key) {
    int index = h(key);
    for (int i = 0; i < SIZE; i++) {
        int probeIdx = (index + i * i) % SIZE;
        
        // If we hit a truly NULL slot, the key isn't here
        if (hashTable[probeIdx] == NULL) {
            return -1; 
        }
        
        if (hashTable[probeIdx]->key == key) {
            return hashTable[probeIdx]->value;
        }
    }
    return -1; // Not found after checking possible probes
}

int main() {
    initTable();

    // Example insertions
    insert(10, 100); // 10 % 10 = 0
    insert(20, 200); // 20 % 10 = 0 -> Collision! (0 + 1*1)%10 = 1
    insert(30, 300); // 30 % 10 = 0 -> Collision! (0 + 2*2)%10 = 4

    // Search and display results
    int keysToSearch[] = {10, 20, 30, 40};
    for (int i = 0; i < 4; i++) {
        int res = search(keysToSearch[i]);
        if (res != -1) {
            printf("Key %d: Found Value %d\n", keysToSearch[i], res);
        } else {
            printf("Key %d: Not Found\n", keysToSearch[i]);
        }
    }

    return 0;
}