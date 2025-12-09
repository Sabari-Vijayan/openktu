#include <stdio.h>

int size = 5;
int dq[5];
int f = -1;  
int r = -1;  

void insertRear(int item) {
    if (r == size - 1) {
        printf("DQ Overflow\n");
        return;
    }
    r++;
    dq[r] = item;
    if (f == -1) {
        f = 0;
    }
    printf("Inserted %d at rear\n", item);
}

void insertFront(int item) {
    if (f == 0) {
        printf("Cannot insert at front\n");
        return;
    }
    if (f == -1) {
        f = r = 0;
    } else {
        f--;
    }
    dq[f] = item;
    printf("Inserted %d at front\n", item);
}

int deleteFront() {
    if (f == -1) {
        printf("DQ is empty\n");
        return -1;
    }
    int item = dq[f];
    f++;
    if (f > r) {  
        f = r = -1;
    }
    printf("Deleted %d from front\n", item);
    return item;
}

int deleteRear() {
    if (r == -1) {
        printf("DQ is empty\n");
        return -1;
    }
    int item = dq[r];
    r--;
    if (f > r) {  
        f = r = -1;
    }
    printf("Deleted %d from rear\n", item);
    return item;
}

void display() {
    if (f == -1) {
        printf("DQ is empty\n");
        return;
    }
    printf("DQ: ");
    for (int i = f; i <= r; i++) {
        printf("%d ", dq[i]);
    }
    printf("\n");
}

int main() {
    insertFront(1);  
    insertRear(2);   
    insertRear(3);   
    deleteFront();   
    insertFront(0);  
    deleteRear();    
    display();       

    return 0;
}
