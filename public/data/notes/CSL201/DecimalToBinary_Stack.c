#include <stdio.h>
#include <stdlib.h>

int stack[100], size, top=-1;

void push(int item){
    if(top==size-1)
        return;
    stack[++top] = item;
}

int pop(){
    if(top==-1)
        return -1;
    int item = stack[top--];
    return item;
}

void decimalTobinary(int num){
    int ognum = num, digit;
    while(num>=0){
        push(num%2);
        num=num/2;
        if(num==0)
            break;
    }
    printf("Decimal: %d Binary: ", ognum);
    while((digit=pop())!=-1){
        printf("%d", digit);
    }
}

int main() {
    size = 100;
    decimalTobinary(12345);
    return 0;
}
