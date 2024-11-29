/*
 Q2. Given an unsorted array of integers and two numbers a and b. Design an algorithm and write a
 program to find minimum distance between a and b in this array. Minimum distance between any
 two numbers a and b present in array is the minimum difference between their indices.
 NAME - ADITYAKEERTI
 SEC - K1
 COURSE - BTECH
 BRANCH - CSE
 */

#include <stdio.h>
int UpdateMinimum(int ans, int min)
{
    if (ans < min)
    {
        return ans;
    }
    else
    {
        return min;
    }
}
int abs_val(int y)
{
    if (y < 0)
        return (y * -1);
    else
        return (y);
}
int main()
{
    int t;
    printf("Enter number of test cases: ");

    scanf("%d", &t);
    while (t > 0)
    {
        int n, a, b;
        printf("\nEnter n: ");
        scanf("%d", &n);
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        // 0 1 5 5 3 2 1 a=5 b=1                                 //              0  1  2  3  4  5  6

        printf("Enter a and b: ");                               //       arr = [5, 2, 3, 4, 1, 2, 3]   a = 1 | b = 2
        scanf("%d%d", &a, &b);
        int start = -1, end = -1, min = 0, ans = n+1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == a)
            {
                start = i;
            }
            else if (arr[i] == b)
            {
                end = i;
            }

            if (start != -1 && end != -1)
            {
                min = abs_val(start - end);
                ans = UpdateMinimum(ans, min);
            }
        }

        if (ans != n+1)
        {

            printf("%d", ans);
        }

        t--;
    }

    return 0;
}