/*
 Q1.Given an array of integers, write an algorithm and a program to left rotate the array by specific
 number of elements.
 NAME - ADITYAKEERTI
 SEC - K1
 COURSE - BTECH
 BRANCH - CSE
*/

#include <stdio.h>
int *reverse(int *ptr, int start, int end)
{
    int temp;
    while (start < end)
    {
        // Swap elements
        temp = ptr[start];
        ptr[start] = ptr[end];
        ptr[end] = temp;

        // Move towards the center
        start++;
        end--;
    }
    return ptr;
}

int *rotate(int *ptr, int k, int n)
{
    if (k > n)
    {
        k = k % n;
    }
    reverse(ptr, 0, k - 1);
    reverse(ptr, k, n-1);
    reverse(ptr, 0, n-1);
    return ptr;
}

int main()
{
    int t;
    printf("Enter number of test cases: ");

    scanf("%d", &t);
    while (t > 0)
    {
        int n, k;
        printf("\nEnter n: ");
        scanf("%d", &n);
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int *ptr = &arr[0];

        printf("Enter k:");
        scanf("%d", &k);
        int temp[k];

        rotate(ptr, k, n);
        for (int i = 0; i < n; i++)
        {
            printf("%d ", ptr[i]);
        }

        t--;
    }

    return 0;
}