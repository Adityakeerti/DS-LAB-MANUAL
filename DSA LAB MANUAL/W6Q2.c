#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void push(Stack *stack, int value) {
    if (stack->top == MAX - 1) {
        return;
    }
    stack->arr[++stack->top] = value;
}

int pop(Stack *stack) {
    if (stack->top == -1) {
        return -1;
    }
    return stack->arr[stack->top--];
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void enqueue(Stack *stack1, int value) {
    push(stack1, value);
}

int dequeue(Stack *stack1, Stack *stack2) {
    if (isEmpty(stack1) && isEmpty(stack2)) {
        return -1;
    }
    if (isEmpty(stack2)) {
        while (!isEmpty(stack1)) {
            push(stack2, pop(stack1));
        }
    }
    return pop(stack2);
}

void printQueue(Stack *stack1, Stack *stack2) {
    int i;
    if (!isEmpty(stack2)) {
        for (i = stack2->top; i >= 0; i--) {
            printf("%d ", stack2->arr[i]);
        }
    }
    for (i = 0; i <= stack1->top; i++) {
        printf("%d ", stack1->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack stack1, stack2;
    stack1.top = -1;
    stack2.top = -1;
    int choice, value;
    printf("Press:\n1 to enqueue\n2 to dequeue\n3 to exit\n");
    while (1) {
        scanf("%d", &choice);
        if (choice == 1) {
            scanf("%d", &value);
            enqueue(&stack1, value);
            printf("Queue - ");
            printQueue(&stack1, &stack2);
        } else if (choice == 2) {
            value = dequeue(&stack1, &stack2);
            if (value == -1) {
                printf("Queue is empty\n");
            } else {
                printf("Element deleted from queue - %d\n", value);
                printf("Queue after deletion- ");
                printQueue(&stack1, &stack2);
            }
        } else if (choice == 3) {
            break;
        }
    }

    return 0;
}
