#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode1 {
    int coeff;             // Coefficient
    int exp;               // Exponent
    struct PolyNode1* link; // Pointer to the link term
}PolyNode;

PolyNode* header1;
PolyNode* header2;
PolyNode* header3;

void insertTerm(PolyNode* header, int coeff, int exp) {
    node* newnode = (node*) malloc(sizeof(node));
    newnode->coeff = coeff;
    newnode->exp = exp;
    newnode->link = NULL;

    node* ptr = header;
    while (ptr->link != NULL && ptr->link->exp > exp) {
        ptr = ptr->link;
    }

    if (ptr->link != NULL && ptr->link->exp == exp) {
        ptr->link->coeff += coeff;
        free(newnode);
    } else {
        newnode->link = ptr->link;
        ptr->link = newnode;
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

void addPolynomials() {
    PolyNode* ptr1 = header1->link;
    PolyNode* ptr2 = header2->link;
    PolyNode* ptr = header3;

    while (ptr1 != NULL || ptr2 != NULL) {
        int coeff = 0;
        int exp;

        if (ptr1 != NULL && (ptr2 == NULL || ptr1->exp > ptr2->exp)) {
            coeff = ptr1->coeff;
            exp = ptr1->exp;
            ptr1 = ptr1->link;
        } else if (ptr2 != NULL && (ptr1 == NULL || ptr2->exp > ptr1->exp)) {
            coeff = ptr2->coeff;
            exp = ptr2->exp;
            ptr2 = ptr2->link;
        } else {
            coeff = ptr1->coeff + ptr2->coeff; 
            exp = ptr1->exp;
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        PolyNode* newNode = (PolyNode*) malloc(sizeof(PolyNode));
        newNode->coeff = coeff;
        newNode->exp = exp;
        newNode->link = NULL;
        ptr->link = newNode;
        ptr = newNode;
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

    addPolynomials();
 
    printf("Resultant Polynomial: ");
    displayPolynomial(header3);

    return 0;
}
