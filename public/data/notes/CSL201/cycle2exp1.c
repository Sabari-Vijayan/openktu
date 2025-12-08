#include <stdio.h>

int main() {
    int size, key, i;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements: ");
    for (int i=0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &key);

    for (i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("Element %d found at index %d.\n", key, i);
            break;
        }
    }
    if (i==size) {
        printf("Element %d not found.\n", key);
    }

    return 0;
}
