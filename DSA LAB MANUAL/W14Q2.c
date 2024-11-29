#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int rollNo;
    struct Node* next;
} Node;

void addEdge(Node* adjList[], int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->rollNo = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;
}

void displayAdjList(Node* adjList[], int n) {
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

int main() {
    int n = 4; // Number of students
    Node* adjList[4] = {NULL};

    // Adding edges
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 0);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 2, 1);
    addEdge(adjList, 3, 0);
    addEdge(adjList, 3, 1);

    printf("Adjacency List:\n");
    displayAdjList(adjList, n);

    return 0;
}
