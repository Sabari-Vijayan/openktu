#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100 

char stack[MAX];
int top = -1;

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
        return;
    }
    stack[++top] = c;
}
char pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return '\0';
    }
    return stack[top--];
}

int isPalindrome(char str[]) {
    int i, length = strlen(str);
    for (i = 0; i < length; i++) {
        push(str[i]);
    }
    for (i = 0; i < length; i++) {
        if (str[i] != pop()) 
            return 0; 
    }
    return 1; 
}

int main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str); 
    if (isPalindrome(str))
        printf("The string is a palindrome.\n");
    else 
        printf("The string is not a palindrome.\n");
    return 0;
}
