#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Structure for a stack node using linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to push an element onto the stack
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory Error\n");
        return;
    }
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    return poppedValue;
}

// Function to evaluate the postfix expression
int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;

    for (int i = 0; exp[i] != '\0'; i++) {
        // Skip whitespace
        if (exp[i] == ' ') continue;

        // If character is a digit, push it
        if (isdigit(exp[i])) {
            push(&stack, exp[i] - '0');
        } 
        // If character is an operator
        else {
            int val1 = pop(&stack);
            int val2 = pop(&stack);

            switch (exp[i]) {
                case '+': push(&stack, val2 + val1); break;
                case '-': push(&stack, val2 - val1); break;
                case '*': push(&stack, val2 * val1); break;
                case '/': push(&stack, val2 / val1); break;
            }
        }
    }
    return pop(&stack);
}

int main() {
    char exp[] = "2 3 1 * + 9 -";
    printf("Postfix Evaluation Result: %d\n", evaluatePostfix(exp));
    return 0;
}