#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};
struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->link = NULL;

    if (rear == NULL) { 
        front = rear = newnode;
        rear->link = front; 
    } else {
        rear->link = newnode;
        rear = newnode;
        rear->link = front; 
    }
}

int dequeue() {
    if (front == NULL) { 
        printf("Queue is empty\n");
        return -1;
    }
    int value;
    if (front == rear) { 
        value = front->data;
        free(front);
        front = rear = NULL;
    } else {
        struct node* temp = front;
        value = temp->data;
        front = front->link;
        rear->link = front; 
        free(temp);
    }
    printf("Dequeued %d\n", value);
    return value;
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct node* temp = front;
    do {
        printf("%d ", temp->data);
        temp = temp->link;
    } 
    while (temp != front);
    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}
