#include <stdio.h>

int main() {
    int m, n, i, j;
    int sum = 0;

    if (scanf("%d %d", &m, &n) != 2) return 0;

    int matrix[m][n];

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            
            if (i == j) {
                sum += matrix[i][j];
            }
        }
    }

    printf("%d\n", sum);

    return 0;
}