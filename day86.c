#include <stdio.h>

/**
 * Finds the integer square root of a non-negative integer using Binary Search.
 * The integer square root is the greatest integer whose square <= n.
 */
long long integerSquareRoot(long long n) {
    // Base cases for 0 and 1
    if (n < 2) {
        return n;
    }

    long long low = 1, high = n;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        // Using division to prevent potential overflow (mid * mid <= n)
        if (mid <= n / mid) {
            ans = mid;     // mid could be the answer, so store it
            low = mid + 1; // Look for a larger value in the right half
        } else {
            high = mid - 1; // Square is too large, look in the left half
        }
    }

    return ans;
}

int main() {
    long long n;

    // Read input n
    if (scanf("%lld", &n) != 1) {
        return 0;
    }

    // Call function and print result
    printf("%lld\n", integerSquareRoot(n));

    return 0;
}