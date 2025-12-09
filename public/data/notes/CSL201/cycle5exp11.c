#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode1 {
    int coeff;             
    int exp;               
    struct PolyNode1* link;
}PolyNode;

PolyNode* header1;
PolyNode* header2;
PolyNode* header3;

void insertTerm(PolyNode* header, int coeff, int exp) {
    if (coeff == 0) {
        return; 
    }

    PolyNode* newNode = (PolyNode*) malloc(sizeof(PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->link = NULL;

    if (header->link == NULL) {
        header->link = newNode;
        return;
    }

    PolyNode* current = header->link;
    PolyNode* previous = NULL;

    while (current != NULL && current->exp > exp) {
        previous = current;
        current = current->link;
    }
    if (current != NULL && current->exp == exp) {
        current->coeff += coeff; 
        free(newNode);            
    } else {
        newNode->link = current;  
        if (previous == NULL) 
            header->link = newNode;  
        else 
            previous->link = newNode;  
    }
}


void displayPolynomial(PolyNode* header) {
    if (header->link == NULL) {
        printf("0\n");
        return;
    }
    PolyNode* ptr = header->link;
    while (ptr != NULL) {
        printf("%dx^%d", ptr->coeff, ptr->exp);
        if (ptr->link != NULL) {
            printf(" + ");
        }
        ptr = ptr->link;
    }
    printf("\n");
}

void multiplyPolynomials() {
    PolyNode* ptr1 = header1->link;
    PolyNode* ptr2 = header2->link;
    int coeff=0, exp=0; 

    while (ptr1 != NULL) {
        ptr2 = header2->link;
        while (ptr2 != NULL) {
            coeff = ptr1->coeff * ptr2->coeff; 
            exp = ptr1->exp + ptr2->exp;        
            insertTerm(header3, coeff, exp);  
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }
}

int main() {
    header1 = (PolyNode*) malloc(sizeof(PolyNode));
    header2 = (PolyNode*) malloc(sizeof(PolyNode));
    header3 = (PolyNode*) malloc(sizeof(PolyNode));
    header1->link=NULL;
    header2->link=NULL;
    header3->link=NULL;
    int n, coeff, exp;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient for exponent %d: ", i);
        scanf("%d", &coeff);
        insertTerm(header1, coeff, i);
    }
    
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coefficient for exponent %d: ", i);
        scanf("%d", &coeff);
        insertTerm(header2, coeff, i);
    }

    printf("Polynomial 1: ");
    displayPolynomial(header1);

    printf("Polynomial 2: ");
    displayPolynomial(header2);

    multiplyPolynomials();
 
    printf("Resultant Polynomial: ");
    displayPolynomial(header3);

    return 0;
}
