// /*
// W3Q2. Given an expression string consisting of opening and closing brackets “{“,”}”,”(“,”)”,”[“,”]”,
//  design an algorithm and a program to check whether this expression has balanced paranthesis or
//  not.
// */

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// typedef struct stackImp
// {
//     int size;
//     char *arr;
//     int top;

// } stackImp;

// void create(stackImp *st, int n)
// { // stack of size n is created
//     st->size = n;
//     st->top = -1;
//     st->arr = (char *)malloc(st->size * sizeof(char));
// }

// void push(stackImp *st, char x)
// {
//     if (st->top == st->size - 1)
//     {
//         printf("Stack Overflow\n");
//     }
//     else
//     {
//         st->top++;
//         st->arr[st->top] = x; // x pushed into the stack
//     }
// }

// char pop(stackImp *st)
// {
//     int x = '\0';
//     if (st->top == -1)
//     {
//         printf("Stack Underflow\n");
//     }
//     else
//     {
//         x = st->arr[st->top];
//         st->top--;
//         // printf("%d popped from the stack\n", x);
//     }
//     return x;
// }

// int IsEmpty(stackImp *st)
// {
//     return st->top == -1;
// }

// void StackSize(stackImp *st)
// {
//     printf("Current size of the stack : %d\n", st->top + 1);
// }

// void printStack(stackImp st)
// {
//     printf("Stack Elements:\n");
//     int i = st.top;
//     while (i >= 0)
//     {
//         printf("%d ", st.arr[i]);
//         i--;
//     }
//     printf("\n");
// }

// int checkBalance(char str[], int n)
// {
//     stackImp st;
//     create(&st, n);
//     for (int i = 0; i < n; i++)
//     {
//         if (str[i] == '(' || str[i] == '{' || str[i] == '[')
//         {
//             push(&st, str[i]);
//         }
//         else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
//         {
//             if (IsEmpty(&st))
//             {
//                 return 0;  // Stack empty but closing bracket found
//             }
//             char check = pop(&st);
//             if ((str[i] == ')' && check != '(') ||
//                 (str[i] == '}' && check != '{') ||
//                 (str[i] == ']' && check != '['))
//             {
//                 return 0;  // Mismatched bracket
//             }
//         }
//     }
    
//     // If stack is empty after the full check, it's balanced
//     return IsEmpty(&st);
// }


// int main()
// {
//     int t;
//     scanf("%d",&t);
// while (t>0)
// {

//     printf("Enter string: \n");
//     getchar();
//     char str[1000];
//     fgets(str, 1000, stdin);
//     int n = strlen(str) - 1;

//     int check = checkBalance(str, n);
//     if (check==1)
//     {
//         printf("Balanced\n");
//     }
//     else
//     {
//         printf("Not Balanced\n");
//     }
//     t--;
// }

    
//     return 0;
// }

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
        st->arr[st->top] = x;
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
    return st->top == -1;
}

int checkBalance(char str[], int n)
{
    stackImp st;
    create(&st, n);
    
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            push(&st, str[i]);
        }
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if (IsEmpty(&st))
            {
                return 0;  // Stack is empty but a closing bracket is found
            }
            char check = pop(&st);
            if ((str[i] == ')' && check != '(') ||
                (str[i] == '}' && check != '{') ||
                (str[i] == ']' && check != '['))
            {
                return 0;  // Mismatched bracket
            }
        }
    }
    
    return IsEmpty(&st);  // Stack should be empty if balanced
}

int main()
{
    int t;
    scanf("%d", &t);
    getchar(); // To consume the newline character left by scanf()

    while (t > 0)
    {
        printf("Enter string: \n");
        char str[1000];
        fgets(str, 1000, stdin);

        // Removing the newline character at the end of the input string, if present
        int n = strlen(str);
        if (str[n - 1] == '\n')
        {
            str[n - 1] = '\0';
            n--; // Adjust length
        }

        int check = checkBalance(str, n);
        if (check == 1)
        {
            printf("Balanced\n");
        }
        else
        {
            printf("Not Balanced\n");
        }
        t--;
    }

    return 0;
}
