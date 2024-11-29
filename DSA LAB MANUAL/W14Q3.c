#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 4

// Function to check if two students are friends
bool areFriends(int matrix[MAX][MAX], int a, int b) {
    return matrix[a - 1][b - 1] == 1;
}

// Function to find mutual friends
void findMutualFriends(int matrix[MAX][MAX], int a, int b) {
    printf("Mutual Friends of %d and %d: ", a, b);
    for (int i = 0; i < MAX; i++) {
        if (matrix[a - 1][i] == 1 && matrix[b - 1][i] == 1) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

// Function to find students who are not friends with both
void findNonFriends(int matrix[MAX][MAX], int a, int b) {
    printf("Students not friends with %d and %d: ", a, b);
    for (int i = 0; i < MAX; i++) {
        if (matrix[a - 1][i] == 0 && matrix[b - 1][i] == 0) {
            printf("%d ", i + 1);
        }
    }
    printf("\n");
}

int main() {
    int matrix[MAX][MAX] = {
        {0, 1, 0, 1},
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    int roll1, roll2;
    printf("Enter two roll numbers (1-%d): ", MAX);
    scanf("%d %d", &roll1, &roll2);

    if (areFriends(matrix, roll1, roll2)) {
        printf("%d and %d are friends.\n", roll1, roll2);
        findMutualFriends(matrix, roll1, roll2);
    } else {
        printf("%d and %d are not friends.\n", roll1, roll2);
    }

    findNonFriends(matrix, roll1, roll2);

    return 0;
}
