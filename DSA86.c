// Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

// Input:
// - First line: an integer n

// Output:
// - Print the integer square root of n

// Examples:
// Input:
// 64

// Output:
// 8

// Input:
// 20

// Output:
// 4

// Input:
// 1

// Output:
// 1

// Explanation:
// Binary Search is applied on the range 0 to n. At each step, the middle value is squared and compared with n. If mid * mid equals n, mid is the square root. If mid * mid is less than n, search continues in the right half; otherwise, in the left half. The final answer is the largest integer whose square does not exceed n.

#include <stdio.h>
int integerSquareRoot(int n) {
    if (n < 2) {
        return n; // The square root of 0 is 0 and the square root of 1 is 1
    }
    
    int left = 0, right = n, result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long midSquared = (long long)mid * mid; // Use long long to avoid overflow
        
        if (midSquared == n) {
            return mid; // Found exact square root
        } else if (midSquared < n) {
            result = mid; // Update result to the largest integer whose square is less than n
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }
    
    return result; // Return the largest integer whose square is less than or equal to n
}
int main() {
    int n;
    scanf("%d", &n);
    
    int sqrtResult = integerSquareRoot(n);
    printf("%d\n", sqrtResult);
    
    return 0;
}
