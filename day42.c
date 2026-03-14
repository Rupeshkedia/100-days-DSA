#include <stdio.h>

#define MAX 100

int main()
{
    int n, i;
    int queue[MAX];
    int stack[MAX];
    int top = -1;

    // Input number of elements
    scanf("%d", &n);

    // Input queue elements
    for(i = 0; i < n; i++)
    {
        scanf("%d", &queue[i]);
    }

    // Push queue elements into stack
    for(i = 0; i < n; i++)
    {
        stack[++top] = queue[i];
    }

    // Pop from stack to reverse
    while(top != -1)
    {
        printf("%d ", stack[top--]);
    }

    return 0;
}