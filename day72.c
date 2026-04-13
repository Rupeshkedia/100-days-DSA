#include <stdio.h>
#include <string.h>

char findFirstRepeated(char* s) {
    // Array to store the count of characters (initialized to 0)
    // Since there are 256 possible ASCII characters
    int seen[256] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char val = s[i];

        // If the character has been seen before, return it
        if (seen[val] == 1) {
            return s[i];
        }

        // Mark the character as seen
        seen[val] = 1;
    }

    // Return null character if no repeat is found
    return '\0';
}

int main() {
    char str[] = "geeksforgeeks";
    char result = findFirstRepeated(str);

    if (result != '\0') {
        printf("The first repeated character is: %c\n", result);
    } else {
        printf("No repeated characters found.\n");
    }

    return 0;
}