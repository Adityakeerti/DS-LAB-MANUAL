#include <stdio.h>
#include <stdbool.h>

// Function to check if the binary tree satisfies max-heap property
bool isMaxHeap(int arr[], int n) {
    for (int i = 0; i <= (n - 2) / 2; i++) {
        // Left child index
        int left = 2 * i + 1;
        // Right child index
        int right = 2 * i + 2;

        // Check left child
        if (left < n && arr[i] < arr[left]) {
            return false;
        }
        // Check right child
        if (right < n && arr[i] < arr[right]) {
            return false;
        }
    }
    return true;
}

// Function to check if the binary tree is complete
bool isComplete(int arr[], int n) {
    bool foundNullChild = false;

    for (int i = 0; i < n; i++) {
        int left = 2 * i + 1; // Left child index
        int right = 2 * i + 2; // Right child index

        // If a child is missing, mark that all subsequent nodes must have no children
        if (left >= n) {
            foundNullChild = true;
        } else if (foundNullChild) {
            return false; // Non-complete structure
        }

        if (right >= n) {
            foundNullChild = true;
        } else if (foundNullChild) {
            return false; // Non-complete structure
        }
    }
    return true;
}

// Function to check if the binary tree satisfies heap properties
bool isHeap(int arr[], int n) {
    return isComplete(arr, n) && isMaxHeap(arr, n);
}

// Main function
int main() {
    int t;
    printf("Enter number of test cases: ");
    scanf("%d", &t);

    while (t--) {
        int n;
        printf("Enter size of binary tree: ");
        scanf("%d", &n);

        int arr[n];
        printf("Enter elements (level order): ");
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        // Check if the binary tree satisfies heap properties
        if (isHeap(arr, n)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
