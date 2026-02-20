// Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the count of subarrays having sum zero

// Example:
// Input:
// 6
// 1 -1 2 -2 3 -3

// Output:
// 6

// Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Hash map: key = prefix sum, value = count
    // Using simple array-based map for range of sums
    int map_size = 200001;
    int *map = (int *)calloc(map_size, sizeof(int));
    int offset = 100000; // to handle negative indices
    
    long long count = 0;
    int prefix_sum = 0;
    map[offset] = 1; // prefix sum 0 appears once at start
    
    for (int i = 0; i < n; i++) {
        prefix_sum += arr[i];
        
        // If this prefix sum appeared before, add to count
        int idx = prefix_sum + offset;
        if (idx >= 0 && idx < map_size) {
            count += map[idx];
            map[idx]++;
        }
    }
    
    free(arr);
    free(map);
    
    printf("%lld\n", count);
    
    return 0;
}
