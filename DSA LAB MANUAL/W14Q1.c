#include <stdio.h>
#include <stdlib.h>

// Structure for Adjacency List Node
typedef struct Node {
    int rollNo;
    struct Node* next;
} Node;

// Function to add an edge to the adjacency list
void addEdge(Node* adjList[], int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->rollNo = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

// Function to display the adjacency matrix
void displayMatrix(int n, int matrix[n][n]) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to display the adjacency list
void displayAdjList(Node* adjList[], int n) {
    printf("Adjacency List:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d: ", i + 1);
        Node* temp = adjList[i];
        while (temp != NULL) {
            printf("%d ", temp->rollNo + 1);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to calculate space used by adjacency matrix
int calculateMatrixSpace(int n) {
    return n * n * sizeof(int); // Space for an n x n matrix
}

// Function to calculate space used by adjacency list
int calculateAdjListSpace(Node* adjList[], int n) {
    int space = 0;
    for (int i = 0; i < n; i++) {
        Node* temp = adjList[i];
        while (temp != NULL) {
            space += sizeof(Node); // Space for each node in the list
            temp = temp->next;
        }
    }
    space += n * sizeof(Node*); // Space for the array of pointers
    return space;
}

int main() {
    int n = 4; // Number of students

    // Adjacency Matrix
    int matrix[4][4] = {
        {0, 1, 0, 1},
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    // Adjacency List
    Node* adjList[4] = {NULL};
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 0);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 1);
    addEdge(adjList, 3, 0);
    addEdge(adjList, 3, 1);

    // Display representations
    displayMatrix(n, matrix);
    displayAdjList(adjList, n);

    // Calculate space
    int matrixSpace = calculateMatrixSpace(n);
    int adjListSpace = calculateAdjListSpace(adjList, n);

    printf("\nSpace used by Adjacency Matrix: %d bytes\n", matrixSpace);
    printf("Space used by Adjacency List: %d bytes\n", adjListSpace);

    // Compare space usage
    if (matrixSpace > adjListSpace) {
        printf("Adjacency List takes less space by %d bytes.\n", matrixSpace - adjListSpace);
    } else {
        printf("Adjacency Matrix takes less space by %d bytes.\n", adjListSpace - matrixSpace);
    }

    return 0;
}
