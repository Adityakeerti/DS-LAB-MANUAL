    #include <stdio.h>
    #include <stdlib.h>

    // Definition of the tree node
    typedef struct TREENODE {
        int data;
        struct TREENODE* left;
        struct TREENODE* right;
    } treeNode;

    // Function to create a new node
    treeNode* create_node(int data) {
        treeNode* new_node = (treeNode*)malloc(sizeof(treeNode));
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    // Function to create a tree from an array representation
    treeNode* create_tree(int* arr, int size, int index) {
        if (index >= size || arr[index] == -1) {
            return NULL;
        }
        treeNode* node = create_node(arr[index]);
        node->left = create_tree(arr, size, 2 * index + 1);
        node->right = create_tree(arr, size, 2 * index + 2);
        return node;
    }

    // Function to insert a node into the binary tree
    treeNode* insert_node(treeNode* root, int data) {
        if (root == NULL) {
            return create_node(data);
        }
        if (data < root->data) {
            root->left = insert_node(root->left, data);
        } else {
            root->right = insert_node(root->right, data);
        }
        return root;
    }

    // Function to delete a node (non-recursive)
    treeNode* delete_node(treeNode* root, int data) {
        if (root == NULL) {
            return root;
        }

        if (data < root->data) {
            root->left = delete_node(root->left, data);
        } else if (data > root->data) {
            root->right = delete_node(root->right, data);
        } else {
            // Node found, now handle deletion cases
            if (root->left == NULL) {
                treeNode* temp = root->right;
                free(root);
                return temp;
            } else if (root->right == NULL) {
                treeNode* temp = root->left;
                free(root);
                return temp;
            }

            // Node with two children: get the in-order successor
            treeNode* temp = root->right;
            while (temp && temp->left != NULL) {
                temp = temp->left;
            }
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
        return root;
    }

    // Function to find the height of the tree
    int find_height(treeNode* root) {
        if (root == NULL) {
            return -1; // Height of an empty tree is -1
        }
        int left_height = find_height(root->left);
        int right_height = find_height(root->right);
        
        return 1 + (left_height > right_height ? left_height : right_height);
    }



    // Function to find the size (number of nodes) of the tree
    int find_size(treeNode* root) {
        if (root == NULL) {
            return 0;
        }
        return 1 + find_size(root->left) + find_size(root->right);
    }

    // Function to print the tree in level order for verification
    void print_level_order(treeNode* root) {
        if (root == NULL) {
            return;
        }
        treeNode* queue[100]; // Assuming tree has at most 100 nodes
        int front = 0, rear = 0;
        queue[rear++] = root;

        while (front < rear) {
            treeNode* temp = queue[front++];
            printf("%d ", temp->data);

            if (temp->left != NULL) {
                queue[rear++] = temp->left;
            }
            if (temp->right != NULL) {
                queue[rear++] = temp->right;
            }
        }
        printf("\n");
    }

    int main() {
        int size;
        printf("Enter size of array: ");
        scanf("%d", &size);

        int* arr = (int*)malloc(size * sizeof(int));
        printf("Enter array elements: ");
        for (int i = 0; i < size; i++) {
            scanf("%d", &arr[i]);
        }

        // Create the tree from the array representation
        treeNode* root = create_tree(arr, size, 0);

        int choice;
        do {
            printf("\nPress:\n1 to insert a node\n2 to delete a node\n3 to exit\n");
            scanf("%d", &choice);

            switch (choice) {
                case 1: {
                    int value;
                    printf("Enter value to insert: ");
                    scanf("%d", &value);
                    root = insert_node(root, value);
                    break;
                }
                case 2: {
                    int value;
                    printf("Enter value to delete: ");
                    scanf("%d", &value);
                    root = delete_node(root, value);
                    break;
                }
                case 3:
                    break;
                default:
                    printf("Invalid choice. Try again.\n");
            }
        } while (choice != 3);

        printf("\nTree contents (Level order): ");
        print_level_order(root);

        printf("Height = %d\n", find_height(root));
        printf("Size = %d\n", find_size(root));

        free(arr);
        return 0;
    }
