#include <stdio.h>
#include <stdlib.h>

typedef struct node1 {
    int data;
    struct node1* link;
}node;

node* front;
node* rear;
node* top;

void enqueue(int data) {
    node* newnode = (node*) malloc(sizeof(node));
    if(newnode==NULL)
        return;
    newnode->data = data;
    newnode->link = NULL;
    if(rear == NULL) {
        front = newnode;
        rear = newnode;
        return;
    }
    rear->link = newnode;
    rear = newnode;
}

int dequeue() {
    if (front == NULL) {
        printf("Queue Underflow!\n");
        return -1;
    }
    node* ptr = front;
    int data = ptr->data;
    front = front->link;
    if (front == NULL) {
        rear = NULL;
    }
    free(ptr);
    printf("%d dequeued from the queue.\n", data);
    return data;
}

void push(int data) {
    node* newnode = (node*) malloc(sizeof(node));
    if(newnode==NULL)
        return;
    newnode->data = data;
    newnode->link = top;
    top = newnode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    node* ptr = top;
    int data = ptr->data;
    top = top->link;
    free(ptr);
    return data;
}

void displayQueue() {
    node* ptr = front;
    if (ptr == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue contents: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void main() {
    top = NULL;
    front = rear = NULL;
    int value, qsize;
    
    printf("Enter number of elements in queue: ");
    scanf("%d", &qsize);
    
    for(int i=0;i<qsize;i++){
        printf("Enter item %d: ", i);
        scanf("%d", &value);
        enqueue(value);
    }
    displayQueue();
    while (front != NULL) {
        push(dequeue());
    }
    while (top != NULL) {
        enqueue(pop());
    }
    printf("Queue has been reversed.\n");
    displayQueue();
}
