// Problem Statement
// Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. If all characters repeat, return '$'.

// Input Format
// A single string s.

// Output Format
// Print the first non-repeating character or '$' if none exists.

// Sample Input
// geeksforgeeks

// Sample Output
// f

// Explanation
// The character 'f' occurs only once in the string and appears before any other non-repeating character.

#include <stdio.h>
#include <string.h>
#define MAX 256

int main() {
    char s[MAX];
    scanf("%s", s);

    int count[MAX] = {0}; // To store the count of each character

    // Count the occurrences of each character
    for (int i = 0; s[i] != '\0'; i++) {
        count[s[i]]++;
    }

    // Find the first non-repeating character
    for (int i = 0; s[i] != '\0'; i++) {
        if (count[s[i]] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    // If no non-repeating character is found, print '$'
    printf("$\n");
    return 0;
}

