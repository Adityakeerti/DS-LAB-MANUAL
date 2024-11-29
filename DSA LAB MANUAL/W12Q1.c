#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a node in the binary tree
struct treenode {
    int data;
    struct treenode *left;
    struct treenode *right;
};

// Function declaration for minnode
struct treenode *minnode(struct treenode *node);

// Create a new node
struct treenode *newnode(int data) {
    struct treenode *temp = (struct treenode *)malloc(sizeof(struct treenode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Insert a node in the BST
struct treenode *insert(struct treenode *root, int data) {
    if (root == NULL) {
        return newnode(data);
    }
    if (data > root->data) {
        root->right = insert(root->right, data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    }
    return root;
}

// Delete a node from the BST
struct treenode *delete(struct treenode *root, int data) {
    if (root == NULL) {
        return root;
    }
    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL) {
            struct treenode *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct treenode *temp = root->left;
            free(root);
            return temp;
        }
        struct treenode *temp = minnode(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    return root;
}

// Find the node with the smallest value
struct treenode *minnode(struct treenode *node) {
    struct treenode *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Calculate the height of the tree
int findHeight(struct treenode *root) {
    if (root == NULL) return 0;
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return fmax(leftHeight, rightHeight);
}

// Print nodes at a given level
void printGivenLevel(struct treenode *root, int level) {
    if (root == NULL) return;
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

// Perform level-order traversal (recursive)
void levelOrder(struct treenode *root) {
    int height = findHeight(root);
    for (int i = 1; i <= height; i++) {
        printGivenLevel(root, i);
    }
}

// Calculate the depth of the tree
int findDepth(struct treenode *root, int data, int depth) {
    if (root == NULL) return -1; // Node not found
    if (root->data == data) return depth; // Node found

    if (data < root->data) {
        return findDepth(root->left, data, depth + 1);
    } else {
        return findDepth(root->right, data, depth + 1);
    }
}

// Search for a key in the BST
int search(struct treenode *root, int key) {
    if (root == NULL) return 0;
    if (root->data == key) return 1;
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}

// Main function
int main() {
    struct treenode *root = NULL;
    int size, data, choice, key;

    // Input: size of the array
    printf("Enter size of tree array: ");
    scanf("%d", &size);

    // Input: tree elements in array form
    printf("Enter tree elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &data);
        if (data != -1) {
            root = insert(root, data);
        }
    }

    do {
        printf("\nPress:\n1 to insert a node\n2 to delete a node\n3 to search a key\n4 to exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter node to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                printf("Enter node to delete: ");
                scanf("%d", &data);
                root = delete(root, data);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(root, key)) {
                    printf("%d - present\n", key);
                } else {
                    printf("Not present\n");
                }
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

        if (choice != 4) {
            printf("BST: ");
            levelOrder(root);
            printf("\nHeight = %d\n", findHeight(root));
            printf("Depth = %d\n", findDepth(root, 7, 1)); // Depth of node `7` is calculated here
        }

    } while (choice != 4);

    return 0;
}
