#include <stdio.h>
#include <string.h>
#include <ctype.h>

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

void infixToPostfixRec(char* infix, int start, int end, char* postfix, int* pIndex) {

    if (start == end) {
        postfix[(*pIndex)++] = infix[start];
        return;
    }

    int minPrecedence = 4; 
    int operatorIndex = -1; 
    int parentheses = 0;

    for (int i = start; i <= end; i++) {
        if (infix[i] == '(') parentheses++;
        else if (infix[i] == ')') parentheses--;
        else if (isOperator(infix[i]) && parentheses == 0) {
            int prec = precedence(infix[i]);
            if (prec <= minPrecedence) {
                minPrecedence = prec;
                operatorIndex = i;
            }
        }
    }

    if (infix[start] == '(' && infix[end] == ')') {
        infixToPostfixRec(infix, start + 1, end - 1, postfix, pIndex);
        return;
    }

    infixToPostfixRec(infix, start, operatorIndex - 1, postfix, pIndex);

    infixToPostfixRec(infix, operatorIndex + 1, end, postfix, pIndex);

    postfix[(*pIndex)++] = infix[operatorIndex];
}

void infixToPostfix(char* infix, char* postfix) {
    int n = strlen(infix);
    int pIndex = 0;  

    infixToPostfixRec(infix, 0, n - 1, postfix, &pIndex);

    postfix[pIndex] = '\0';
}

int main() {
    char infix[] = "1+(2/3)^3";
    char postfix[100];  

    infixToPostfix(infix, postfix);

    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
