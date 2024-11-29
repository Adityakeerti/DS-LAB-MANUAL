/*
Design an algorithm and write a program to reverse a queue.

 NAME - ADITYAKEERTI
 SEC - K1
 ROLL NO. - 21
 COURSE - BTECH
 BRANCH - CSE

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct queue
{
    int start, end, cap, *arr;
} queue;

void createQueue(queue *q, int cap)
{
    q->start = q->end = -1;
    q->cap = cap;
    q->arr = (int *)malloc(q->cap * sizeof(int));
}

int isEmpty(queue *q)
{
    return (q->start == -1);
}

int isFull(queue *q)
{
    return ((q->end + 1) % q->cap == q->start);
}

int size(queue *q)
{
    return (q->cap - q->start + q->end + 1) % q->cap;
}

void push(queue *q, int val)
{
    if (isFull(q))
    {
        printf("QUEUE OVERFLOW\n");
        return;
    }
    else
    {
        if (isEmpty(q))
        {
            q->start = q->end = 0;
        }
        else
        {
            q->end = (q->end + 1) % q->cap;
        }
        q->arr[q->end] = val;
        // printf("%d Queued\n", q->arr[q->end]);
    }
}

void pop(queue *q)
{
    if (isEmpty(q))
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }
    else
    {
        if (q->start == q->end)
        {
            q->start = q->end = -1;
            return;
        }
        // printf("%d Dequed\n", q->arr[q->start]);
        q->start = (q->start + 1) % q->cap;
    }
}

void display(queue q)
{
    printf("Queue - ");
    int i = q.start;
    while (1)
    {
        printf("%d ", q.arr[i]);
        if (i == q.end)
        {
            break;
        }
        i = (i + 1) % q.cap;
    }
    printf("\n");
}

void reverseQueue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot reverse.\n");
        return;
    }

    int stack[q->cap];
    int top = -1;

    // Pop all elements from queue and push to stack
    while (!isEmpty(q))
    {
        stack[++top] = q->arr[q->start];
        pop(q);
    }

    // Push back all elements from stack to queue
    while (top != -1)
    {
        push(q, stack[top--]);
    }
}

int main()
{
    queue q;
    int cap;
    printf("Enter size of queue: ");
    scanf("%d", &cap);
    createQueue(&q, cap);
    int choice, val;
    printf("Press:\n1 to insert\n2 to exit\n");
    while (choice != 2)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d", &val);
            push(&q, val);
            break;
        }
    }

    printf("Initial Queue: ");
    display(q);

    reverseQueue(&q);

    printf("Reversed Queue: ");
    display(q);

    free(q.arr);

    return 0;
}
