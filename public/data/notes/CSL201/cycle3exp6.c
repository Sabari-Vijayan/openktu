#include<stdio.h>

int size =4;
int pq[3][4];
int rear[3]={-1, -1, -1};
int front[3]={-1, -1, -1};

void display(){
    for (int p = 0; p < 3; p++) {  
        if (front[p] != -1) {  
            printf("Priority %d: ", p);
            for (int i = front[p]; i <= rear[p]; i++) {  
                printf("%d ", pq[p][i]);
            }
            printf("\n");
        }
    }
}

void insert(int item , int priority){
    if(rear[priority] == size-1){
        printf("PQ full at given priority");
        return;
    }
    rear[priority] = rear[priority]+1;
    pq[priority][rear[priority]] = item;
    if(front[priority]==-1){
        front[priority]=rear[priority];
    }
}

int delete(){
    int p=0;
    while(front[p]==-1){
        p++;
    }
    int item = pq[p][front[p]];
    front[p] = front[p]+1;
    if(front[p]>rear[p]){
        front[p] = rear[p] = -1;
    }
    return item;
}

int main(){
    insert(10, 0);  
    insert(20, 1);  
    insert(30, 0);  
    insert(40, 2);  

    display();  

    int item = delete();  
    printf("Deleted item: %d\n", item);

    item = delete();  
    printf("Deleted item: %d\n", item);

    display();  

}
