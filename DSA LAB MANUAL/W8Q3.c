#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int info;
    struct node *next;
    struct node *prev;
} node;

// Function to create a new node
node *createNode(int info) {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Heap Overflow\n");
        exit(1);
    }
    newNode->info = info;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert an element at the end of the doubly linked list
void insertEnd(node **head, int info) {
    node *newNode = createNode(info);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void removeDuplicates(node *head) {
    node *current = head;
    while (current != NULL) {
        node *runner = current->next;
        while (runner != NULL) {
            if (runner->info == current->info) {
                node *duplicate = runner;
                runner = runner->next;
                if (duplicate->prev != NULL) {
                    duplicate->prev->next = duplicate->next;
                }
                if (duplicate->next != NULL) {
                    duplicate->next->prev = duplicate->prev;
                }
                free(duplicate);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
}


// Function to display the doubly linked list
void displayList(node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->info);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    node *head = NULL;
    int choice, info;

    printf("Press:\n1 to insert element to linked list\n2 to exit\n");
    while (1) {
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            scanf("%d", &info);
            insertEnd(&head, info);
            break;
        case 2:
            printf("Doubly Linked List: ");
            displayList(head);
            removeDuplicates(head);
            printf("Doubly Linked List after duplicate removal: ");
            displayList(head);
            return 0;
        default:
            printf("Invalid choice, please try again.\n");
        }
    }
}
