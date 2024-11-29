#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* create(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode; 
    return newNode;
}
void insertEnd(struct Node** head, int value) {
    struct Node* newNode = create(value);
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
}
void display(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
void splitList(struct Node* head, int k) {
    if (head == NULL) return;

    struct Node* temp = head;
    struct Node* head1 = head;
    struct Node* head2 = NULL;

    for (int i = 1; i < k && temp->next != head; i++) {
        temp = temp->next;
    }

    head2 = temp->next; 
    temp->next = head1;

    struct Node* temp2 = head2;
    while (temp2->next != head) {
        temp2 = temp2->next;
    }
    temp2->next = head2; 

    printf("First part of list : ");
    display(head1);
    printf("\nSecond part of list : ");
    display(head2);
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, splitPos;

    printf("Press:\n");
    printf("1 to insert\n");
    printf("2 to exit\n");

    while (1) {
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &value);
            insertEnd(&head, value);
        } else if (choice == 2) {
            printf("Original List : ");
            display(head);
            printf("\n");
            break;
        }
    }
    scanf("%d", &splitPos);
    splitList(head, splitPos);
    return 0;
}
