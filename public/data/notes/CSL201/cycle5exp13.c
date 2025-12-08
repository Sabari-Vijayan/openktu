#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StudentNode {
    int number;                    
    char name[50];                
    float total_marks;             
    struct StudentNode* link;     
} StudentNode;

void insertStudent(StudentNode** header, int number, const char* name, float total_marks) {
     StudentNode* newNode = (StudentNode*)malloc(sizeof(StudentNode));
    newNode->number = number;
    strcpy(newNode->name, name);
    newNode->total_marks = total_marks;
    newNode->link = *header; 
    *header = newNode; 
}

void deleteStudent(StudentNode** header, int number) {
    StudentNode* ptr = *header;
    StudentNode* previous = NULL;
    while (ptr != NULL && ptr->number != number) {
        previous = ptr;
        ptr = ptr->link;
    }
    if (ptr == NULL) {
        printf("Student with number %d not found.\n", number);
        return; 
    }

    else {
        previous->link = ptr->link;
    }
    free(ptr);
    printf("Student with number %d deleted.\n", number);
}

StudentNode* searchStudent(StudentNode* header, const char* name, int number) {
    StudentNode* ptr = header;
    while (ptr != NULL) {
        if ((name != NULL && strcmp(ptr->name, name) == 0) || (number != -1 && ptr->number == number)) {
            return ptr; 
        }
        ptr = ptr->link;
    }
    return NULL; 
}

void sortStudents(StudentNode** header) {
    if (*header == NULL) {
        return; 
    }

    StudentNode *i, *j;
    int tempNumber;
    char tempName[50];
    float tempMarks;

    for (i = *header; i != NULL; i = i->link) {
        for (j = *header; j->link != NULL; j = j->link) {
            if (j->number > j->link->number) {

                tempNumber = j->number;
                j->number = j->link->number;
                j->link->number = tempNumber;

                strcpy(tempName, j->name);
                strcpy(j->name, j->link->name);
                strcpy(j->link->name, tempName);

                tempMarks = j->total_marks;
                j->total_marks = j->link->total_marks;
                j->link->total_marks = tempMarks;
            }
        }
    }
}

void displayStudents(StudentNode* header) {
    if (header == NULL) {
        printf("No students in the list.\n");
        return;
    }

    printf("Student List:\n");
    printf("Number\tName\tTotal Marks\n");
    printf("-------------------------------------\n");
    StudentNode* ptr = header;
    while (ptr != NULL) {
        printf("%d\t%s\t\t%.2f\n", ptr->number, ptr->name, ptr->total_marks);
        ptr = ptr->link;
    }
}

int main() {
    StudentNode* header = NULL; 
    int choice, number;
    char name[50];
    float total_marks;

    do {
        printf("1. Insert Student\n");
        printf("2. Delete Student\n");
        printf("3. Search Student\n");
        printf("4. Sort Students\n");
        printf("5. Display Students\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter student number, name, and total marks: ");
                scanf("%d %s %f", &number, name, &total_marks);
                insertStudent(&header, number, name, total_marks);
                break;
            case 2:
                printf("Enter student number to delete: ");
                scanf("%d", &number);
                deleteStudent(&header, number);
                break;
            case 3:
                printf("Enter student number to search (or -1 for name search): ");
                scanf("%d", &number);
                if (number == -1) {
                    printf("Enter name to search: ");
                    scanf("%s", name);
                } else {
                    name[0] = '\0'; 
                }

                StudentNode* foundStudent = searchStudent(header, name[0] ? name : NULL, number);
                if (foundStudent != NULL) {
                    printf("Student found: %d %s %f\n", foundStudent->number, foundStudent->name, foundStudent->total_marks);
                } else {
                    printf("Student not found.\n");
                }
                break;
            case 4:
                sortStudents(&header);
                printf("Students sorted by number.\n");
                break;
            case 5:
                displayStudents(header);
                break;
        }
    } 
    while (choice != 0);
    return 0;
}
