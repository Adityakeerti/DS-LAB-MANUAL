#include <stdio.h>
#include <stdlib.h>
typedef struct cir_queue
{
    int front, rear, size, *arr;
} cq;

void create(cq *q)
{
    printf("Enter size of queue: ");
    scanf("%d", &q->size);
    q->front = q->rear = -1;
    q->arr = (int *)malloc(q->size * (sizeof(int)));
}
int isFull(cq *q)
{
    return ((q->rear + 1) % q->size == q->front);
}

int isEmpty(cq *q)
{
    return (q->front == -1);
}

void enqueue(cq *q, int val)
{
    if (isFull(q))
    {
        printf("Circular Queue is full");
        return;
    }
    if (isEmpty(q))
    {
        q->front = q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
    }
    q->arr[q->rear] = val;
}

int deque(cq *q)
{
    if (isEmpty(q))
    {
        printf("queue is empty\n");
        return -1;
    }
    else
    {
        int temp = q->arr[q->front];
        if (q->front == q->rear)
        {
            q->front = q->rear = -1;
        }
        else
        {
            q->front = (q->front + 1) % q->size;
        }
        return temp;
    }
}

int display(cq *q)
{
    if (isEmpty(q))
    {
        printf("queue is empty\n");
    }
    printf("Queue elements: ");
    int i = q->front;
    while (i != q->rear)
    {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("%d\n", q->arr[q->rear]);
}

int findFront(cq *q)
{
    return q->arr[q->front];
}
int findRear(cq *q)
{
    return q->arr[q->rear];
}

int main()
{
    int choice=-1, val, front, rear;
    cq q;
    create(&q);
    printf("Press:\n1. to enque\n2. to dequeue\n3. to find front\n4. to find rear\n5. to exit\n");
    while (choice != 5)
    {
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            scanf("%d", &val);
            enqueue(&q, val);
            display(&q);
            break;
        case 2:
            deque(&q);
            display(&q);
            break;
        case 3:
            front = findFront(&q);
            printf("Front: %d\n", front);
            break;
        case 4:
            rear = findRear(&q);
            printf("Rear: %d\n", rear);
            break;
        }
    }

    return 0;
}