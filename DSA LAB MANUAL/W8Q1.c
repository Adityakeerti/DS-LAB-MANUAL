#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

Node *newNode(int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Heap Overflow\n");
        return temp;
    }
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
}

void insertAtBegin(Node **head, int val)
{
    Node *temp = newNode(val);
    if (temp == NULL)
    {
        printf("Memory allocation failed");
        return;
    }

    temp->data = val;
    if (*head != NULL)
    {
        temp->next = *head;
        (*head)->prev = temp;
    }
    temp->prev = NULL;
    *head = temp;
}

void insertAtEnd(Node **head, int val)
{
    Node *temp = newNode(val);
    if (temp == NULL)
        return; // Heap overflow check
    if (*head == NULL)
    {
        // List is empty, so the new node is the head
        *head = temp;
        temp->prev = NULL; // The previous pointer of the new node is NULL as it’s the only node
        return;
    }
    Node *itr = *head;
    while (itr->next != NULL)
    {
        itr = itr->next;
    }
    temp->data = val;
    itr->next = temp;
    temp->next = NULL;
    temp->prev = itr;
}
void insertIntermediate(Node **head, int val, int pos)
{
    int i = 1;
    Node *itr = *head;
    Node *temp = newNode(val);
    while (itr->next)
    {
        if (i == pos)
        {
            break;
        }
        i++;
        itr = itr->next;
    }
    temp->next = itr;
    itr->prev->next = temp;
    temp->prev = itr->prev;
    itr->prev = temp;
}

void delFromBegin(Node **head)
{
    if (*head == NULL)
    {
        printf("List is already empty\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    (*head)->prev = NULL;
    printf("Node deleted - %d\n", temp->data);
    free(temp);
}

void delFromEnd(Node **head)
{
    if (*head == NULL)
    {
        printf("List is already empty\n");
        return;
    }
    Node *itr = *head;
    Node *temp;
    if (itr->next == NULL)
    {
        free(itr);
        *head = NULL;
        return;
    }

    while (itr->next->next)
    {
        itr = itr->next;
    }
    temp = itr->next;
    printf("Node deleted - %d\n", temp->data);
    free(temp);
    itr->next = NULL;
}

void delIntermediate(Node **head, int pos)
{
    Node *itr = *head;
    Node *temp;
    int i = 1;
    while (itr->next)
    {
        if (i == pos)
        {
            break;
        }
        itr = itr->next;
        i++;
    }
    itr->prev->next = itr->next;
    itr->next->prev = itr->prev;
    temp = itr;
    free(temp);
}

void displayList(Node *head)
{
    printf("Double Linked List - ");
    Node *itr = head;
    while (itr != NULL)
    {
        printf("%d ", itr->data);
        itr = itr->next;
    }
    printf("\n");
}

int isEmpty(Node **head)
{
    return (*head) == NULL;
}

int size(Node **head)
{
    Node *itr = *head;
    int size=1;
    while (itr)
    {
        size++;
        itr=itr->next;
    }
    return size;
}

int middle(Node **head)
{
    Node *s = *head, *f = *head;
    while (f && f->next)
    {
        s = s->next;
        f = f->next->next;
        if (f->next->next == NULL)
        {
            break;
        }
    }
    return s->data;
}

int main()
{
    Node *head = NULL;
    int choice = 0, val, pos;

    printf("\nPress:\n1 insert node at front\n2 insert node at end\n3 insert node at specific position\n4 delete node from front\n5 delete node from end\n6 delete node from specific position\n7 find size of linked list\n8 find middle element of the list\n9 exit\n");

    while (choice != 9)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &val);
            insertAtBegin(&head, val);
            displayList(head);
            break;
        case 2:
            scanf("%d", &val);
            insertAtEnd(&head, val);
            displayList(head);
            break;
        case 3:
            printf("Value and Position: ");
            scanf("%d %d", val, pos);
            insertIntermediate(&head, val, pos);
            displayList(head);
            break;
        case 4:
            delFromBegin(&head);
            displayList(head);
            break;
        case 5:
            delFromEnd(&head);
            displayList(head);
            break;
        case 6:
            break;
        case 7:
            printf("%d", middle(&head));
            break;
        default:
            break;
        }
    }
}
