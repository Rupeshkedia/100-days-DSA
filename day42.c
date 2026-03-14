#include <stdio.h>
#include <stdlib.h>

// Structure for Stack
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

// Structure for Queue
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

void enqueue(struct Queue* queue, int item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(struct Queue* queue) {
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Main Function to reverse the queue
void reverseQueue(struct Queue* queue) {
    struct Stack* stack = createStack(queue->capacity);

    // Step 1: Dequeue everything and push to stack
    while (queue->size > 0) {
        push(stack, dequeue(queue));
    }

    // Step 2: Pop from stack and enqueue back
    while (stack->top != -1) {
        enqueue(queue, pop(stack));
    }
}

int main() {
    int n, temp;
    if (scanf("%d", &n) != 1) return 0;

    struct Queue* queue = createQueue(n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        enqueue(queue, temp);
    }

    reverseQueue(queue);

    // Print the reversed queue
    for (int i = 0; i < n; i++) {
        printf("%d%s", dequeue(queue), (i == n - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}