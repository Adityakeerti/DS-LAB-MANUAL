/*
 Q3. Given an array of nonnegative integers, where all numbers occur even number of times except
 one number which occurs odd number of times. Write an algorithm and a program to find this
 number. (Time complexity = O(n))
*/

#include <stdio.h>
int main()
{
    int t;
    printf("Enter number of test cases: ");

    scanf("%d", &t);
    while (t > 0)
    {
        int n;
        printf("\nEnter n: ");
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        int oddNo = 0;
        for (int i = 0; i < n; i++)
        {
            oddNo ^= arr[i];
        }

        printf("%d", oddNo);

        t--;
    }

    return 0;
}

