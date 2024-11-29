/*
W4Q1. Given an empty stack, design an algorithm and a program to reverse a string using this stack
(with and without recursion).
 NAME - ADITYAKEERTI
 SEC - K1
 COURSE - BTECH
 BRANCH - CSE
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stackImp
{
    int size;
    char *arr;
    int top;

} stackImp;

void create(stackImp *st, int n)
{
    st->size = n;
    st->top = -1;
    st->arr = (char *)malloc(st->size * sizeof(char));
}

void push(stackImp *st, char x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->top++;
        st->arr[st->top] = x; // x pushed into the stack
        // printf("%c pushed \n", x);
    }
}

char pop(stackImp *st)
{
    int x = '\0';
    if (st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->arr[st->top];
        st->top--;
    }
    return x;
}

int IsEmpty(stackImp *st)
{
    return (st->top == -1);
}

void reverseString(char *str, int n)
{
    stackImp st;
    create(&st, n);
    for (int i = 0; i < n; i++)
    {
        push(&st, str[i]);
    }
    for (int i = 0; i < n; i++)
    {
        str[i] = pop(&st);
    }
    printf("Reversed String without recursion: ");
    puts(str);
}

void reverseRec(stackImp *st, char *str, int index)
{
    if (IsEmpty(&st))
    {
        return;
    }

    char ch = pop(st);
    reverseRec(st, str, index + 1);
    str[index] = ch;
}

void revStr(char *str, int n)
{
    stackImp st;
    int len = strlen(str);

    create(&st, len);
    for (int i = 0; i < len; i++)
    {
        push(&st, str[i]);
    }

    reverseRec(&st, str, 0); // initiate recursive reversal
    printf("Reversed String using recursion: %s\n", str);
}

int main()
{
    int t;
    printf("Enter number of test cases: ");
    scanf("%d", &t);
    while (t > 0)
    {
        printf("Enter string: \n");
        char str[1000];
        getchar();
        fgets(str, 1000, stdin);
        int n = strlen(str) - 1;

        reverseString(str, n); //without 
        revStr(str, n); 

        t--;
    }

    return 0;
}