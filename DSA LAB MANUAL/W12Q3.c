#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct treenode {
    int data;
    struct treenode *left;
    struct treenode *right;
};

// Create a new node
struct treenode* newnode(int data) {
    struct treenode* temp = (struct treenode*)malloc(sizeof(struct treenode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Insert a node into the BST
struct treenode* insert(struct treenode* root, int data) {
    if (root == NULL) {
        return newnode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Pre-order traversal to print the BST
void printPreOrder(struct treenode* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

// Level-order traversal to find the level with the maximum number of nodes
void findMaxNodesLevel(struct treenode* root, int* maxLevel, int* maxNodes) {
    if (root == NULL) return;

    int currentLevel = 1;
    int queueSize = 1000;  // Arbitrary size for a simple queue implementation
    struct treenode* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        int nodeCount = rear - front;
        if (nodeCount > *maxNodes) {
            *maxNodes = nodeCount;
            *maxLevel = currentLevel;
        }

        for (int i = 0; i < nodeCount; i++) {
            struct treenode* current = queue[front++];
            if (current->left != NULL) {
                queue[rear++] = current->left;
            }
            if (current->right != NULL) {
                queue[rear++] = current->right;
            }
        }
        currentLevel++;
    }
}

// Main function
int main() {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter tree elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Build the BST from the input array
    struct treenode* root = NULL;
    for (int i = 0; i < size; i++) {
        if (arr[i] != -1) { // Insert only non-`-1` values
            root = insert(root, arr[i]);
        }
    }

    // Print the BST in pre-order
    printf("BST: ");
    printPreOrder(root);
    printf("\n");

    // Find the level with the maximum number of nodes
    int maxLevel = 0, maxNodes = 0;
    findMaxNodesLevel(root, &maxLevel, &maxNodes);

    // Print the result
    printf("Level %d has %d nodes\n", maxLevel, maxNodes);

    return 0;
}
