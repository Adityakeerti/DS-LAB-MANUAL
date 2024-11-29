#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *newNode(int val) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Heap Overflow\n");
        return NULL;
    }
    temp->data = val;
    temp->next = NULL;
    return temp;
}

void insertAtEnd(Node **head, int val) {
    Node *temp = newNode(val);
    if (temp == NULL) {
        return; // Heap overflow check
    }

    if (*head == NULL) {
        *head = temp;
        return;
    }

    Node *itr = *head;
    while (itr->next) {
        itr = itr->next;
    }
    itr->next = temp;
}

void printList(Node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node *itr = head;
    while (itr) {
        printf("%d ", itr->data);
        itr = itr->next;
    }
    printf("\n");
}

void reverseList(Node **head) {
    Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

int main() {
    Node *head = NULL;
    int choice, val;

    printf("Press:\n1 to insert node\n2 to exit\n");

    while (1) {
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &val);
            insertAtEnd(&head, val);
        } else if (choice == 2) {
            break;
        } else {
            printf("Invalid option\n");
        }
    }

    printf("Original Linked List: ");
    printList(head);

    reverseList(&head);

    printf("Reversed Linked List: ");
    printList(head);

    return 0;
}
