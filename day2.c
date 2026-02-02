int main() {
    int n, pos;
    scanf("%d", &n);
    
    int arr[1000]; 
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    scanf("%d", &pos);
    pos--;  
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}