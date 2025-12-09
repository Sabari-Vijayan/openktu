#include<stdio.h>
#include<stdlib.h>

int main(){
    int size, item;
    printf("Enter size of list: ");
    scanf("%d", &size);
    int* arr = (int*) malloc(sizeof(int)*size);
    for(int i=0; i<size;i++){
        printf("Enter item: ");
        scanf("%d", &item);
        *(arr+i) = item;
    }
    int* min = arr;
    for(int i=0; i<size;i++){
        if(*(arr+i)<*min){
            min = (arr+i);
        }
    }
    printf("\nMin: %d", *min);
    free(min);
    free(arr);

}
