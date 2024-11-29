#include <stdio.h>

// Function to heapify a subtree rooted at index i
void heapify(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // Check if left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

// Function to build a max heap
void buildMaxHeap(int arr[], int n) {
    // Start from last non-leaf node and heapify each node
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Function to find the Kth largest element
int findKthLargest(int arr[], int n, int k) {
    buildMaxHeap(arr, n); // Build the max heap

    for (int i = n - 1; i > n - k; i--) {
        // Swap the root (largest) with the last element in heap
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Reduce the heap size and heapify root
        heapify(arr, i, 0);
    }

    // After K extractions, the root is the Kth largest element
    return arr[0];
}

int main() {
    int n, k;

    // Input size of the array
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input value of K
    printf("Enter the value of K: ");
    scanf("%d", &k);

    // Find and print the Kth largest element
    int result = findKthLargest(arr, n, k);
    printf("K = %d, largest element: %d\n", k, result);

    return 0;
}
