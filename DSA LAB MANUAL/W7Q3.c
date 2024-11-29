#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *newNode(int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Heap Overflow\n");
        return NULL;
    }
    temp->data = val;
    temp->next = NULL;
    return temp;
}

int isEmpty(Node *head)
{
    return head == NULL;
}

void push(Node **head, int val)
{
    Node *temp = newNode(val);
    if (temp == NULL)
    {
        printf("Error: Unable to allocate memory for node\n");
        return;
    }
    
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        Node *itr = *head;
        while (itr->next != NULL)
        {
            itr = itr->next;
        }
        itr->next = temp;
    }
}

void printList(Node *head)
{
    if (head == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack - ");
    Node *itr = head;
    while (itr)
    {
        printf("%d ", itr->data);
        itr = itr->next;
    }
    printf("\n");
}

void pop(Node **head)
{
    if (*head == NULL)
    {
        printf("Stack is empty, nothing to pop\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    printf("Node deleted - %d\n", temp->data);
    free(temp);
}

int sizeOfList(Node *head)
{
    int size = 0;
    while (head)
    {
        size++;
        head = head->next;
    }
    return size;
}

int main()
{
    Node *head = NULL;

    int n = 0, val;

    printf("\nPress:\n1 to push\n2 to pop\n3 to calculate size\n4 to exit\n");

    while (n != 4)
    {
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            scanf("%d", &val);
            push(&head, val);
            printList(head);
            break;
        case 2:
            pop(&head);
            printList(head);
            break;
        case 3:
            printf("Size = %d\n", sizeOfList(head));
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option. Try again.\n");
            break;
        }
    }

    return 0;
}
