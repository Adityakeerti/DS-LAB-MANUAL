#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *newnode(int data)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        return temp;
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertAtEnd(struct Node **head, int val)
{
    struct Node *temp = newnode(val);
    if (*head == NULL)
    {
        *head = temp;
        return;
    }
    struct Node *itr = *head;
    while (itr->next != NULL)
    {
        itr = itr->next;
    }
    itr->next = temp;
}

void splitList(struct Node *head, struct Node **oddList, struct Node **evenList)
{
    int position = 1; // To track the position of the node
    while (head != NULL)
    {
        if (position % 2 == 1)
        {
            insertAtEnd(oddList, head->data);
        }
        else
        {
            insertAtEnd(evenList, head->data);
        }
        head = head->next;
        position++;
    }
}

void display(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Node *head = NULL;
    struct Node *oddList = NULL;
    struct Node *evenList = NULL;
    int choice, value;

    // Input loop
    while (1)
    {
        printf("1 to insert node\n2 to exit\n ");
        scanf("%d", &choice);
        if (choice == 2)
            break;
        if (choice == 1)
        {
            printf("Enter value to insert: ");
            scanf("%d", &value);
            insertAtEnd(&head, value);
        }
    }

    // Display the original list
    printf("Original List: ");
    display(head);

    // Split the list into odd and even numbered nodes
    splitList(head, &oddList, &evenList);

    // Display the odd and even lists
    printf("Odd numbered nodes list: ");
    display(oddList);

    printf("Even numbered nodes list: ");
    display(evenList);

    return 0;
}
