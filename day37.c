// Problem Statement:
// Implement a Priority Queue using an array. An element with smaller value has higher priority.

// Supported Operations:
// - insert x
// - delete
// - peek

// Input Format:
// - First line contains integer N
// - Next N lines contain operations

// Output Format:
// - Print the deleted or peeked element
// - Print -1 if the queue is empty

// Example:
// Input:
// 5
// insert 30
// insert 10
// insert 20
// delete
// peek

// Output:
// 10
// 20

#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x)
{
    if(size == MAX)
    {
        printf("Queue Full\n");
        return;
    }

    int i = size - 1;

    // shift elements to maintain ascending order
    while(i >= 0 && pq[i] > x)
    {
        pq[i+1] = pq[i];
        i--;
    }

    pq[i+1] = x;
    size++;
}

void deleteElement()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", pq[0]);

    for(int i=1;i<size;i++)
        pq[i-1] = pq[i];

    size--;
}

void peek()
{
    if(size == 0)
        printf("-1\n");
    else
        printf("%d\n", pq[0]);
}

int main()
{
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        char op[10];
        scanf("%s",op);

        if(strcmp(op,"insert")==0)
        {
            int x;
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"delete")==0)
        {
            deleteElement();
        }
        else if(strcmp(op,"peek")==0)
        {
            peek();
        }
    }

    return 0;
}