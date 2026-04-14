#include <stdio.h>
#include <string.h>

char firstNonRepeating(char* s) {
    // There are 26 lowercase English letters
    int count[26] = {0};
    int n = strlen(s);

    // Step 1: Fill the frequency array
    // We subtract 'a' from the character to get an index from 0 to 25
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    // Step 2: Traverse the string again to find the first char with count 1
    for (int i = 0; i < n; i++) {
        if (count[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    // Step 3: If no unique character is found
    return '$';
}

int main() {
    char s[] = "geeksforgeeks";
    char result = firstNonRepeating(s);
    
    printf("The first non-repeating character is: %c\n", result);
    
    return 0;
}