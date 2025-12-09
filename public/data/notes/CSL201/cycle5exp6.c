#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(Node** head, char data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

int isPalindrome(Node* head) {
    if (head == NULL)
        return 1; 
    Node* tail = head;
    while (tail->next != NULL)
        tail = tail->next;

    while (head != tail && tail->next != head) {
        if (head->data != tail->data)
            return 0;  
        head = head->next;
        tail = tail->prev;
    }
    return 1;  
}

int main() {
    Node* head = NULL;
    char str[100];  
    printf("Enter string: ");
    scanf("%s", str);
    for (int i = 0; i < strlen(str); i++) {
        insertEnd(&head, str[i]);
    }

    if (isPalindrome(head)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
