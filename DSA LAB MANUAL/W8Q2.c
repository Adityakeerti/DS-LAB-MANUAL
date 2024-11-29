#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
typedef struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* newNode(int val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Heap Overflow\n");
        return NULL;
    }
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

// Function to insert a node at the end of the doubly linked list
void insert(Node** head, int val) {
    Node* temp = newNode(val);
    if (temp == NULL)
        return; // Heap overflow check

    if (*head == NULL) {
        *head = temp; // First node becomes the head
        return;
    }

    Node* itr = *head;
    while (itr->next != NULL) {
        itr = itr->next;
    }

    itr->next = temp;
    temp->prev = itr;
}

// Function to display the doubly linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* itr = head;
    while (itr != NULL) {
        printf("%d ", itr->data);
        itr = itr->next;
    }
    printf("\n");
}

// Function to reverse the doubly linked list
void reverse(Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to reverse.\n");
        return;
    }

    Node* current = *head;
    Node* temp = NULL;

    // Swap next and prev pointers for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Move to the next node in the original sequence
    }

    // Update the head pointer to point to the new head
    if (temp != NULL) {
        *head = temp->prev;
    }
}

// Main function
int main() {
    Node* head = NULL;
    int choice = 0, val;

    printf("\nPress:\n1 to insert element into the linked list\n2 to exit\n");

    while (choice != 2) {
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            scanf("%d", &val);
            insert(&head, val);
            break;
        case 2:
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Doubly Linked List: ");
    displayList(head);

    printf("Reversed Doubly Linked List: ");
    reverse(&head);
    displayList(head);

    return 0;
}
