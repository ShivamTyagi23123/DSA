/** Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char s[100001];
  
    if (scanf("%s", s) != 1) {
        return 0;
    }

    int left = 0;
    int right = strlen(s) - 1;
    bool isPalindrome = true;

    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = false;
            break; 
        }
        left++;
        right--;
    }

    if (isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
