#include <stdio.h>

int size = 5;
int cq[5];
int front = -1;
int rear = -1;

void enqueue(int item) {
    if (front == (rear + 1) % size) {
        printf("CQ Overflow\n");
        return;
    }
    rear = (rear + 1) % size;
    if (front == -1) {
        front = rear;
    }
    cq[rear] = item;
}

int dequeue() {
    if (rear == -1 && front == -1) {
        printf("CQ Underflow\n");
        return -1;
    }

    int item = cq[front];
    
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }
    return item;
}

void display() {
    if (rear == -1 && front == -1) {
        printf("CQ Underflow\n");
        return;
    }
    int i = front;
    printf("Queue: ");
    while (i != rear) {
        printf("%d ", cq[i]);
        i = (i + 1) % size;
    }
    printf("%d\n", cq[rear]);
}

int main() {
    int choice, element;
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("0. Exit\n");

    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &element);
                enqueue(element);
                display(); 
                break;
            case 2:
                dequeue();
                display();
                break;
            case 3:
                display();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
