#include <stdio.h>

#define SIZE 100 

int stack[SIZE];  
int top = -1;   

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == SIZE - 1;
}

void push(int item) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
    printf("Item Pushed.\n");
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1; 
    }
    return stack[top--];
}

int peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1; 
    }
    return stack[top];
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice, value;
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("0. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped %d from the stack.\n", value);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("Top element is %d.\n", value);
                }
                break;
            case 4:
                display();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
