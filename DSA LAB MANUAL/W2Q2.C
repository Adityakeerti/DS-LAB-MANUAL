/*
W2Q2.Given a boolean matrix (contains only 0 and 1) of size m X n where each row is sorted, write an
 algorithm and a program to find which row has maximum number of 1's. (Linear time
 complexity)
 NAME - ADITYAKEERTI
 SEC - K1
 COURSE - BTECH
 BRANCH - CSE
*/
#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
        
    }
    int col =n-1; 
    int rowWithMaxOnes = -1;

    for (int i = 0; i < m; i++)
    {
        
        while (col >= 0 && arr[i][col] == 1)
        {
            rowWithMaxOnes = i;  
            col--;  
        }
    }

   

    if (rowWithMaxOnes != -1)
    {
        printf("Row - %d", rowWithMaxOnes + 1);  
    }
    else
    {
        printf("Not Present");
    }

    return 0;
}
   