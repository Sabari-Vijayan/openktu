#include <stdio.h>

int main() {
    int size, key;

    printf("Enter size of array: ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter the elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int left = 0;
    int right = size;
    int found = 0;
    while (left <= right) {
        int mid = (right + left) / 2;
        if (arr[mid] == key) {
            printf("Element %d found at index %d.\n", key, mid);
            found=1;
            break;
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    if (found==0) {
        printf("Element %d not found\n", key);
    }
    return 0;
}
