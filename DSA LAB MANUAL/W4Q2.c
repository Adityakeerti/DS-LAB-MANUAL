/*
W4Q2. Design an algorithm and a program to implement two stacks by using only one array i.e. both the
stacks should use the same array for push and pop operation. Array should be divided in such a
manner that space should be efficiently used if one stack contains very large number of elements
and other one contains only few elements.
 NAME - ADITYAKEERTI
 SEC - K1
 COURSE - BTECH
 BRANCH - CSE

*/
#include <stdio.h>
#include <stdlib.h>
typedef struct stackImp
{
    int size;
    int *arr;
    int top1, top2;
} stackImp;
void create(stackImp *st)
{
    printf("Enter the size of stack: ");
    scanf("%d", &st->size);
    st->top1 = -1;
    st->top2 = st->size;
    st->arr = (int *)malloc(st->size * sizeof(int));
}
void push1(stackImp *st, int x)
{
    if (st->top1 < st->top2 - 1)
    {
        st->top1++;
        st->arr[st->top1] = x;
    }
    else
    {
        printf("Overflow\n");
        return;
    }
}
void push2(stackImp *st, int x)
{
    if (st->top1 < st->top2 - 1)
    {
        st->top2--; // Decrement top2 for Stack 2
        st->arr[st->top2] = x;
    }
    else
    {
        printf("Overflow in Stack 2\n");
        return;
    }
}
int pop1(stackImp *st)
{
    if (st->top1 >= 0)
    {
        int x = st->arr[st->top1];
        st->top1--;
        return x;
    }
    else
    {
        printf("Underflow in Stack 1\n");
        return -1;
    }
}
int pop2(stackImp *st)
{
    if (st->top2 < st->size)
    {
        int x = st->arr[st->top2];
        st->top2++; // Increment top2 after popping
        return x;
    }
    else
    {
        printf("Underflow in Stack 2\n");
        return -1;
    }
}
int isEmpty1(stackImp *st)
{
    return st->top1 == -1;
}
int isEmpty2(stackImp *st)
{
    return st->top2 == st->size;
}
void display(stackImp *st)
{
    printf("Stack 1: ");
    for (int i = 0; i <= st->top1; i++)
    {
        printf("%d ", st->arr[i]);
    }
    printf("\nStack 2: ");
    for (int i = st->size - 1; i >= st->top2; i--)
    {
        printf("%d ", st->arr[i]);
    }
    printf("\n");
}

int main()
{
    stackImp st;
    create(&st);
    int choice, val;
    printf("\n1. Push Value in Stack1\n2. Pop from stack 1\n3. Push in Stack 2\n4. Pop from stack 2\n5. to Exit\nEnter Choice: \n");
    while (choice != 5)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // PUSH IN SATCK1
            printf("Enter value to push: ");
            scanf("%d", &val);
            push1(&st, val);
            break;
        case 2: // POP1
            pop1(&st);
            break;
        case 3: // PUSH IN SATCK2
            printf("Enter value to push: ");
            scanf("%d", &val);
            push2(&st, val);
            break;
        case 4: // POP2
            pop2(&st);
            break;
        }
    }
    display(&st);
    return 0;
}