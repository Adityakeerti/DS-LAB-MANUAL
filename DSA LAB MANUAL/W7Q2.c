#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;          // 4 bytes
    struct Node *next; // 4 bytes
} Node;

Node *newNode(int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Heap Overflow");
        return temp;
    }
    temp->data = val;
    temp->next = NULL;
    return temp;
}

int isEmpty(Node **head)
{
    return *head == NULL;
}

void enqueue(Node **head, int val)
{
    Node *temp = newNode(val);
    if (*head == NULL)
    {
        *head = temp;
        return;
    }

    if (temp == NULL)
        return; // Heap overflow check
    Node *itr = *head;
    while (itr->next)
    {
        itr = itr->next;
    }
    itr->next = temp;
}

void printList(Node *head)
{
    if (isEmpty(&head))
    {
        printf("List is empty\n");
        return;
    }
    printf("Queue - ");
    Node *itr = head;
    while (itr)
    {
        printf("%d ", itr->data);
        itr = itr->next;
    }
    printf("\n");
}


void dequeue(Node **head)
{
    if (*head == NULL)
    {
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    printf("Node deleted - %d\n", temp->data);
    free(temp);
}



int sizeOfList(Node **head)
{
    Node *itr = *head;
    int size = 0;
    while (itr->next != NULL)
    {
        itr = itr->next;
        size++;
    }
    return size + 1;
}


int main()
{
    Node *head = NULL;

    int n, val, k;

    printf("\nPress:\n1 to enqueue\n2 to dequeue\n3 to calculate size\n4 to exit\n");

    while (n != 4)
    {
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            scanf("%d", &val);
            enqueue(&head, val);
            printList(head);
            break;
        case 2:
            dequeue(&head);
            printList(head);
            break;
        case 3:
            printf("Size = %d",sizeOfList(&head));
            break;

        default:
            break;
        }
    }

    return 0;
}