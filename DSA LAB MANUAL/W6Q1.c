#include <stdio.h>
#include <stdlib.h>
typedef struct queue
{
    int front, rear, *arr, size;
} sq;

void create(sq *q)
{
    printf("Enter size of queue: ");
    scanf("%d", &q->size);
    q->arr = (int *)malloc(q->size * sizeof(int));
    q->front = q->rear = -1;
}

void enque(sq *q, int val)
{
    if (q->rear == q->size - 1)
    {
        printf("Queue full\n");
        return;
    }
    if (q->front == -1)
    {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = val;
}

int dequeue(sq *q)
{
    if(q->front==-1||q->front>q->rear)
    {
        printf("Queue is empty\n");
        return -1;
    }
    int temp = q->arr[q->front];
    q->front++; 
    if(q->front>q->rear)
    {
        q->front = q->rear =-1;
    }
    return temp;
}

int isEmpty(sq *q)
{
    return (q->front == -1 || q->front>q->rear);
}

void display(sq q)
{
    if (isEmpty(&q))
    {
        printf("Stack Empty\n");
    }
    else
    {
        printf("Stack - ");
        // Print from rear to front to simulate stack behavior (LIFO)
        for (int i = q.rear; i >= q.front; i--)
        {
            printf("%d ", q.arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    sq q1,q2;
    create(&q1);
    create(&q2);
    int choice=-1,val;
    printf("Press:\n1 to push\n2 to pop\n3 to exit\n");
    while (choice!=3)
    {
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:

            scanf("%d",&val);
            enque(&q2,val); //push in q2

            //q1 to q2
            while (!isEmpty(&q1))
            {
                enque(&q2,dequeue(&q1));
            }

            //swap q1 and q2
            sq temp = q1;
            q1 = q2;
            q2 = temp;
            display(q1);
            break;
        case 2:
            if (!isEmpty(&q1))
            {
                printf("Element poppped from stack - %d\n",dequeue(&q1));
            }
            else{
                printf("Stack Empty\n");
            }
            display(q1);
            break;
        }
        
    }
    

    return 0;
}