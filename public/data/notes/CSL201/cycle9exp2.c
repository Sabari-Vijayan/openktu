#include <stdio.h>

int size;
int hashTable[100];

void insert(int key) {
    int index = key % size;
    while (hashTable[index] != -1) 
        index = (index + 1) % size;  
    hashTable[index] = key;
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < size; i++) {
        if (hashTable[i] == -1) 
            printf("[%d] :\n", i);
        else 
            printf("[%d] : %d\n", i, hashTable[i]);
    }
}

// int search(int key) {
//     int index = key % size;
//     int startIndex = index;
//     while (hashTable[index] != -1) {
//         if (hashTable[index] == key) 
//             return index;  
//         index = (index + 1) % size;
//         if (index == startIndex) 
//             break;
//     }
//     return -1;  
// }

int main() {
    int choice, key;
    printf("Enter size of table: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        hashTable[i] = -1;
    }

    printf("1.Insert key\n2.Display\n0.Exit");
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                display();
                break;
            case 0:
                return 0;
        }
    }
    return 0;
}
