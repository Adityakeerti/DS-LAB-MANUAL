#include <stdio.h>
#include <stdlib.h>

// Define the structure for a priority queue (heap)
struct PriorityQueue {
    int *arr;
    int size;
    int capacity;
};

// Create a new priority queue
struct PriorityQueue* create(int capacity) {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->arr = (int*)malloc(capacity * sizeof(int));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

// Resize the heap if needed
void resizeHeap(struct PriorityQueue* pq) {
    pq->capacity *= 2;
    pq->arr = (int*)realloc(pq->arr, pq->capacity * sizeof(int));
}

// Swap two elements in the array
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble up to maintain the max-heap property
void bubbleUp(struct PriorityQueue* pq, int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (pq->arr[index] > pq->arr[parentIndex]) {
            swap(&pq->arr[index], &pq->arr[parentIndex]);
            index = parentIndex;
        } else {
            break;
        }
    }
}

// Insert a new element into the priority queue
void insert(struct PriorityQueue* pq, int value) {
    if (pq->size == pq->capacity) {
        resizeHeap(pq); // Expand heap dynamically
    }
    pq->arr[pq->size] = value;
    pq->size++;
    bubbleUp(pq, pq->size - 1);
}

// Get the highest priority element (root)
int getHighestPriority(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty!\n");
        return -1;
    }
    return pq->arr[0];
}

// Bubble down to maintain the max-heap property
void bubbleDown(struct PriorityQueue* pq, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int largest = index;

    if (leftChild < pq->size && pq->arr[leftChild] > pq->arr[largest]) {
        largest = leftChild;
    }
    if (rightChild < pq->size && pq->arr[rightChild] > pq->arr[largest]) {
        largest = rightChild;
    }
    if (largest != index) {
        swap(&pq->arr[index], &pq->arr[largest]);
        bubbleDown(pq, largest);
    }
}

// Delete the highest priority element (root)
int deleteHighestPriority(struct PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty!\n");
        return -1;
    }
    int root = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    bubbleDown(pq, 0);
    return root;
}

// Print level order traversal of the priority queue
void printLevelOrder(struct PriorityQueue* pq) {
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->arr[i]);
    }
    printf("\n");
}

// Free memory allocated for the heap
void freePriorityQueue(struct PriorityQueue* pq) {
    free(pq->arr);
    free(pq);
}

// Main function to test the priority queue
int main() {
    int size;
    printf("Enter size of the priority queue: ");
    scanf("%d", &size);

    struct PriorityQueue* pq = create(size);
    printf("Enter the priorities of the elements: ");
    for (int i = 0; i < size; i++) {
        int value;
        scanf("%d", &value);
        insert(pq, value);
    }

    // Print initial level order traversal
    printf("Initial Priority Queue: ");
    printLevelOrder(pq);
    printf("Max Priority: %d\n", getHighestPriority(pq));

    int choice;
    do {
        printf("Press:\n1 to insert node\n2 to delete node\n3 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int value;
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(pq, value);
                printf("Updated Priority Queue: ");
                printLevelOrder(pq);
                break;
            }
            case 2: {
                int deletedValue = deleteHighestPriority(pq);
                if (deletedValue != -1) {
                    printf("Deleted value: %d\n", deletedValue);
                    printf("Updated Priority Queue: ");
                    printLevelOrder(pq);
                }
                break;
            }
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    freePriorityQueue(pq); // Free memory
    return 0;
}
