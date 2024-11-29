#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head1 = NULL;
struct Node* create(int k) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = k;
    newNode->next = newNode;
    return newNode;
}
void display(struct Node* head) {
    if (head == NULL) {
        printf("Circular Linked List is empty\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List- ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
void insertFront(struct Node** head, int k) {
    struct Node* newNode = create(k);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    }
    display(*head);
}
void insertEnd(struct Node** head, int k) {
    struct Node* newNode = create(k);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
    display(*head);
}
void insertIntermediate(struct Node** head, int k, int pos) {
    struct Node* newNode = create(k);
    if (pos == 1) {
        insertFront(head, k);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < pos - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }
    if (temp->next == *head && pos > 1) {
        printf("Position out of range\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    display(*head);
}
void deleteFront(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = *head;
    if ((*head)->next == *head) {
        printf("Node deleted %d\n", (*head)->data);
        free(*head);
        *head = NULL;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = (*head)->next;
        *head = (*head)->next;
        printf("Node deleted %d\n", temp->data);
        free(temp);
    }
    display(*head);
}
int main() {
    int choice, value, position;
    while (1) {
        printf("\nPress:\n");
        printf("1 to insert node at front\n");
        printf("2 to insert node at end\n");
        printf("3 to insert node at specific position\n");
        printf("4 to delete node from front\n");
        printf("9 to exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(&head1, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertEnd(&head1, value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &position);
                insertIntermediate(&head1, value, position);
                break;
            case 4:
                deleteFront(&head1);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
