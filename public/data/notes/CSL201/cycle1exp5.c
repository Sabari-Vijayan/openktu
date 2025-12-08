#include<stdio.h>

void display(int* arr, int len) {
    for(int i = 0; i < len; i++) {
        printf("%d ", *(arr + i)); 
    }
    printf("\n");
}

void bubbleSort(int* arr, int n) {
    for(int i = 0; i < n ; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main() {
    int arr[] = {3, 4, 5, 2, 6, 8, 1, 9};
    int len = sizeof(arr) / sizeof(int);

    printf("Original array: ");
    display(arr, len);
    
    bubbleSort(arr, len);

    printf("Sorted array: ");
    display(arr, len);

    return 0;
}
