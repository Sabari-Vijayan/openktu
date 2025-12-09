#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* link;
}node;

node* header;

void insert(int data){
    node* newnode = (node*) malloc(sizeof(node));
    newnode->data = data;
    newnode->link = header->link;
    header->link = newnode;
}

void display(){
    node* ptr = header->link;
    while(ptr!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void bubblesort(){
    int swapped;
    node* ptr;
    node* lastptr = NULL;
    if (header->link == NULL) return;
    do{
        swapped = 0;
        ptr = header->link;
        while(ptr->link!=lastptr){
            if(ptr->data > ptr->link->data){
                int temp = ptr->data;
                ptr->data = ptr->link->data;
                ptr->link->data = temp;
                swapped = 1;
            }
            ptr = ptr->link;
        }  
        lastptr = ptr;
    }
    while(swapped == 1);
}

int main(){
    header = (node*) malloc(sizeof(node));
    header->link=NULL;

    insert(5);
    insert(2);
    insert(3);
    insert(1);
    insert(4);
    insert(8);
    insert(6);
    display();
    bubblesort();
    display();
    return 0;
}
