// Problem Statement
// Given a string s consisting of lowercase letters, find the first repeated character in the string. A character is considered repeated if it appears more than once, and among all such characters, the one whose second occurrence has the smallest index should be returned.

// Input Format
// A single string s.

// Output Format
// Print the first repeated character. If no character is repeated, print -1.

// Sample Input
// geeksforgeeks

// Sample Output
// e

#include <stdio.h>
#include <string.h>
#define MAX 256

int main() {
    char s[MAX];
    scanf("%s", s);
    
    int count[MAX] = {0}; // To store the count of each character
    int first_repeated_index = MAX; // To store the index of the first repeated character
    char first_repeated_char = -1; // To store the first repeated character
    
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i]]++;
        if (count[s[i]] == 2) { // If the character is repeated
            if (i < first_repeated_index) { // Check if it's the first repeated character
                first_repeated_index = i;
                first_repeated_char = s[i];
            }
        }
    }
    
    if (first_repeated_char != -1) {
        printf("%c\n", first_repeated_char);
    } else {
        printf("-1\n");
    }
    
    return 0;
}
