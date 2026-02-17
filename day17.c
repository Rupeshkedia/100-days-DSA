#include <stdio.h>

int main() {
    int arr[] = {23, 5, 89, 1, 54, 32, 7};
    int n = sizeof(arr) / sizeof(arr[0]); 

    int max = arr[0];
    int min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i]; 
        }
        if (arr[i] < min) {
            min = arr[i]; 
        }
    }

    printf("Array elements: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    
    printf("\nMaximum value: %d", max);
    printf("\nMinimum value: %d\n", min);

    return 0;
}