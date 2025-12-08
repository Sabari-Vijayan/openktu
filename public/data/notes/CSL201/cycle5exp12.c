#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode {
    int coeff;         
    int expX;          
    int expY;          
    struct PolyNode* link; 
} PolyNode;

void insertTerm(PolyNode** header, int coeff, int expX, int expY) {
    if (coeff == 0) {
        return; 
    }

    PolyNode* newNode = (PolyNode*) malloc(sizeof(PolyNode));
    newNode->coeff = coeff;
    newNode->expX = expX;
    newNode->expY = expY;
    newNode->link = NULL;

    PolyNode* current = *header;
    PolyNode* previous = NULL;

    while (current != NULL && (current->expX > expX || (current->expX == expX && current->expY > expY))) {
        previous = current;
        current = current->link;
    }

    if (current != NULL && current->expX == expX && current->expY == expY) {
        current->coeff += coeff; 
        free(newNode);           
    } else {
        newNode->link = current; 
        if (previous == NULL) {
            *header = newNode;
        } else {
            previous->link = newNode; 
        }
    }
}

PolyNode* addPolynomials(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* result = NULL;
    PolyNode* ptr1 = poly1;
    PolyNode* ptr2 = poly2;

    while (ptr1 != NULL || ptr2 != NULL) {
        int coeff = 0;
        int expX, expY;

        if (ptr1 != NULL && (ptr2 == NULL || ptr1->expX > ptr2->expX || (ptr1->expX == ptr2->expX && ptr1->expY > ptr2->expY))) {
            coeff = ptr1->coeff;
            expX = ptr1->expX;
            expY = ptr1->expY;
            ptr1 = ptr1->link;
        } else if (ptr2 != NULL && (ptr1 == NULL || ptr2->expX > ptr1->expX || (ptr2->expX == ptr1->expX && ptr2->expY > ptr1->expY))) {
            coeff = ptr2->coeff;
            expX = ptr2->expX;
            expY = ptr2->expY;
            ptr2 = ptr2->link;
        } else {
            coeff = ptr1->coeff + ptr2->coeff;
            expX = ptr1->expX;
            expY = ptr1->expY;
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        insertTerm(&result, coeff, expX, expY);
    }

    return result;
}

void displayPolynomial(PolyNode* poly) {
    PolyNode* current = poly;
    while (current != NULL) {
        if (current->coeff > 0 && current != poly) {
            printf("+ ");
        }
        printf("%dx^%dy^%d ", current->coeff, current->expX, current->expY);
        current = current->link;
    }
    printf("\n");
}

void readPolynomial(PolyNode** header) {
    int n; 
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int coeff, expX, expY;
        printf("Enter coefficient, exponent of x, and exponent of y for term %d: ", i + 1);
        scanf("%d %d %d", &coeff, &expX, &expY);
        insertTerm(header, coeff, expX, expY);
    }
}

int main() {
    PolyNode* poly1 = NULL;
    PolyNode* poly2 = NULL;

    printf("Enter the first polynomial:\n");
    readPolynomial(&poly1);
    
    printf("Enter the second polynomial:\n");
    readPolynomial(&poly2);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    PolyNode* result = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial: ");
    displayPolynomial(result);
    return 0;
}

