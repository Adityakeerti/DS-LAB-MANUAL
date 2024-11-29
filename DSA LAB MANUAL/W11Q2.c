#include<stdio.h>
#include<stdlib.h>

// Tree node structure
struct treenode {
    int data;
    struct treenode *left;
    struct treenode *right;
};

// Function to create a new node
struct treenode* newnode(int data) {
    if (data == -1) // Handle null nodes represented by -1
        return NULL;
    struct treenode *temp = (struct treenode*)malloc(sizeof(struct treenode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to build the tree from an array representation
struct treenode* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1) // If index out of bounds or null node
        return NULL;

    struct treenode *root = newnode(arr[i]);
    root->left = buildTree(arr, n, 2 * i + 1);  // Left child index
    root->right = buildTree(arr, n, 2 * i + 2); // Right child index
    return root;
}

// Traversal functions
void inorder(struct treenode *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct treenode *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

void preorder(struct treenode *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Main function
int main() {
    int n;
    printf("Enter the size: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Build the tree
    struct treenode *root = buildTree(arr, n, 0);

    // Perform and display traversals
    printf("Inorder : ");
    inorder(root);
    printf("\n");

    printf("Postorder : ");
    postorder(root);
    printf("\n");

    printf("Preorder : ");
    preorder(root);
    printf("\n");

    return 0;
}
