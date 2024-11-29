/*
Q20-Write an algorithm and a program to implement queue using linked list. The program should implement following stack operations:
a) Create()
b) EnQueue()
c) DeQueue()
d) IsEmpty()
e) Size()
NAME: PAWAN RAJ PRAJAPATI
SECTION: L1
ROLL NO: 12
COURSE: BTech CSE
*/
// SOURCE CODE:

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
struct snode
{
    int info;
    struct snode *next;
};

// Function to enqueue an element into the queue
struct snode *enqueue(struct snode *top)
{
    struct snode *temp = (struct snode *)malloc(sizeof(struct snode));
    struct snode *p1 = top;

    if (temp == NULL)
    {
        printf("Memory not allocated.\n");
        return top;
    }
    scanf("%d", &(temp->info));
    temp->next = NULL;

    if (p1 == NULL)
    {
        // If the queue is empty
        top = temp;
    }
    else
    {
        // Traverse to the end of the queue
        while (p1->next != NULL)
        {
            p1 = p1->next;
        }
        p1->next = temp;
    }
    return top;
}

// Function to dequeue an element from the queue
struct snode *dequeue(struct snode *top)
{
    if (top == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("%d is dequeued.\n", top->info);
        struct snode *temp = top;
        top = top->next;
        free(temp);
    }
    return top;
}

// Function to calculate the size of the queue
int size(struct snode *top)
{
    int count = 0;
    struct snode *p1 = top;

    while (p1 != NULL)
    {
        count++;
        p1 = p1->next;
    }
    return count;
}

// Function to display the queue
void display(struct snode *top)
{
    struct snode *p1 = top;
    if (top == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue: ");
        while (p1 != NULL)
        {
            printf("%d ", p1->info);
            p1 = p1->next;
        }
        printf("\n");
    }
}

// Main function
void main()
{
    int choice;
    printf("Press:\n");
    printf("1 to enqueue\n");
    printf("2 to dequeue\n");
    printf("3 to calculate size\n");
    printf("4 to exit\n");
    struct snode *top = NULL;

    do
    {

        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            top = enqueue(top);
            display(top);
            break;
        case 2:
            top = dequeue(top);
            display(top);
            break;
        case 3:
            printf("Size = %d\n", size(top));
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}
