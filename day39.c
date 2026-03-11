#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100005

int heap[MAX_SIZE];
int size = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Maintains heap property by moving the element up
void bubbleUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Maintains heap property by moving the element down
void bubbleDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        bubbleDown(smallest);
    }
}

void insert(int x) {
    heap[size] = x;
    bubbleUp(size);
    size++;
}

void peek() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
    }
}

void extractMin() {
    if (size == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", heap[0]);
        heap[0] = heap[size - 1];
        size--;
        bubbleDown(0);
    }
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    char op[20];
    int val;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "peek") == 0) {
            peek();
        } else if (strcmp(op, "extractMin") == 0) {
            extractMin();
        }
    }

    return 0;
}