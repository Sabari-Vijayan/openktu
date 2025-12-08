#include<stdio.h>

void display(int arr[], int size){
    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr1[] = {1,3,5,7,9};
    int arr2[] = {2,4,6,8};
    int size1 = 5, size2 = 4;
    int arr[9];
  
    int i=0,j=0,k=0;
    display(arr1,size1);
    display(arr2,size2);
    while(i<size1 && j<size2){
        if(arr1[i]<arr2[j]){
            arr[k++] = arr1[i++];
        }
        else if(arr1[i]==arr2[j]){
            arr[k++] = arr2[j++];
            i++;
        }
        else{
            arr[k++] = arr2[j++];
        }
    }
    while(i<size1){
        arr[k++] = arr1[i++];
    }
    while(j<size2){
        arr[k++] = arr2[j++];
    }

    display(arr,k);
}
