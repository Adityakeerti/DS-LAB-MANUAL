#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

int priority(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

int isOp(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char *infixToPostfix(char *infix)
{
    int i, j;
    int len = strlen(infix);
    char *postfix = (char *)malloc(sizeof(char) * (len + 2));
    if (postfix == NULL) // Check for successful memory allocation
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    char stack[MAX];
    int top = -1;

    for (i = 0, j = 0; i < len; i++)
    {
        if (infix[i] == ' ' || infix[i] == '\t')
            continue;

        if (isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (top > -1 && stack[top] != '(')
                postfix[j++] = stack[top--];
            if (top > -1 && stack[top] != '(')
            {
                free(postfix); // Free memory before returning
                return "Invalid Expression"; // Error handling
            }
            else
                top--; // Pop the '('
        }
        else if (isOp(infix[i]))
        {
            while (top > -1 && priority(stack[top]) >= priority(infix[i]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i];
        }
    }

    while (top > -1)
    {
        if (stack[top] == '(')
        {
            free(postfix); // Free memory before returning
            return "Invalid Expression"; // Error handling
        }
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char infix[MAX];
    printf("Enter an infix expression: ");
    fgets(infix, MAX, stdin); // Use fgets to read the entire line
    infix[strcspn(infix, "\n")] = '\0'; // Remove newline character

    char *postfix = infixToPostfix(infix);
    
    // Check if postfix returned a valid conversion or an error message
    if (strcmp(postfix, "Invalid Expression") == 0)
    {
        printf("%s\n", postfix);
    }
    else
    {
        printf("Postfix: %s\n", postfix);
    }
    
    // Free the allocated memory only if it is not an error message
    if (strcmp(postfix, "Invalid Expression") != 0)
    {
        free(postfix);
    }

    return 0;
}
// galathai