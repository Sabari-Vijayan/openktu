#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initStack(Stack* stack) {
    stack->top = NULL;
}

void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top; 
    stack->top = newNode; 
    printf("Pushed %d onto the stack.\n", data);
}

int pop(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack Underflow.\n");
        return -1;
    }
    Node* temp = stack->top;
    int poppedData = temp->data; 
    stack->top = stack->top->next; 
    free(temp); 
    return poppedData; 
}

void display(Stack* stack) {
    if (stack->top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    Node* temp = stack->top;
    printf("Stack:");
    while (temp != NULL) {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);
    int choice, value;
    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2: 
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped %d from the stack.\n", value);
                }
                break;
            case 3: 
                display(&stack);
                break;
            case 4: 
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
