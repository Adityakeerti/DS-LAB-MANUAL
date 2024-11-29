#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
struct Node* create(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = newNode; 
    return newNode;
}
void insertEnd(struct Node** head, int value) 
{
    struct Node* newNode = create(value);
    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        struct Node* temp = *head;
        while (temp->next != *head) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}
void display(struct Node* head) 
{
    if (head == NULL) return;
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
struct Node* concatenateLists(struct Node* head1, struct Node* head2) 
{
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    while (temp1->next != head1) 
    {
        temp1 = temp1->next;
    }

    while (temp2->next != head2) 
    {
        temp2 = temp2->next;
    }
    temp1->next = head2;

    temp2->next = head1;

    return head1;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    int choice, value;

    printf("Press:\n");
    printf("1 to insert nodet\n");
    printf("2 to exit\n");

    while (1) {
        scanf("%d", &choice);
        if (choice == 1) 
        {
            scanf("%d", &value);
            insertEnd(&head1, value); 
        }
         else if (choice == 2) 
         {
            printf("First circular linked list: ");
            display(head1);
            printf("\n");
            break;
        }
    }

    printf("Press:\n");
    printf("1 to insert node\n");
    printf("2 to exit \n");
    while (1) 
    {
        scanf("%d", &choice);
        if (choice == 1) 
        {
            scanf("%d", &value);
            insertEnd(&head2, value); 
        }
         else if (choice == 2) 
         {
            printf("Second circular linked list: ");
            display(head2);
            printf("\n");
            break;
        }
    }
    struct Node* concatenatedList = concatenateLists(head1, head2);

    printf("Final Concatenated linked list: ");
    display(concatenatedList);
    printf("\n");

    return 0;
}