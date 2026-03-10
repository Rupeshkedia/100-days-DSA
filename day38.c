#include <stdio.h>
#include <stdbool.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int front;
    int rear;
} Deque;

// Initialize the deque
void initDeque(Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

bool isFull(Deque *dq) {
    return ((dq->front == 0 && dq->rear == MAX - 1) || (dq->front == dq->rear + 1));
}

bool isEmpty(Deque *dq) {
    return (dq->front == -1);
}

// Add to the front
void insertFront(Deque *dq, int val) {
    if (isFull(dq)) {
        printf("Deque Overflow\n");
        return;
    }
    if (dq->front == -1) { // First element
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->front == 0) { // Wrap around
        dq->front = MAX - 1;
    } else {
        dq->front--;
    }
    dq->items[dq->front] = val;
    printf("Inserted %d at front\n", val);
}

// Add to the rear
void insertRear(Deque *dq, int val) {
    if (isFull(dq)) {
        printf("Deque Overflow\n");
        return;
    }
    if (dq->front == -1) {
        dq->front = 0;
        dq->rear = 0;
    } else if (dq->rear == MAX - 1) { // Wrap around
        dq->rear = 0;
    } else {
        dq->rear++;
    }
    dq->items[dq->rear] = val;
    printf("Inserted %d at rear\n", val);
}

// Delete from front
void deleteFront(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque Underflow\n");
        return;
    }
    printf("Deleted %d from front\n", dq->items[dq->front]);
    if (dq->front == dq->rear) { // Reset if empty
        dq->front = -1;
        dq->rear = -1;
    } else if (dq->front == MAX - 1) {
        dq->front = 0;
    } else {
        dq->front++;
    }
}

int main() {
    Deque dq;
    initDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    deleteFront(&dq);
    
    return 0;
}