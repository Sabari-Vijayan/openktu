#include <stdio.h>
#include <stdlib.h>

int stack1[100],stack2[100], top1=-1, top2=-1, size;

void push(int stack[], int* top, int item){
    if(*top==size-1)
        return;
    (*top)++;
    stack[*top] = item;
}

int pop(int stack[], int* top){
    if(*top==-1){
        return -1;
    }
    int item = stack[*top];
    (*top)--;
    return item;
}

void enqueue(int item){
    push(stack1, &top1, item);
    printf("%d enqueued\n", item);
}

void dequeue(){
    int item;
    if(top2==-1){
        while((item=pop(stack1, &top1))!=-1){
            push(stack2, &top2, item);
        }
    }
    if(top2==-1){
        printf("Queue is empty\n");
        return;
    }
    item = pop(stack2, &top2);
    printf("%d dequeued\n", item);
}

int main() {
    size = 10;
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    printf("\n");
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}
