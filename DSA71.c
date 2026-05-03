// Problem Statement
// Implement a hash table using quadratic probing with formula:

// h(k, i) = (h(k) + i*i) % m

// Input Format
// Same as previous.

// Output Format
// Result of SEARCH operations.

// Sample Input
// 7
// 4
// INSERT 49
// INSERT 56
// SEARCH 49
// SEARCH 15

// Sample Output
// FOUND
// NOT FOUND

// Explanation
// Collisions resolved using i² jumps.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 100
int hash_table[MAX];
int hash_function(int key, int i, int m) {
    return (key + i * i) % m;
}
void insert(int key, int m) {
    int i = 0;
    while (i < m) {
        int index = hash_function(key, i, m);
        if (hash_table[index] == -1) { // Empty slot
            hash_table[index] = key;
            return;
        }
        i++;
    }
    printf("Hash table is full. Cannot insert %d\n", key);
}
int search(int key, int m) {
    int i = 0;
    while (i < m) {
        int index = hash_function(key, i, m);
        if (hash_table[index] == -1) { // Empty slot
            return 0; // NOT FOUND
        }
        if (hash_table[index] == key) {
            return 1; // FOUND
        }
        i++;
    }
    return 0; // NOT FOUND after full probe
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for (int i = 0; i < MAX; i++) {
        hash_table[i] = -1; // Initialize hash table with -1 (indicating empty)
    }
    for (int i = 0; i < n; i++) {
        char operation[10];
        int key;
        scanf("%s %d", operation, &key);
        if (strcmp(operation, "INSERT") == 0) {
            insert(key, m);
        } else if (strcmp(operation, "SEARCH") == 0) {
            if (search(key, m)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }
    return 0;
}
