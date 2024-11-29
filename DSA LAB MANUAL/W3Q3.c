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

void printStack(stackImp st)
{
    printf("Stack Elements:\n");
    int i = st.top;
    while (i >= 0)
    {
        printf("%d ", st.arr[i]);
        i--;
    }
    printf("\n");
}

int validLength(char str[], int n)
{
    int maxLen = 0;
    stackImp st;
    create(&st, n + 1);
    push(&st, -1);

    for (int i = 0; i < n; i++)
    {
        if (str[i] == '(')
        {
            push(&st, i);
        }
        else
        {
            pop(&st);

            if (!IsEmpty(&st))
            {
                int len = i - st.arr[st.top];
                if (len > maxLen)
                {
                    maxLen = len;
                }
            }
            else
            {
                push(&st, i);
            }
        }
    }
    return maxLen;
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

        int validLen = validLength(str, n);
        printf("%d\n", validLen);
        t--;
    }

    return 0;
}
