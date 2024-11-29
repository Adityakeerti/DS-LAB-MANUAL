/*
 W3Q1. Design an algorithm and a program to implement stack using array. The program should
 implement following stack operations:
 a)Create() - create an empty stack
 b)Push(k) - push an element k into the stack
 c)Pop() - pop an element from the stack snd return it
 d)IsEmpty() - check if stack is empty or not
 e)Size() - finds the size of the stack
 f)Print() - prints the contents of stack
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct stackImp
{
    int size;
    int *arr;
    int top;

} stackImp;

void create(stackImp *st)
{
    printf("Enter the size of stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->arr = (int *)malloc(st->size * sizeof(int));
}

void push(stackImp *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->arr[st->top] = x;
    }
}

int pop(stackImp *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->arr[st->top];
        st->top--;
        printf("%d popped from the stack\n", x);
    }
    return x;
}

int IsEmpty(stackImp *st)
{
    if (st->top == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void StackSize(stackImp *st)
{
    printf("Size : %d\n", st->top + 1);
}

void printStack(stackImp st)
{
    
    int i = 0;
    while (i <= st.top)
    {
        printf("%d ", st.arr[i]);
        i++;
    }
    printf("\n");
}


int main()
{
    stackImp st;
    int choice, val;
    create(&st);
    while (choice != 4)
    {
        printf("\nPress:\n1. to push\n2. to pop\n3. to calculate size\n4. to exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &val);
            push(&st, val);
            printStack(st);
            break;
        case 2:
            pop(&st);
            break;
        case 3:
            StackSize(&st);
            break;
        
        }
    }

    return 0;
}