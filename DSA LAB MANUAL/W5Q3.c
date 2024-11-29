/*
W5Q3. Design an algorithm and write a program to implement Deque i.e. double ended queue. Double
ended queue is a queue in which insertion and deletion can be done from both ends of the queue.
The program should implement following operations:
a) insertFront() - insert an element at the front of Deque
b)insertEnd() - insert an element at the end of Deque
c) deleteFront() - delete an element from the front of Deque
d)deleteEnd() - delete an element from the end of Deque
e) isEmpty() - checks whether Deque is empty or not
f)isFull() - checks whether Deque is full or not
g)printFront() - print Deque from front
h)printEnd() - print Deque from end

 NAME - ADITYAKEERTI
 SEC - K1
 ROLL NO. - 21
 COURSE - BTECH
 BRANCH - CSE


*/

#include <stdio.h>
#include <stdlib.h>

typedef struct deque
{
    int start, end, cap, *arr;
} deque;

void createDeque(deque *q, int cap)
{
    q->start = q->end = -1;
    q->cap = cap;
    q->arr = (int *)malloc(q->cap * sizeof(int));
}

int isEmpty(deque *q)
{
    return (q->start == -1);
}

int isFull(deque *q)
{
    return ((q->end + 1) % q->cap == q->start);
}

void insertFront(deque *q, int val)
{
    if (isFull(q))
    {
        printf("Deque Overflow\n");
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
            q->start = (q->start - 1 + q->cap) % q->cap;
        }
        q->arr[q->start] = val;
    }
}

void insertEnd(deque *q, int val)
{
    if (isFull(q))
    {
        printf("Deque Overflow\n");
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
    }
}

void deleteFront(deque *q)
{
    if (isEmpty(q))
    {
        printf("Deque Underflow\n");
        return;
    }
    else
    {
        if (q->start == q->end)
        {
            q->start = q->end = -1;
        }
        else
        {
            q->start = (q->start + 1) % q->cap;
        }
    }
}

void deleteEnd(deque *q)
{
    if (isEmpty(q))
    {
        printf("Deque Underflow\n");
        return;
    }
    else
    {
        if (q->start == q->end)
        {
            q->start = q->end = -1;
        }
        else
        {
            q->end = (q->end - 1 + q->cap) % q->cap;
        }
    }
}

void printFront(deque q)
{
    if (isEmpty(&q))
    {
        printf("Deque is empty.\n");
        return;
    }

   
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

void printEnd(deque q)
{
    if (isEmpty(&q))
    {
        printf("Deque is empty.\n");
        return;
    }
    int i = q.end;
    while (1)
    {
        printf("%d ", q.arr[i]);
        if (i == q.start)
        {
            break;
        }
        i = (i - 1 + q.cap) % q.cap;
    }
    printf("\n");
}

int main()
{
    deque q;
    int cap;
    printf("Enter size of deque: ");
    scanf("%d", &cap);
    createDeque(&q, cap);

    int choice, val;
    printf("Press:\n1 to insert at front\n2 to insert at end\n3 to delete from front\n4 to delete from end\n5 to exit\n");

    while (1)
    {
        scanf("%d", &choice);
        if (choice == 5)
            break;

        switch (choice)
        {
        case 1:
            scanf("%d", &val);
            insertFront(&q, val);
            break;
        case 2:
            scanf("%d", &val);
            insertEnd(&q, val);
            break;
        case 3:
            deleteFront(&q);
            break;
        case 4:
            deleteEnd(&q);
            break;
        }
    }

    printf("Contents of deque from front: ");
    printFront(q);

    printf("Contents of deque from end: ");
    printEnd(q);

    free(q.arr);
    return 0;
}
