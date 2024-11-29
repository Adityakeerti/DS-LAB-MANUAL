#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;          // 4 bytes
    struct Node *next; // 4 bytes
} Node;

Node *newNode(int val) {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Heap Overflow\n");
        return NULL;
    }
    temp->data = val;
    temp->next = NULL;
    return temp;
}

int isEmpty(Node *head) {
    return head == NULL;
}

void insertAtBegin(Node **head, int val) {
    Node *temp = newNode(val);
    if (temp == NULL) {
        return;
    }
    temp->next = *head;
    *head = temp;
}

void printList(Node *head) {
    if (isEmpty(head)) {
        printf("List is empty\n");
        return;
    }
    Node *itr = head;
    while (itr) {
        printf("%d ", itr->data);
        itr = itr->next;
    }
    printf("\n");
}

void insertAtEnd(Node **head, int val) {
    Node *temp = newNode(val);
    if (temp == NULL) {
        return; // Heap overflow check
    }

    if (*head == NULL) {
        *head = temp;
        return;
    }

    Node *itr = *head;
    while (itr->next) {
        itr = itr->next;
    }
    itr->next = temp;
}

void delFromBegin(Node **head) {
    if (*head == NULL) {
        printf("List is already empty\n");
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    printf("Node deleted - %d\n", temp->data);
    free(temp);
}

void delFromEnd(Node **head) {
    if (*head == NULL) {
        printf("List is already empty\n");
        return;
    }

    if ((*head)->next == NULL) {
        printf("Node deleted - %d\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    Node *itr = *head;
    while (itr->next->next) {
        itr = itr->next;
    }
    Node *temp = itr->next;
    printf("Node deleted - %d\n", temp->data);
    free(temp);
    itr->next = NULL;
}

void insertAtK(Node **head, int val, int k) {
    if (k <= 0) {
        printf("Invalid position\n");
        return;
    }

    if (k == 1) {
        insertAtBegin(head, val);
        return;
    }

    Node *temp = newNode(val);
    if (temp == NULL) {
        return;
    }

    Node *itr = *head;
    int i = 1;
    while (itr && i < k - 1) {
        itr = itr->next;
        i++;
    }

    if (itr == NULL) {
        printf("Position out of bounds\n");
        free(temp);
        return;
    }

    temp->next = itr->next;
    itr->next = temp;
}

void delAtk(Node **head, int k) {
    if (k <= 0) {
        printf("Invalid position\n");
        return;
    }

    if (isEmpty(*head)) {
        printf("List is empty\n");
        return;
    }

    if (k == 1) {
        delFromBegin(head);
        return;
    }

    Node *itr = *head;
    int i = 1;
    while (itr->next && i < k - 1) {
        itr = itr->next;
        i++;
    }

    if (itr->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    Node *temp = itr->next;
    itr->next = itr->next->next;
    printf("Node deleted - %d\n", temp->data);
    free(temp);
}

int sizeOfList(Node *head) {
    Node *itr = head;
    int size = 0;
    while (itr != NULL) {
        itr = itr->next;
        size++;
    }
    return size;
}

void midOfList(Node *head) {
    if (isEmpty(head)) {
        printf("List is empty\n");
        return;
    }

    Node *slow = head, *fast = head;
    int pos = 1;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        pos++;
    }

    printf("Mid Pos: %d\n", pos);
    printf("Mid Data: %d\n", slow->data);
}

void reverseLL(Node **head) {
    Node *front = NULL, *prev = NULL, *itr = *head;
    while (itr != NULL) {
        front = itr->next;
        itr->next = prev;
        prev = itr;
        itr = front;
    }
    *head = prev;
}

int main() {
    Node *head = NULL;
    int n = 0, val, k;

    printf("\nPress:\n1 insert node at front\n2 insert node at end\n3 insert node at specific position\n4 delete node from front\n5 delete node from end\n6 delete node from specific position\n7 find size of linked list\n8 find middle element of the list\n9 reverse linked list\n10 exit\n");

    while (n != 10) {
        scanf("%d", &n);
        switch (n) {
        case 1:
            scanf("%d", &val);
            insertAtBegin(&head, val);
            printf("Linked List - ");
            printList(head);
            break;
        case 2:
            scanf("%d", &val);
            insertAtEnd(&head, val);
            printf("Linked List - ");
            printList(head);
            break;
        case 3:
            printf("Enter k and val: ");
            scanf("%d %d", &k, &val);
            insertAtK(&head, val, k);
            printf("Linked List - ");
            printList(head);
            break;
        case 4:
            delFromBegin(&head);
            printf("Linked List after deletion - ");
            printList(head);
            break;
        case 5:
            delFromEnd(&head);
            printf("Linked List after deletion - ");
            printList(head);
            break;
        case 6:
            printf("Enter k: ");
            scanf("%d", &k);
            delAtk(&head, k);
            printf("Linked List after deletion - ");
            printList(head);
            break;
        case 7:
            printf("Size: %d\n", sizeOfList(head));
            break;
        case 8:
            midOfList(head);
            break;
        case 9:
            reverseLL(&head);
            printf("Linked List reversed - ");
            printList(head);
            break;
        case 10:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }

    return 0;
}
