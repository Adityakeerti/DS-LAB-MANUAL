    /*
    W2Q1. Given a matrix of size n X n, where every row and every column is sorted in increasing order.
    Write an algorithm and a program to find whether the given key element is present in the matrix
    or not. (Linear time complexity)
    NAME - ADITYAKEERTI
    SEC - K1
    COURSE - BTECH
    BRANCH - CSE
    */

    #include <stdio.h>

    int searchMatrix(int target, int n, int arr[50][50])
    {
        int i = 0, j = n - 1;
        while (i < n && j >= 0)
        {
            if (target == arr[i][j])
            {
                return 0;
            }
            else if (target > arr[i][j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return 1;
    }

    int main()
    {
        int n;
        printf("Enter size: ");
        scanf("%d", &n);
        int arr[50][50];
        printf("Enter 2d array elements: ");

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }

        int target;
        printf("Enter target:");
        scanf("%d", &target);

        if (searchMatrix(target, n, arr) == 0)
        {
            printf("Present");
        }
        else
        {
            printf("Not Present");
        }
    }