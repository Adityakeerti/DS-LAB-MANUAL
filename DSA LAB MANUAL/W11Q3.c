#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Define the tree node structure
typedef struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Stack for tree nodes
typedef struct {
    TreeNode* nodes[100];
    int top;
} NodeStack;

// Stack for operators
typedef struct {
    char ops[100];
    int top;
} OperatorStack;

// Initialize stacks
void initNodeStack(NodeStack* stack) {
    stack->top = -1;
}

void initOperatorStack(OperatorStack* stack) {
    stack->top = -1;
}

int isNodeStackEmpty(NodeStack* stack) {
    return stack->top == -1;
}

int isOperatorStackEmpty(OperatorStack* stack) {
    return stack->top == -1;
}

void pushNode(NodeStack* stack, TreeNode* node) {
    stack->nodes[++stack->top] = node;
}

TreeNode* popNode(NodeStack* stack) {
    return stack->nodes[stack->top--];
}

void pushOperator(OperatorStack* stack, char op) {
    stack->ops[++stack->top] = op;
}

char popOperator(OperatorStack* stack) {
    return stack->ops[stack->top--];
}

char peekOperator(OperatorStack* stack) {
    return stack->ops[stack->top];
}

// Function to create a new tree node
TreeNode* createNode(char data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Check operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to construct the binary expression tree
TreeNode* constructTree(char* expression) {
    NodeStack nodeStack;
    OperatorStack operatorStack;
    initNodeStack(&nodeStack);
    initOperatorStack(&operatorStack);

    for (int i = 0; i < strlen(expression); i++) {
        char ch = expression[i];

        if (isalnum(ch)) {
            pushNode(&nodeStack, createNode(ch));
        } else if (ch == '(') {
            pushOperator(&operatorStack, ch);
        } else if (ch == ')') {
            while (!isOperatorStackEmpty(&operatorStack) && peekOperator(&operatorStack) != '(') {
                char op = popOperator(&operatorStack);
                TreeNode* right = popNode(&nodeStack);
                TreeNode* left = popNode(&nodeStack);
                TreeNode* newNode = createNode(op);
                newNode->left = left;
                newNode->right = right;
                pushNode(&nodeStack, newNode);
            }
            popOperator(&operatorStack); // Pop the '('
        } else {
            while (!isOperatorStackEmpty(&operatorStack) &&
                   precedence(peekOperator(&operatorStack)) >= precedence(ch)) {
                char op = popOperator(&operatorStack);
                TreeNode* right = popNode(&nodeStack);
                TreeNode* left = popNode(&nodeStack);
                TreeNode* newNode = createNode(op);
                newNode->left = left;
                newNode->right = right;
                pushNode(&nodeStack, newNode);
            }
            pushOperator(&operatorStack, ch);
        }
    }

    // Build remaining subtrees
    while (!isOperatorStackEmpty(&operatorStack)) {
        char op = popOperator(&operatorStack);
        TreeNode* right = popNode(&nodeStack);
        TreeNode* left = popNode(&nodeStack);
        TreeNode* newNode = createNode(op);
        newNode->left = left;
        newNode->right = right;
        pushNode(&nodeStack, newNode);
    }

    // The root of the tree is the only node left in the stack
    return popNode(&nodeStack);
}

// Postorder traversal for generating postfix expression
void postorderTraversal(TreeNode* root, char* postfix, int* index) {
    if (root != NULL) {
        postorderTraversal(root->left, postfix, index);
        postorderTraversal(root->right, postfix, index);
        postfix[(*index)++] = root->data;
    }
}

// Main function
int main() {
    int T;
    scanf("%d", &T);
    getchar(); // To consume the newline after the number of test cases

    for (int t = 0; t < T; t++) {
        char expression[100];
        fgets(expression, sizeof(expression), stdin);
        int len = strlen(expression);
        if (expression[len - 1] == '\n') {
            expression[len - 1] = '\0'; // Remove newline character
        }

        TreeNode* root = constructTree(expression);

        // Generate postfix expression
        char postfix[100];
        int index = 0;
        postorderTraversal(root, postfix, &index);
        postfix[index] = '\0';

        printf("%s\n", postfix);
    }

    return 0;
}
