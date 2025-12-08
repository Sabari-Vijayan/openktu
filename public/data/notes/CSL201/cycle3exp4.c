#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void insert(int element) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert more elements.\n");
        return;
    }
    if (front == -1) front = 0; 
    queue[++rear] = element;
    printf("Inserted %d into the queue.\n", element);
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No elements to delete.\n");
        return;
    }
    printf("Deleted %d from the queue.\n", queue[front]);
    front++;
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, element;
    printf("1. Insert element into queue\n");
    printf("2. Delete element from queue\n");
    printf("3. Display queue\n");
    printf("0. Exit");
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insert(element);
                display(); 
                break;
            case 2:
                delete();
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
