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

void findNthFromEnd(Node *head, int n) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node *itr1 = head;
    Node *itr2 = head;

    // Move itr2 `n` steps ahead
    for (int i = 0; i < n; i++) {
        if (itr2 == NULL) {
            printf("Position out of bounds\n");
            return;
        }
        itr2 = itr2->next;
    }

    // Move both pointers until itr2 reaches the end
    while (itr2 != NULL) {
        itr1 = itr1->next;
        itr2 = itr2->next;
    }

    printf("Value at position %d from end: %d\n", n, itr1->data);
}

int main() {
    Node *head = NULL;
    int choice, val, n;

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

    printf("Enter value n: ");
    scanf("%d", &n);

    printf("Linked List: ");
    printList(head);
    findNthFromEnd(head, n);

    return 0;
}
