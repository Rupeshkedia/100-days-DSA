#include <stdio.h>

int main() {
    char s[100];
    int len = 0;

    if (scanf("%s", s) == 1) {
        while (s[len] != '\0') {
            len++;
        }
        for (int i = len - 1; i >= 0; i--) {
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}