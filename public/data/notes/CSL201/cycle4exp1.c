#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct {
    int coefficient;
    int exponent;
} Term;

void readPolynomial(Term poly[], int *numTerms) {
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", numTerms);
    for (int i = 0; i < *numTerms; i++) {
        printf("Enter coefficient and exponent of term %d: ", i + 1);
        scanf("%d %d", &poly[i].coefficient, &poly[i].exponent);
    }
}

void displayPolynomial(Term poly[], int numTerms) {
    for (int i = 0; i < numTerms; i++) {
        if (i != 0 && poly[i].coefficient > 0) {
            printf(" + ");
        }
        if (poly[i].exponent == 0) {
            printf("%d", poly[i].coefficient);
        } else if (poly[i].exponent == 1) {
            printf("%dx", poly[i].coefficient);
        } else {
            printf("%dx^%d", poly[i].coefficient, poly[i].exponent);
        }
    }
    printf("\n");
}

void addPolynomials(Term poly1[], int numTerms1, Term poly2[], int numTerms2, Term result[], int *numTermsResult) {
    int index1 = 0, index2 = 0, indexResult = 0;

    while (index1 < numTerms1 && index2 < numTerms2) {
        if (poly1[index1].exponent > poly2[index2].exponent) {
            result[indexResult++] = poly1[index1++];
        } else if (poly1[index1].exponent < poly2[index2].exponent) {
            result[indexResult++] = poly2[index2++];
        } else {
            result[indexResult].exponent = poly1[index1].exponent;
            result[indexResult].coefficient = poly1[index1].coefficient + poly2[index2].coefficient;
            indexResult++;
            index1++;
            index2++;
        }
    }
    while (index1 < numTerms1) {
        result[indexResult++] = poly1[index1++];
    }
    while (index2 < numTerms2) {
        result[indexResult++] = poly2[index2++];
    }
    *numTermsResult = indexResult;
}

int main() {
    int numTerms1, numTerms2, numTermsResult;
    Term poly1[MAX_TERMS], poly2[MAX_TERMS], result[MAX_TERMS];

    printf("Polynomial 1:\n");
    readPolynomial(poly1, &numTerms1);

    printf("Polynomial 2:\n");
    readPolynomial(poly2, &numTerms2);

    addPolynomials(poly1, numTerms1, poly2, numTerms2, result, &numTermsResult);

    printf("Polynomial 1: ");
    displayPolynomial(poly1, numTerms1);

    printf("Polynomial 2: ");
    displayPolynomial(poly2, numTerms2);

    printf("Sum of Polynomials: ");
    displayPolynomial(result, numTermsResult);

    return 0;
}
