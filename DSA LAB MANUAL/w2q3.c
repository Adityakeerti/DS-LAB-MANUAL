/*
 W2Q3. Given a matrix of size n X n containing positive integers, write an algorithm and a program to
 rotate the elements of matrix in clockwise direction.
 NAME - ADITYAKEERTI
 SEC - K1
 COURSE - BTECH
 BRANCH - CSE
*/
#include <stdio.h>

void rotateMatrix(int n, int matrix[n][n]) {
    int temp[n][n];
    
    // Copy the matrix to a temporary matrix with the desired rotation
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[i][j] = matrix[i][j];
        }
    }
    
    // Rotate the outermost layer
    for (int i = 0; i < n - 1; i++) {
        matrix[0][i + 1] = temp[0][i];
    }
    for (int i = 0; i < n - 1; i++) {
        matrix[i + 1][n - 1] = temp[i][n - 1];
    }
    for (int i = n - 1; i > 0; i--) {
        matrix[n - 1][i - 1] = temp[n - 1][i];
    }
    for (int i = n - 1; i > 0; i--) {
        matrix[i - 1][0] = temp[i][0];
    }
    
    // Rotate the inner layer if n > 2
    if (n > 2) {
        for (int i = 1; i < n - 2; i++) {
            matrix[1][i + 1] = temp[1][i];
        }
        for (int i = 1; i < n - 2; i++) {
            matrix[i + 1][n - 2] = temp[i][n - 2];
        }
        for (int i = n - 2; i > 1; i--) {
            matrix[n - 2][i - 1] = temp[n - 2][i];
        }
        for (int i = n - 2; i > 1; i--) {
            matrix[i - 1][1] = temp[i][1];
        }
    }
}

void printMatrix(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n;
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);
    int matrix[n][n];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);}  }
 rotateMatrix(n, matrix);

    printf("Rotated matrix:\n");
    printMatrix(n, matrix);

    return 0;
}n