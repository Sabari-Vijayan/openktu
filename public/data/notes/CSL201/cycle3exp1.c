#include <stdio.h>
#include <ctype.h>
#include <math.h> 

#define MAX 100

char infix[MAX];
char postfix[MAX];

char stack[MAX];
int top = -1;

int postfixIndex = 0;

void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    } else {
        printf("Stack overflow!\n");
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0'; 
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0'; 
}

int isEmpty() {
    return top == -1;
}

int isOperand(char ch) {
    return isdigit(ch);
}

int precedence(char op) {
    if (op == '^') return 3;   
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isRightAssociative(char op) {
    return (op == '^');
}

void infixToPostfix() {
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        if (isOperand(ch)) {
            postfix[postfixIndex++] = ch;
        }

        else if (ch == '(') {
            push(ch);
        }

        else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[postfixIndex++] = pop();
            }
            pop(); 
        }

        else {
            while (!isEmpty() && ((isRightAssociative(ch) == 0 && precedence(peek()) >= precedence(ch)) ||
                                  (isRightAssociative(ch) && precedence(peek()) > precedence(ch)))) {
                postfix[postfixIndex++] = pop();
            }
            push(ch);
        }
    }

    while (!isEmpty()) {
        postfix[postfixIndex++] = pop();
    }

    postfix[postfixIndex] = '\0'; 
}

int evaluatePostfix() {
    int operandStack[MAX]; 
    int operandTop = -1;   

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isOperand(ch)) {
            operandStack[++operandTop] = ch - '0'; 
        }

        else {
            int val2 = operandStack[operandTop--];
            int val1 = operandStack[operandTop--];

            switch (ch) {
                case '+': operandStack[++operandTop] = val1 + val2; break;
                case '-': operandStack[++operandTop] = val1 - val2; break;
                case '*': operandStack[++operandTop] = val1 * val2; break;
                case '/': operandStack[++operandTop] = val1 / val2; break;
                case '^': operandStack[++operandTop] = (int)pow(val1, val2); break; 
            }
        }
    }
    return operandStack[operandTop]; 
}

int main() {
    printf("Enter an infix expression: ");
    scanf("%s", infix);
    infixToPostfix();
    printf("Postfix expression: %s\n", postfix);
    int result = evaluatePostfix();
    printf("Evaluation result: %d\n", result);
    return 0;
}
