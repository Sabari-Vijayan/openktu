#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int precedence(char operator) {
    if (operator == '^')
        return 3;
    if (operator == '*' || operator == '/')
        return 2;
    if (operator == '+' || operator == '-')
        return 1;
    return -1;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int isOperand(char ch) {
    return (ch >= '0' && ch <= '9');
}

void push(char stack[], int *top, char element) {
    if (*top >= MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++(*top)] = element;
}

char pop(char stack[], int *top) {
    if (*top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[(*top)--];
}

void infixToPrefix(char infix[], char prefix[]) {
    char stack[MAX_SIZE];
    int top = -1;
    int i, j = 0;

    for (i = strlen(infix) - 1; i >= 0; i--) {
        if (isOperand(infix[i])) {
            prefix[j++] = infix[i];
        } else if (infix[i] == ')') {
            push(stack, &top, infix[i]);
        } else if (infix[i] == '(') {
            while (top >= 0 && stack[top] != ')') {
                prefix[j++] = pop(stack, &top);
            }
            if (top >= 0 && stack[top] == ')') {
                pop(stack, &top);
            } else {
                printf("Invalid expression\n");
                return;
            }
        } else if (isOperator(infix[i])) {
            while (top >= 0 && precedence(stack[top]) > precedence(infix[i])) {
                prefix[j++] = pop(stack, &top);
            }
            push(stack, &top, infix[i]);
        }
    }

    while (top >= 0) {
        prefix[j++] = pop(stack, &top);
    }
    prefix[j] = '\0';
    int start = 0, end = j - 1;
    while (start < end) {
        char temp = prefix[start];
        prefix[start] = prefix[end];
        prefix[end] = temp;
        start++;
        end--;
    }
}

int main() {
    char infix[MAX_SIZE], prefix[MAX_SIZE];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
} 
